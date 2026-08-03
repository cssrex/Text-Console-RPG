#pragma once

#include "NormalMonster.h"

class Drake : public NormalMonster {
public:
	Drake() : NormalMonster(

		"드레이크",
		35,
		1100,
		0,
		150,
		"용혈",
		RandGold(250, 270),
		500,
		80,
		200
		
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