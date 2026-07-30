#include "KingSlime.h"
#include <iostream>

// 일반 공격
void KingSlime::Attack(Character& target){
	target.TakeDamage(attack_);
}
// 특수 공격
void KingSlime::SpecialAttack(Character& target) {
	target.TakeDamage(attack_);
}

// 특수 공격이 발동될 로직
void KingSlime::TakeTurn(Character& target) {
	turnCount_++;

	if (turnCount_ % 3 == 0)
	{
		SpecialAttack(target);
	}
	else
	{
		Attack(target);
	}
}
