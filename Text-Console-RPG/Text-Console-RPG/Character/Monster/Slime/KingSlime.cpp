#include "KingSlime.h"
#include <iostream>

void KingSlime::PrintAsciiArt(short startX, short startY) {
	PrintBossSlimeAsciiArt(startX, startY);
}
void KingSlime::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void KingSlime::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}

void KingSlime::HyperAttack(Player* player) {
	player->TakeDamage(GetAttack() * 3);
}