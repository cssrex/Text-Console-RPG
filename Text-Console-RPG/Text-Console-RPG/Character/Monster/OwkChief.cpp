#include "OwkChief.h"
#include <iostream>

// 기본 공격
void OwkChief::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}
// 특수 공격
void OwkChief::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}

// 궁극기 공격
void OwkChief::HyperAttack(Player* player) {
	player->TakeDamage(attack_ * 3);
}