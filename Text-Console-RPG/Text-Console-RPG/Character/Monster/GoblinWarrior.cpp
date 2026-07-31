#include "GoblinWarrior.h"
#include <iostream>

// 기본 공격
void GoblinWarrior::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void GoblinWarrior::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}
