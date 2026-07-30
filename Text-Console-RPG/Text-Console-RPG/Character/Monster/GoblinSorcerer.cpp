#include "GoblinSorcerer.h"
#include <iostream>

// 기본 공격
void GoblinSorcerer::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void GoblinSorcerer::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}

// 궁극기 공격
void GoblinSorcerer::HyperAttack(Player* player) {
	player->TakeDamage(attack_ * 3);
}