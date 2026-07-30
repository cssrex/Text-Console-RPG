#pragma once

#include "Monster.h"

class HornSlime : public Monster{
public:
	HornSlime(int level = 4) : Monster(
		"가시 슬라임",
		level,
		30,
		0,
		5,
		"슬라임 볼",
		randGold(20, 30),
		30
	) {}

	void Attack(Character& target) override;

};