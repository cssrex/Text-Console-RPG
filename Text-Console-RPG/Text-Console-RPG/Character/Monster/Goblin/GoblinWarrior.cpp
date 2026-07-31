#include "GoblinWarrior.h"
#include <iostream>

void GoblinWarrior::PrintAsciiArt(short startX, short startY) {
	PrintNormalGoblinAsciiArt(startX, startY);
}

void GoblinWarrior::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void GoblinWarrior::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}