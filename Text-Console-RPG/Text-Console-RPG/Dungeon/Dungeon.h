#pragma once
#include <map>
#include <vector>
#include <string>

class Player;
class Monster;

struct Room {
	std::string name_;
	int floor_;
	std::vector<Monster*> monsters_;
	Monster* boss_;
};

class Dungeon {
private:
	std::map<Monster*, int> killedMonsterList_;
	std::vector<Room*> rooms_;
	int topCanEnter = 0;
	
private:
	Dungeon();
	Dungeon(const Dungeon&) = delete;
	Dungeon& operator=(const Dungeon&) = delete;
	~Dungeon();

public:
	static Dungeon& GetInstance();
	void StartDungeonLoop(Player* player);
	void Enter(Player* player, int roomIndex);
	void PrintDungeonList();

private:
	Monster* CreateMonster(int level);
	void Battle(Player* player, Monster& monster);
	void GiveReward(Player* player, Monster& monster);
};