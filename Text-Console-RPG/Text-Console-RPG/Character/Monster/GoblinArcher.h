#pragma once

#include "Monster.h"

class GoblinArcher : public Monster{
public:
	GoblinArcher() : Monster(
		{
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
		}
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;

private:
	int turnCount_ = 0;
};