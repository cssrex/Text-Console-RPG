#include "Dungeon.h"
#include "GameManager.h"
#include "LogManager.h"
#include "Player.h"

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

Dungeon::Dungeon() {
	// 슬라임 던전
	Room* slimeRoom = new Room{ "슬라임 던전", 3 };

	Monster* greenSlime = new GreenSlime;
	Monster* hornSlime = new HornSlime;
	Monster* poisonSlime = new PoisonSlime;
	slimeRoom->monsters_.push_back(greenSlime);
	slimeRoom->monsters_.push_back(hornSlime);
	slimeRoom->monsters_.push_back(poisonSlime);

	slimeRoom->boss_ = new KingSlime;

	// 고블린 던전
	Room* goblinRoom = new Room{ "고블린 던전", 3 };

	Monster* goblinWarrior = new GoblinWarrior;
	Monster* goblinArcher = new GoblinArcher;
	goblinRoom->monsters_.push_back(goblinWarrior);
	goblinRoom->monsters_.push_back(goblinArcher);

	goblinRoom->boss_ = new GoblinSorcerer;

	// 오크 던전
	Room* orcRoom = new Room{ "오크 던전", 3 };

	Monster* orcWarrior = new OwkWarrior;
	Monster* orcSorcerer = new OwkSorcerer;
	orcRoom->monsters_.push_back(orcWarrior);
	orcRoom->monsters_.push_back(orcSorcerer);

	orcRoom->boss_ = new OwkChief;

	// 드래곤 던전
	Room* dragonRoom = new Room{ "드래곤 던전", 3 };

	Monster* wyvern = new Wyvern;
	Monster* drake = new Drake;
	dragonRoom->monsters_.push_back(wyvern);
	dragonRoom->monsters_.push_back(drake);

	dragonRoom->boss_ = new TransparentDragon;

	rooms_.push_back(slimeRoom);
	rooms_.push_back(goblinRoom);
	rooms_.push_back(orcRoom);
	rooms_.push_back(dragonRoom);
}

Dungeon::~Dungeon() {
	for (Room* room : rooms_)
	{
		for (Monster* monster : room->monsters_)
		{
			delete monster;
		}
		delete room->boss_;
		delete room;
	}
}

Dungeon& Dungeon::GetInstance() {
	static Dungeon instance;
	return instance;
}

void Dungeon::StartDungeonLoop(Player* player) {
	while (true)
	{
		PrintDungeonList();

		int command;
		std::cin >> command;

		switch (command)
		{
		case 0:
			GameManager::GetInstance().SetNextScene(Scene::MAIN);
			return;
		case 1:
			Enter(player, 1);
			GameManager::GetInstance().SetNextScene(Scene::MAIN);
			return;
		case 2:
			Enter(player, 2);
			GameManager::GetInstance().SetNextScene(Scene::MAIN);
			return;
		case 3:
			Enter(player, 3);
			GameManager::GetInstance().SetNextScene(Scene::MAIN);
			return;
		case 4:
			if (topCanEnter >= rooms_.size() - 1)
			{
				Enter(player, 4);
				GameManager::GetInstance().SetNextScene(Scene::MAIN);
				return;
			}
			else
			{
				LogManager::GetInstance().PrintInpuErrorMessage();
				break;
			}
		default:	
			LogManager::GetInstance().PrintInpuErrorMessage();
			break;
		}

	}
}

void Dungeon::Enter(Player* player, int roomIndex) {
	while (true)
	{
		LogManager::GetInstance().PrintDungeonBattleMainMenu(rooms_[0], 1, rooms_[0]->monsters_[0]);

		int command;
		std::cin >> command;

		switch (command)
		{
		case 0:
			GameManager::GetInstance().SetNextScene(Scene::MAIN);
			return;
		case 1:
			Enter(player, 1);
			GameManager::GetInstance().SetNextScene(Scene::MAIN);
			return;
		case 2:
			Enter(player, 2);
			GameManager::GetInstance().SetNextScene(Scene::MAIN);
			return;
		case 3:
			Enter(player, 3);
			GameManager::GetInstance().SetNextScene(Scene::MAIN);
			return;
		case 4:
			if (topCanEnter >= rooms_.size() - 1)
			{
				Enter(player, 4);
				GameManager::GetInstance().SetNextScene(Scene::MAIN);
				return;
			}
			else
			{
				LogManager::GetInstance().PrintInpuErrorMessage();
				break;
			}
		default:
			LogManager::GetInstance().PrintInpuErrorMessage();
			break;
		}

	}
	




	return;
}

void Dungeon::PrintDungeonList() {
	std::vector<std::string> roomList;
	for (int i = 0; i < rooms_.size(); i++)
	{
		if((i == rooms_.size() - 1) && (topCanEnter != rooms_.size() - 1)) continue;

		Room* room = rooms_[i];

		std::string s = room->name_;
		if (i > topCanEnter) s += " (입장 불가능)";

		roomList.push_back(s);
	}

	LogManager::GetInstance().PrintDungeonList(roomList);

}

Monster* Dungeon::CreateMonster(int level) {
	return nullptr;
}

void Dungeon::Battle(Player* player, Monster& monster) {
}

void Dungeon::GiveReward(Player* player, Monster& monster) {
	// player.AddExp();
}

