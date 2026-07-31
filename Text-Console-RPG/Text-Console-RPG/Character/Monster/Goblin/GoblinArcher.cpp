#include "GoblinArcher.h"
#include <iostream>

void GoblinArcher::PrintAsciiArt(short startX, short startY) {
	PrintNormalGoblinAsciiArt(startX, startY);
}
void GoblinArcher::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void GoblinArcher::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}