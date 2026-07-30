#pragma once

#include "Monster.h"

class PoisonSlime : public Monster{
public:
	PoisonSlime(int level = 8) : Monster(
		"독 슬라임",
		level,
		40,
		0,
		5,
		"슬라임 볼",
		randGold(30, 40),
		35
	) {}

	void Attack(Character& target) override;
};