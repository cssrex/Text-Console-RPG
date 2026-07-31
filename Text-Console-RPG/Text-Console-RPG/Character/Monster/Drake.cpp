#include "Drake.h"
#include <iostream>


// 기본 공격
void Drake::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void Drake::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}
