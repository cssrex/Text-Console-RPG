#pragma once

#include "Monster.h"

class OwkChief : public Monster{
public:
	OwkChief() : Monster(

		"오크 족장",
		30,
		1000,
		0,
		150,
		"오크 족장의 거대한 대검",
		RandGold(300, 350),
		150,
		100,
		300
		
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void HyperAttack(Player* player) override;
	void PrintAsciiArt(short startX = 40, short startY = 0) override;

private:
	int turnCount_ = 0;
};