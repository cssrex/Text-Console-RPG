#include "GreenSlime.h"
#include <iostream>

void GreenSlime::PrintAsciiArt(short startX, short startY) {
	PrintNormalSlimeAsciiArt(startX, startY);
}

void GreenSlime::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void GreenSlime::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}