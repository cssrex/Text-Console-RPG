#include "PoisonSlime.h"
#include <iostream>

void PoisonSlime::PrintAsciiArt(short startX, short startY) {
	PrintNormalSlimeAsciiArt(startX, startY);
}
void PoisonSlime::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void PoisonSlime::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}