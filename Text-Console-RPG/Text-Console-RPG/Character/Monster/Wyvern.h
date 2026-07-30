#pragma once

#include "Monster.h"

class Wyvern : public Monster{
public:
	Wyvern() : Monster(
		{
			"와이번",
			31,
			1000,
			0,
			130,
			"용혈",
			RandGold(200, 220),
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