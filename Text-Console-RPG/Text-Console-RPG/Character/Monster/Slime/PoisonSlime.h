#pragma once

#include "NormalMonster.h"

class PoisonSlime : public NormalMonster {
public:
	PoisonSlime() : NormalMonster(
		"독 슬라임",
		8,
		40,
		0,
		5,
		"슬라임 볼",
		RandGold(30, 40),
		35,
		90,
		90
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX, short startY) override;
	void MonsterAppearanceScript() override;
	void MonsterDeadScript() override;
};