#pragma once

#include "NormalMonster.h"

class Wyvern : public NormalMonster {
public:
	Wyvern() : NormalMonster(

		"와이번",
		31,
		1000,
		0,
		130,
		"용혈",
		RandGold(200, 220),
		500,
		70,
		200
		
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX, short startY) override;
	void MonsterAppearanceScript() override;
	void MonsterDeadScript() override;
};