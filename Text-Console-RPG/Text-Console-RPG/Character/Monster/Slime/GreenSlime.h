#pragma once

#include "Monster.h"

class GreenSlime : public Monster{
public:
	GreenSlime(int level = 1) : Monster(
		"초록 슬라임",
		level,
		20,
		0,
		5,
		"슬라임 볼",
		randGold(10, 20),
		25
		) {}
	
	void Attack(Character& target) override;
};