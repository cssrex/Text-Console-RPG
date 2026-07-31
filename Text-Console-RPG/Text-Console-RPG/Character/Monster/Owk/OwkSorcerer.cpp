#include "OwkSorcerer.h"
#include <iostream>

void OwkSorcerer::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void OwkSorcerer::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}