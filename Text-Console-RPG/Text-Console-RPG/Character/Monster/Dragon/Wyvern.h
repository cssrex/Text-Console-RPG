#pragma once

#include "Monster.h"

class Wyvern : public Monster{
public:
	Wyvern() : Monster(

		"와이번",
		31,
		1000,
		0,
		130,
		"용혈",
		RandGold(200, 220),
		100,
		70,
		200
		
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX, short startY) override;
	void MonsterAppearanceScript() override;
	void MonsterDeadScript() override;
};