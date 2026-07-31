#include "Monster.h"
#include <iostream>
// 피격 및 사망 로직
void Monster::TakeDamage(int damage){
	Character::TakeDamage(damage);
	if (IsDead()){
		if (RollDropChance())
		{
			// 아이템 획득
		}
		// 로그 처리
	}
}
// 특수 스킬 사용 기준
bool Monster::SpecialAttackTurn() const{
	return (turnCount_ % 2 == 0);
}
// 궁극기 스킬 사용 기준
bool Monster::HyperAttackTurn() const{
	return (GetHp() <= GetMaxHp() * 0.3f);
}

void Monster::Attack(Player* player) {
	turnCount_++;
	if (HyperAttackTurn())
	{
		HyperAttack(player);
	}
	else if (SpecialAttackTurn())
	{
		SpecialAttack(player);
	}
	else
	{
		BasicAttack(player);
	}
}
void Monster::Reward(Player* player) {
}
