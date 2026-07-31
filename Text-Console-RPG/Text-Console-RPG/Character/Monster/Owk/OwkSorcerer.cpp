#include "OwkSorcerer.h"
#include <iostream>

void OwkSorcerer::PrintAsciiArt(short startX, short startY) {
	PrintNormalOrcAsciiArt(startX, startY);
}
void OwkSorcerer::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void OwkSorcerer::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}