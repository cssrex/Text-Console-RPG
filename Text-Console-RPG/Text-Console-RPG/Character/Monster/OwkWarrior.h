#pragma once

#include "Monster.h"

class OwkWarrior : public Monster{
public:
	OwkWarrior() : Monster(
		{
			"오크 전사",
			21,
			600,
			0,
			50,
			"오크의 어금니",
			RandGold(100, 120),
			50,
			70,
			200
		}
	) {}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;

private:
	int turnCount_ = 0;
};