#pragma once

#include "NormalMonster.h"

class HornSlime : public NormalMonster {
public:
	HornSlime() : NormalMonster(
		"가시 슬라임",
		4,
		30,
		0,
		5,
		"슬라임 볼",
		RandGold(20, 30),
		200,
		80,
		90
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX, short startY) override;
	void MonsterAppearanceScript() override;
	void MonsterDeadScript() override;
};