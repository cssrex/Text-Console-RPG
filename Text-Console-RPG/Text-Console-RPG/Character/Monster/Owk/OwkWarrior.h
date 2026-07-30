#pragma once

#include "Monster.h"

class OwkWarrior : public Monster{
public:
	OwkWarrior(int level = 21) : Monster(
		{
			"오크 전사",
			level,
			600,
			0,
			50,
			"오크의 어금니",
			randGold(100, 120),
			50
		}
	) {}

	void Attack(Character& target) override;
};