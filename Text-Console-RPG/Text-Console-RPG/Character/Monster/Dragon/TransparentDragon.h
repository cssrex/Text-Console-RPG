#pragma once

#include "Monster.h"

class TransparentDragon : public Monster{
public:
	TransparentDragon(int level = 40) : Monster(
		
			"투명 드래곤",
			level,
			2000,
			0,
			200,
			"현생 귀환권",
			100000000,
			0
		
	) {}

	void Attack(Character& target) override;
	void SpecialAttack(Character& target) override;
	void TakeTurn(Character& target) override;

private:
	int turnCount_ = 0;
};