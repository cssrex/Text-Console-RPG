#include "GoblinArcher.h"
#include <iostream>

// 기본 공격
void GoblinArcher::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void GoblinArcher::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}
