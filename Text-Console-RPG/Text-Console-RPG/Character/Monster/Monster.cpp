#include "Monster.h"
#include <iostream>

// 피격 및 사망 로직
void Monster::TakeDamage(int damage){

	Character::TakeDamage(damage);
	if (IsDead()){

		// 로그 처리
	}
}

void Monster::SpecialAttack(Character& target)
{

}


void Monster::TakeTurn(Character& target)
{
	Attack(target);
}