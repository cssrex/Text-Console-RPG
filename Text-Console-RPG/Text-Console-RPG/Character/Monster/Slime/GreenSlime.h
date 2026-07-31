#pragma once

#include "Monster.h"

class GreenSlime : public Monster{
public:
	GreenSlime() : Monster(
		"초록 슬라임",
		1,
		20,
		0,
		5,
		"슬라임 볼",
		RandGold(10, 20),
		25,
		70,
		90
	) {}
	
	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
};