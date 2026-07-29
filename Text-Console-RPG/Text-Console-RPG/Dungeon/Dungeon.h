#include <map>
#include <vector>

class Player;
class Monster;

struct Room
{
	int floor;
	std::vector<Monster*> monster;
};

class Dungeon
{
private:
	static std::map<Monster, int> killedMonsterList;

private:
	Dungeon();
	Dungeon(const Dungeon&) = delete;
	Dungeon& operator=(const Dungeon&) = delete;
	~Dungeon();

public:
	static Dungeon& GetInstance();
	void Enter(Player& player);

private:
	Monster* CreateMonster(int level);
	void Battle(Player& player, Monster& monster);
	void GiveReward(Player& player);
};