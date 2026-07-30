#pragma once

#include "Monster.h"

class GoblinSorcerer : public Monster{

public:
	GoblinSorcerer(int level = 20) : Monster(
		
			"고블린 주술사",
			level,
			400,
			0,
			100,
			"주술사의 지팡이",
			randGold(200, 250),
			100
		
	) {}

	void Attack(Character& target) override;
	void SpecialAttack(Character& target) override;
	void TakeTurn(Character& target) override;

private:
	int turnCount_ = 0;
};