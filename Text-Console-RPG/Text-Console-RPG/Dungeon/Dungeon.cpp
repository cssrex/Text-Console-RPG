#include "Dungeon.h"
#include "LogManager.h"
#include "Player.h"

Dungeon::Dungeon() {

}

Dungeon::~Dungeon() {
}

Dungeon& Dungeon::GetInstance() {
	static Dungeon instance;
	return instance;
}

void Dungeon::Enter(Player& player, int roomIndex) {
}

Monster* Dungeon::CreateMonster(int level) {
	return nullptr;
}

void Dungeon::Battle(Player& player, Monster& monster) {
}

void Dungeon::GiveReward(Player& player, Monster& monster) {
	// player.AddExp();
}

