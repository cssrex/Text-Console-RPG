#pragma once

#include "Monster.h"

class HornSlime : public Monster{
public:
	HornSlime() : Monster(
		"가시 슬라임",
		4,
		30,
		0,
		5,
		"슬라임 볼",
		RandGold(20, 30),
		30,
		80,
		90
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX = 40, short startY = 0) override;
};