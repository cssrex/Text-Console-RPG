#include "Wyvern.h"
#include <iostream>

void Wyvern::PrintAsciiArt(short startX, short startY) {
	PrintNormalDragonAsciiArt(startX, startY);
}
void Wyvern::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void Wyvern::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}