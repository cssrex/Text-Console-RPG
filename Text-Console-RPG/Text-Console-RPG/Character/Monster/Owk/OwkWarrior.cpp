#include "OwkWarrior.h"
#include <iostream>

void OwkWarrior::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void OwkWarrior::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}