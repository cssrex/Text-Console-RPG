#include "GoblinArcher.h"
#include <iostream>

void GoblinArcher::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void GoblinArcher::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}