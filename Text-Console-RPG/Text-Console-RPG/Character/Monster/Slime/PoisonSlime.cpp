#include "PoisonSlime.h"
#include <iostream>

void PoisonSlime::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void PoisonSlime::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}