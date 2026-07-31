#include "Wyvern.h"
#include <iostream>

void Wyvern::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void Wyvern::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}