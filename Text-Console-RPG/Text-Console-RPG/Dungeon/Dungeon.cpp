#include "Dungeon.h"
#include "GameManager.h"
#include "LogManager.h"
#include "GameSound.h"

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

	dragonRoom->monsterFactories_.push_back([]() { return new Drake(); });
	dragonRoom->monsterFactories_.push_back([]() { return new Wyvern(); });

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

bool Dungeon::StartDungeonLoop(Player* player) {
	GameSound::PlayDungeonBgmLoop();

	while (true)
	{
		PrintDungeonList();

		int command;
		std::cin >> command;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			LogManager::GetInstance().PrintInpuErrorMessage();
			system("pause > nul");
			continue;
		}

		bool isRightCommand = true;
		
		switch (command)
		{
		case 0:
			GameManager::GetInstance().SetNextScene(Scene::MAIN);
			return false;
		case 1:
			Enter(player, 0);
			break;
		case 2:
			if (topCanEnter >= 1)
			{
				Enter(player, 1);
				break;
			}
			else
			{
				LogManager::GetInstance().PrintInpuErrorMessage();
				isRightCommand = false;
			}
			break;
		case 3:
			if (topCanEnter >= 2)
			{
				Enter(player, 2);
				break;
			}
			else
			{
				LogManager::GetInstance().PrintInpuErrorMessage();
				isRightCommand = false;
			}
			break;
		case 4:
			if (topCanEnter >= 3)
			{
				Enter(player, 3);
				break;
			}
			else
			{
				LogManager::GetInstance().PrintInpuErrorMessage();
				isRightCommand = false;
			}
			break;
		default:
			LogManager::GetInstance().PrintInpuErrorMessage();
			isRightCommand = false;
			break;
		}

		if (!isRightCommand)
		{
			continue;
		}

		if (player->IsDead()) {
			GameManager::GetInstance().SetNextScene(Scene::HOTEL);

			return true;
		}

		break;
	}

	if (isClear)
	{
		GameManager::GetInstance().SetNextScene(Scene::END);
	}
	else if (GameManager::GetInstance().GetDay() <= 0)
	{
		GameManager::GetInstance().SetNextScene(Scene::END);
	}
	else
	{
		GameManager::GetInstance().SetNextScene(Scene::MAIN);
	}

	return true;
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
			GameSound::PlayBattleBgmLoop();
		}
		else {
			monster = CreateMonster(roomIndex, 1);
			GameSound::PlayBossBattleBgmLoop();
		}

		string name = monster->GetName();
		string rewardItem = monster->GetDropItem();
		int rewardGold = monster->GetDropGold();
		int rewardExp = monster->GetRewardExp();

		bool isWon = Battle(player, monster, roomIndex, floor);

		delete monster;

		// 패배한 경우 : 이전 메뉴로
		if (!isWon)
		{
			return;
		}

		killedMonsterList_[name]++;

		// 보스층 클리어한 경우
		if (floor >= rooms_[roomIndex]->floor_) {
			GameSound::StopBgm();
			GameSound::StopWave();
			GameSound::PlayDungeonClearSfx();
			
			// 축하 메시지
			if (name == "투명 드래곤")
			{
				isClear = true;
				return;
			}

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
				player->GetInventory()->BattleConsumableMenu(*player);
				system("pause > nul");
				break;
			/* 용병 삭제됨
			case 4:
				break;*/
			default:
				LogManager::GetInstance().PrintInpuErrorMessage();
				break;
			}
		}

		system("pause > nul");

		if (monster->IsDead())
		{
			cout << monster->GetName() << "을(를) 무찔렀다!\n";
			system("pause > nul");
			
			GiveReward(player, monster);
			playerWon = true;
			break;
		}

		LogManager::GetInstance().PrintDungeonBattleMonsterTurn(rooms_[roomIndex], floor, player, monster);

		player->UpdateStatusEffects();

		if (player->IsDead())
		{
			GameSound::StopBgm();
			// GameSound::PlayPlayerDeathSfx();
			player->LevelDown();
			LogManager::GetInstance().PrintDungeonPlayerDeath();
			playerWon = false;
			break;
		}

		// 몬스터가 플레이어 때리기
		monster->Attack(player);
		
		system("pause > nul");

		if (player->IsDead())
		{
			GameSound::StopBgm();
			// GameSound::PlayPlayerDeathSfx();
			player->LevelDown();
			LogManager::GetInstance().PrintDungeonPlayerDeath();
			playerWon = false;
			break;
		}

		// 몬스터 턴 시작 시 상태이상 업데이트
		monster->UpdateStatusEffects();

		if (monster->IsDead())
		{
			cout << monster->GetName() << "을(를) 무찔렀다!\n";
			system("pause > nul");

			GiveReward(player, monster);
			playerWon = true;
			break;
		}
	}

	return playerWon;
}

void Dungeon::PrintDungeonList() const {
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

void Dungeon::PrintKilledMonsterList() const {
	LogManager::GetInstance().PrintDungeonKillList(killedMonsterList_);
}


void Dungeon::GiveReward(Player* player, Monster* monster) {
	player->GetInventory()->AddItem(make_unique<LootItem>(monster->GetDropItem(), monster->GetSellPrice(), 1));
	player->AddGold(monster->GetDropGold());
	player->AddExp(monster->GetRewardExp());


	LogManager::GetInstance().PrintDungeonReward(monster->GetDropItem(), monster->GetDropGold(), monster->GetRewardExp());
}