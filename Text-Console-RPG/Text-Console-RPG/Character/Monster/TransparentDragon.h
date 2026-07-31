#pragma once

#include "Monster.h"

class TransparentDragon : public Monster{
public:
	TransparentDragon() : Monster(
		{
			"Åõ¸í µå·¡°ï",
			40,
			2000,
			0,
			200,
			"Çö»ý ±ÍÈ¯±Ç",
			100000000,
			0,
			100,
			0
		}
	) {}

	void Attack() override;
	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void SpecialAttackTurn(Player* player) override;
	void HyperAttack(Player* player) override;
	void HyperAttackTurn(Player* player) override;

private:
	int turnCount_ = 0;
};