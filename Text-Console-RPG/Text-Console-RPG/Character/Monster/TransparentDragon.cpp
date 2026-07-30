#include "TransparentDragon.h"
#include <iostream>

void TransparentDragon::Attack(Character& target){
	target.TakeDamage(attack_);
}

// 특수 공격
void TransparentDragon::SpecialAttack(Character& target) {
	target.TakeDamage(attack_);
}

// 특수 공격이 발동될 로직
void TransparentDragon::TakeTurn(Character& target) {
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