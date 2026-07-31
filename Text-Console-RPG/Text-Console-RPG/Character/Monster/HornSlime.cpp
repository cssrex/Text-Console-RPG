#include "HornSlime.h"
#include <iostream>


// 기본 공격
void HornSlime::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void HornSlime::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}