#pragma once

#include "Monster.h"

class GoblinArcher : public Monster{
public:
	GoblinArcher(int level = 15) : Monster(

		"고블린 궁수",
		15,
		200,
		0,
		40,
		"고블린의 허름한 망토",
		RandGold(50, 60),
		60,
		80,
		100
		
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX, short startY) override;
	void MonsterAppearanceScript() override;
	void MonsterDeadScript() override;
};