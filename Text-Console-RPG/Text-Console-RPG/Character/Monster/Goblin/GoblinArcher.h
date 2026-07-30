#pragma once

#include "Monster.h"

class GoblinArcher : public Monster{
public:
	GoblinArcher(int level = 15) : Monster(
		{
			"고블린 궁수",
			level,
			200,
			0,
			40,
			"고블린의 허름한 망토",
			randGold(50, 60),
			60
		}
	) {}

	void Attack(Character& target) override;
};