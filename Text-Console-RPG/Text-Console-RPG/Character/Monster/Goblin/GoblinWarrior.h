#pragma once

#include "Monster.h"

class GoblinWarrior : public Monster{
public:
	GoblinWarrior(int level = 11) : Monster(
		
			"고블린 전사",
			level,
			300,
			0,
			20,
			"고블린의 허름한 망토",
			randGold(30, 40),
			50
		
	) {}

	void Attack(Character& target) override;
};