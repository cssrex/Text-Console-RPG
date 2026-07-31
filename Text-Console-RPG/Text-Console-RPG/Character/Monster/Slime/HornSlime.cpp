#include "HornSlime.h"
#include <iostream>

void HornSlime::PrintAsciiArt(short startX, short startY) {
	PrintNormalSlimeAsciiArt(startX, startY);
}
void HornSlime::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void HornSlime::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}