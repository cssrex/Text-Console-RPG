#include "TransparentDragon.h"
#include <iostream>

// 기본 공격
void TransparentDragon::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void TransparentDragon::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}


// 궁극기 공격
void TransparentDragon::HyperAttack(Player* player) {
	player->TakeDamage(attack_ * 3);
}