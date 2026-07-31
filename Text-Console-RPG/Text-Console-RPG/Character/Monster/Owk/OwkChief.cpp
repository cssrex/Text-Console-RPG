#include "OwkChief.h"
#include <iostream>

void OwkChief::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void OwkChief::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}

void OwkChief::HyperAttack(Player* player) {
	player->TakeDamage(GetAttack() * 3);
}