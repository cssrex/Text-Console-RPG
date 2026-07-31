#pragma once

#include "Monster.h"

class GoblinSorcerer : public Monster{

public:
	GoblinSorcerer() : Monster(

		"고블린 주술사",
		20,
		400,
		0,
		100,
		"주술사의 지팡이",
		RandGold(200, 250),
		100,
		100,
		200
		
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void HyperAttack(Player* player) override;

private:
	int turnCount_ = 0;
};