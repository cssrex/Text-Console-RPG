#include "GoblinSorcerer.h"
#include <iostream>

void GoblinSorcerer::PrintAsciiArt(short startX, short startY) {
	PrintBossGoblinAsciiArt(startX, startY);
}
void GoblinSorcerer::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void GoblinSorcerer::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}

void GoblinSorcerer::HyperAttack(Player* player) {
	player->TakeDamage(GetAttack() * 3);
}