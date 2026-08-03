#include "Monster.h"
#include "GameManager.h"
#include <iostream>
#include "LogManager.h"

// 피격 및 사망 로직
void Monster::TakeDamage(int damage){
	Character::TakeDamage(damage);

	LogManager::GetInstance().PrintMonsterHitEffect(damage);
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
		GameSound::PlayMonsterHitSfx();
		HyperAttack(player);
	}
	else if (SpecialAttackTurn())
	{
		GameSound::PlayMonsterHitSfx();
		SpecialAttack(player);
	}
	else
	{
		GameSound::PlayMonsterHitSfx();
		BasicAttack(player);
	}
}


// 몬스터 공격력 업
int Monster::CalculatePowerUpAttack() const{
	int currentDay_ = 28 - GameManager::GetInstance().GetDay();
	double powerUpAttack_ = GetAttack() + (GetAttack() * currentDay_ * 0.1); // 계산은  double형으로
	return static_cast<int>(powerUpAttack_); // 반환은 int형으로
}

// 몬스터 체력 업
int Monster::CalculatePowerUpHp() const {
	int currentDay_ = 28 - GameManager::GetInstance().GetDay();
	double powerUpHp_ = GetHp() + (GetHp() * currentDay_ * 0.1); // 계산은  double형으로
	return static_cast<int>(powerUpHp_); // 반환은 int형으로
}
