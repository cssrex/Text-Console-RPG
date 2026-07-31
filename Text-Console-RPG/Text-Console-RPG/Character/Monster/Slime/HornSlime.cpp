#include "HornSlime.h"
#include <iostream>

void HornSlime::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void HornSlime::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}