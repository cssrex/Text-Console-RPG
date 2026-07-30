#include "Wyvern.h"
#include <iostream>

// 기본 공격
void Wyvern::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void Wyvern::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}