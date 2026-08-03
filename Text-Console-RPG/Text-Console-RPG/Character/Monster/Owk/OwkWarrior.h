#pragma once

#include "NormalMonster.h"

class OwkWarrior : public NormalMonster {
public:
	OwkWarrior() : NormalMonster(

		"오크 전사",
		21,
		600,
		0,
		50,
		"오크의 어금니",
		RandGold(100, 120),
		300,
		70,
		200
		
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX, short startY) override;
	void MonsterAppearanceScript() override;
	void MonsterDeadScript() override;
};