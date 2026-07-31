#include "OwkWarrior.h"
#include <iostream>

// 기본 공격
void OwkWarrior::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void OwkWarrior::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}
