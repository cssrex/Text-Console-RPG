#pragma once

#include "Monster.h"

class KingSlime : public Monster{
public:
	KingSlime(int level = 10) : Monster(
		"킹 슬라임",
		level,
		300,
		0,
		25,
		"슬라임 추출액",
		randGold(100, 150),
		50
	) {}

	void Attack(Character& target) override;
	void SpecialAttack(Character& target) override;
	void TakeTurn(Character& target) override;

private:
	int turnCount_ = 0;
};