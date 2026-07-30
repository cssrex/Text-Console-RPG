#include "KingSlime.h"
#include <iostream>



// 기본 공격
void KingSlime::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void KingSlime::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}

// 궁극기
void KingSlime::HyperAttack(Player* player) {
	player->TakeDamage(attack_ * 3);
}