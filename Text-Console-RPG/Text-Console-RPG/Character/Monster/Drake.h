#pragma once

#include "Monster.h"

class Drake : public Monster{
public:
	Drake() : Monster(
		{
			"드레이크",
			35,
			1100,
			0,
			150,
			"용혈",
			RandGold(250, 270),
			100,
			80,
			200
		}
	) {}
	
	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;

private:
	int turnCount_ = 0;
};