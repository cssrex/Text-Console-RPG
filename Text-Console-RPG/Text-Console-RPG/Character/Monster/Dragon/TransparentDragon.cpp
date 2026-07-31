#include "TransparentDragon.h"
#include <iostream>

void TransparentDragon::PrintAsciiArt(short startX, short startY) {
	PrintBossDragonAsciiArt(startX, startY);
}
void TransparentDragon::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void TransparentDragon::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}

void TransparentDragon::HyperAttack(Player* player) {
	player->TakeDamage(GetAttack() * 3);
}