#include "GreenSlime.h"
#include <iostream>



// 기본 공격
void GreenSlime::BasicAttack(Player* player) {
	player->TakeDamage(attack_);
}

// 특수 공격
void GreenSlime::SpecialAttack(Player* player) {
	player->TakeDamage(attack_ * 2);
}

