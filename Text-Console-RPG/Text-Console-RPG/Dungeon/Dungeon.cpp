#include "Dungeon.h"
#include "GameManager.h"
#include "LogManager.h"
#include "Player.h"
#include "Inventory.h"
#include "Item.h"

#include "SkillManager.h"

#include "GreenSlime.h"
#include "HornSlime.h"
#include "PoisonSlime.h"
#include "KingSlime.h"

#include "GoblinWarrior.h"
#include "GoblinArcher.h"
#include "GoblinSorcerer.h"

#include "OwkWarrior.h"
#include "OwkSorcerer.h"
#include "OwkChief.h"

#include "Wyvern.h"
#include "Drake.h"
#include "TransparentDragon.h"

#include <vector>
#include <iostream>
#include <random>

Dungeon::Dungeon() {
	// 슬라임 던전
	Room* slimeRoom = new Room{ "슬라임 던전", 3 };

	slimeRoom->monsterFactories_.push_back([]() { return new GreenSlime(); });
	slimeRoom->monsterFactories_.push_back([]() { return new HornSlime(); });
	slimeRoom->monsterFactories_.push_back([]() { return new PoisonSlime(); });

	slimeRoom->bossFactory_ = []() { return new KingSlime(); };

	// 고블린 던전
	Room* goblinRoom = new Room{ "고블린 던전", 3 };

	goblinRoom->monsterFactories_.push_back([]() { return new GoblinWarrior(); });
	goblinRoom->monsterFactories_.push_back([]() { return new GoblinArcher(); });

	goblinRoom->bossFactory_ = []() { return new GoblinSorcerer(); };

	// 오크 던전
	Room* orcRoom = new Room{ "오크 던전", 3 };

	orcRoom->monsterFactories_.push_back([]() { return new OwkWarrior(); });
	orcRoom->monsterFactories_.push_back([]() { return new OwkSorcerer(); });

	orcRoom->bossFactory_ = []() { return new OwkChief(); };

	// 드래곤 던전
	Room* dragonRoom = new Room{ "드래곤 던전", 3 };

	dragonRoom->monsterFactories_.push_back([]() { return new TransparentDragon(); });
	dragonRoom->monsterFactories_.push_back([]() { return new TransparentDragon(); });

	dragonRoom->bossFactory_ = []() { return new TransparentDragon(); };

	rooms_.push_back(slimeRoom);
	rooms_.push_back(goblinRoom);
	rooms_.push_back(orcRoom);
	rooms_.push_back(dragonRoom);
}

Dungeon::~Dungeon() {
	for (Room* room : rooms_)
	{
		delete room;
	}
}

void Dungeon::StartDungeonLoop(Player* player) {
	while (true)
	{
		PrintDungeonList();

		int command;
		std::cin >> command;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			LogManager::GetInstance().PrintInpuErrorMessage();
			system("pause");
			continue;
		}

		switch (command)
		{
		case 0:
			GameManager::GetInstance().SetNextScene(Scene::MAIN);
			return;
		case 1:
			Enter(player, 0);
			return;
		case 2:
			if (topCanEnter >= 1)
			{
				Enter(player, 1);
				return;
			}
			else LogManager::GetInstance().PrintInpuErrorMessage();
			break;
		case 3:
			if (topCanEnter >= 2)
			{
				Enter(player, 2);
				return;
			}
			else LogManager::GetInstance().PrintInpuErrorMessage();
			break;
		case 4:
			if (topCanEnter >= 3)
			{
				Enter(player, 3);
				return;
			}
			else LogManager::GetInstance().PrintInpuErrorMessage();
			break;
		default:
			LogManager::GetInstance().PrintInpuErrorMessage();
			break;
		}

		if (player->IsDead()) {
			return;
		}
	}
}

Monster* Dungeon::CreateMonster(int roomIndex, int level) {
	static std::random_device rd;
	static std::mt19937 gen(rd());

	auto& factories = rooms_[roomIndex]->monsterFactories_;
	std::uniform_int_distribution<int> dis(0, factories.size() - 1);

	return factories[dis(gen)]();
}

void Dungeon::Enter(Player* player, int roomIndex) {
	int floor = 1;
	int command;

	while (true)
	{
		Room* currentRoom = rooms_[roomIndex];
		Monster* monster = nullptr;

		if (floor >= currentRoom->floor_) {
			monster = currentRoom->bossFactory_();
		}
		else {
			monster = CreateMonster(roomIndex, 1);
		}

		string rewardItem = monster->GetDropItem();
		int rewardGold = monster->GetDropGold();
		int rewardExp = monster->GetRewardExp();

		bool isWon = Battle(player, monster, roomIndex, floor);

		delete monster;

		// 패배한 경우 : 이전 메뉴로
		if (!isWon) return;

		// 보스층 클리어한 경우
		if (floor >= rooms_[roomIndex]->floor_) {
			// 축하 메시지

			if (topCanEnter == roomIndex && topCanEnter < (rooms_.size()) - 1) {
				topCanEnter++;
			}
			system("pause");
			return;
		}

		while (true)
		{
			LogManager::GetInstance().PrintDungeonProgressOption(rooms_[roomIndex], floor, rewardItem, rewardGold, rewardExp);
			bool isRightCommand = true;
			cin >> command;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				LogManager::GetInstance().PrintInpuErrorMessage();
				continue;
			}

			if (command == 0) {
				GameManager::GetInstance().SetNextScene(Scene::MAIN);
				return; // 던전 떠나기
			}
			if (command == 1) {       // 다음 층으로
				floor++;
				break;
			}
			LogManager::GetInstance().PrintInpuErrorMessage();
		}

	}

	return;
}

bool Dungeon::Battle(Player* player, Monster* monster, int roomIndex, int floor) {

	bool playerWon = false;

	while (true)
	{
		// 플레이어 턴 시작 시 상태이상 업데이트
		player->UpdateStatusEffects();

		if (player->IsDead()) {
			GameManager::GetInstance().SetNextScene(Scene::END);
			playerWon = false;
			break;
		}

		// 행동 완료 여부 플래그 (MP 부족/취소 시 루프 재실행용)
		bool validTurn = false;
		

		while (!validTurn)
		{
			LogManager::GetInstance().PrintDungeonBattleMainMenu(rooms_[roomIndex], floor, player, monster);

			// 플레이어가 몬스터 때리기
			int command;
			std::cin >> command;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				LogManager::GetInstance().PrintInpuErrorMessage();
				system("pause > nul");
				continue;
			}

			switch (command)
			{
			case 1:
				monster->TakeDamage(player->GetAttack());
				validTurn = true; // 일반 공격 성공 시 턴 소모
				break;
			case 2:
				// SkillManager를 통한 플레이어 스킬 사용
				validTurn = SkillManager::GetInstance().ProcessSkillSelection(*player, *monster);
				system("pause > nul");
				break;
			case 3:
				player->GetInventory()->InventoryMenu(*player);
				system("pause > nul");
				break;
			case 4:
				break;
			default:
				LogManager::GetInstance().PrintInpuErrorMessage();
				break;
			}
		}

		system("pause > nul");

		if (monster->IsDead())
		{
			// TODO : 승리 메시지 띄우고 잠깐 기다렸다가 끝내기
			cout << monster->GetName() << "을(를) 무찔렀다!\n";
			system("pause > nul");
			//
			
			GiveReward(player, monster);
			playerWon = true;
			break;
		}

		// 몬스터 턴 시작 시 상태이상 업데이트
		monster->UpdateStatusEffects();

		// 몬스터가 플레이어 때리기
		monster->Attack(player);
		
		system("pause > nul");

		if (player->IsDead())
		{
			GameManager::GetInstance().SetNextScene(Scene::END);
			playerWon = false;
			break;
		}
	}

	return playerWon;
}

void Dungeon::PrintDungeonList() {
	std::vector<std::string> roomList;
	for (int i = 0; i < rooms_.size(); i++)
	{
		if ((i == rooms_.size() - 1) && (topCanEnter != rooms_.size() - 1)) continue;

		Room* room = rooms_[i];

		std::string s = room->name_;
		if (i > topCanEnter) s += " (입장 불가능)";

		roomList.push_back(s);
	}

	LogManager::GetInstance().PrintDungeonList(roomList);

}


void Dungeon::GiveReward(Player* player, Monster* monster) {
	player->GetInventory()->AddItem(make_unique<LootItem>(monster->GetDropItem(), monster->GetSellPrice(), 1));
	player->AddGold(monster->GetDropGold());
	player->AddExp(monster->GetRewardExp());


	LogManager::GetInstance().PrintDungeonReward(monster->GetDropItem(), monster->GetDropGold(), monster->GetRewardExp());
}