#pragma once

#include "NormalMonster.h"

class GreenSlime : public NormalMonster {
public:
	GreenSlime() : NormalMonster(
		"초록 슬라임",
		1,
		20,
		0,
		5,
		"슬라임 볼",
		RandGold(10, 20),
		200,
		70,
		90
	) {
		SetMaxHp(CalculatePowerUpHp());
		SetHp(CalculatePowerUpHp());
	}
	
	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX, short startY) override;
	void MonsterAppearanceScript() override;
	void MonsterDeadScript() override;
};