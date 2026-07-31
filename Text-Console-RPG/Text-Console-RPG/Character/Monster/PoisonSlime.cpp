#include "PoisonSlime.h"
#include <iostream>

// 기본 공격
void PoisonSlime::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void PoisonSlime::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}
