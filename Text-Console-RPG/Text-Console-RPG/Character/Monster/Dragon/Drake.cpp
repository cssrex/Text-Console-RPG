#include "Drake.h"
#include <iostream>

void Drake::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void Drake::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}