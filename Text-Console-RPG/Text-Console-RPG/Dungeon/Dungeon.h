#pragma once
#include <map>
#include <vector>
#include <string>
#include <functional>

class Player;
class Monster;

struct Room {
	std::string name_;
	int floor_;
	std::vector<std::function<Monster*()>> monsterFactories_;
	std::function<Monster* ()> bossFactory_;
};

class Dungeon {
private:
	std::map<std::string, int> killedMonsterList_;
	std::vector<Room*> rooms_;
	int topCanEnter = 0;
	
public:
	Dungeon();
	~Dungeon();

public:
	bool StartDungeonLoop(Player* player);
	void PrintKilledMonsterList();

private:
	Monster* CreateMonster(int roomIndex, int level);
	bool Enter(Player* player, int roomIndex);
	bool Battle(Player* player, Monster* monster, int roomIndex, int floor);
	void GiveReward(Player* player, Monster* monster);

	void PrintDungeonList();
};