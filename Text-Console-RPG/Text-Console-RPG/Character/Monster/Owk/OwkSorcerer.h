#pragma once

#include "Monster.h"

class OwkSorcerer : public Monster{
public:
	OwkSorcerer(int level = 25) : Monster(

		"오크 주술사",
		25,
		500,
		0,
		80,
		"오크의 어금니",
		RandGold(130, 140),
		75,
		90,
		200
		
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX, short startY) override;
	void MonsterAppearanceScript() override;
	void MonsterDeadScript() override;
};