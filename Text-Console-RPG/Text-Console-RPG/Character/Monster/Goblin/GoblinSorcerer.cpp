#include "GoblinSorcerer.h"
#include <iostream>

void GoblinSorcerer::Attack(Character& target){
	target.TakeDamage(attack_);
}
// 특수 공격
void GoblinSorcerer::SpecialAttack(Character& target) {
	target.TakeDamage(attack_);
}

// 특수 공격이 발동될 로직
void GoblinSorcerer::TakeTurn(Character& target) {
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