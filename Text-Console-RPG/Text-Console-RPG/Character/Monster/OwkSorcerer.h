#pragma once

#include "Monster.h"

class OwkSorcerer : public Monster{
public:
	OwkSorcerer() : Monster(
		{
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
		}
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;

private:
	int turnCount_ = 0;
};