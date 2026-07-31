#pragma once

#include "Monster.h"

class KingSlime : public Monster{
public:
	KingSlime() : Monster(
		"킹 슬라임",
		10,
		300,
		0,
		25,
		"슬라임 추출액",
		RandGold(100, 150),
		50,
		100,
		150
	) {}

	
	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void HyperAttack(Player* player) override;
	void PrintAsciiArt(short startX = 40, short startY = 0) override;
private:
	int turnCount_ = 0;
};