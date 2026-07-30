#pragma once

#include "Monster.h"

class OwkSorcerer : public Monster{
public:
	OwkSorcerer(int level = 25) : Monster(
		{
			"오크 주술사",
			level,
			500,
			0,
			80,
			"오크의 어금니",
			randGold(130, 140),
			75
		}
	) {}

	void Attack(Character& target) override;
};