#include "TransparentDragon.h"
#include <iostream>

void TransparentDragon::BasicAttack(Player* player) {
	player->TakeDamage(GetAttack());
}

void TransparentDragon::SpecialAttack(Player* player) {
	player->TakeDamage(GetAttack() * 2);
}

void TransparentDragon::HyperAttack(Player* player) {
	player->TakeDamage(GetAttack() * 3);
}