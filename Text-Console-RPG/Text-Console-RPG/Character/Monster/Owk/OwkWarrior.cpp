#include "OwkWarrior.h"
#include <iostream>

void OwkWarrior::PrintAsciiArt(short startX, short startY) {
	PrintNormalOrcAsciiArt(startX, startY);
}
void OwkWarrior::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void OwkWarrior::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}