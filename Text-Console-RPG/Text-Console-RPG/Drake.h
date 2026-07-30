#pragma once

#include "Monster.h"

class Drake : public Monster{
public:
	Drake(int level = 35) : Monster(
		{
			"드레이크",
			level,
			1100,
			0,
			150,
			"용혈",
			randGold(250, 270),
			100
		}
	) {}

	void Attack(Character& target) override;
};