#pragma once

#include "Monster.h"

class Wyvern : public Monster{
public:
	Wyvern(int level = 31) : Monster(
		{
			"와이번",
			level,
			1000,
			0,
			130,
			"용혈",
			randGold(200, 220),
			100
		}
	) {}

	void Attack(Character& target) override;
};