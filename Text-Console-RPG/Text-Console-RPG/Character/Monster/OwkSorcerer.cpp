#include "OwkSorcerer.h"
#include <iostream>

// 기본 공격
void OwkSorcerer::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void OwkSorcerer::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}