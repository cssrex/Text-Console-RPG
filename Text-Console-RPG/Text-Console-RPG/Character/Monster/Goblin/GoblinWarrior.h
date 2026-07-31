#pragma once

#include "Monster.h"

class GoblinWarrior : public Monster{
public:
	GoblinWarrior() : Monster(

		"고블린 전사",
		11,
		300,
		0,
		20,
		"고블린의 허름한 망토",
		RandGold(30, 40),
		50,
		70,
		100
		
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX = 40, short startY) override;
};