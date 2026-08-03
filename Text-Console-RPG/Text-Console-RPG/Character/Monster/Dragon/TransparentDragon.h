#pragma once

#include "Monster.h"

class TransparentDragon : public Monster{
public:
	TransparentDragon() : Monster(

		"투명 드래곤",
		40,
		2000,
		0,
		200,
		"현생 귀환권",
		100000000,
		0,
		100,
		0
		
	) {
		SetMaxHp(CalculatePowerUpHp());
		SetHp(CalculatePowerUpHp());
	}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void HyperAttack(Player* player) override;
	void PrintAsciiArt(short startX, short startY) override;
	void MonsterAppearanceScript() override;
	void MonsterDeadScript() override;

private:
	int turnCount_ = 0;
};