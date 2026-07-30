#pragma once

#include "Monster.h"

class OwkChief : public Monster{
public:
	OwkChief(int level = 30) : Monster(
		
			"오크 족장",
			level,
			1000,
			0,
			150,
			"오크 족장의 거대한 대검",
			randGold(300, 350),
			150
		
	) {}

	void Attack(Character& target) override;
	void SpecialAttack(Character& target) override;
	void TakeTurn(Character& target) override;

private:
	int turnCount_ = 0;
};