#pragma once

#include "NormalMonster.h"

class GoblinWarrior : public NormalMonster {
public:
	GoblinWarrior() : NormalMonster(

		"고블린 전사",
		11,
		300,
		0,
		20,
		"고블린의 허름한 망토",
		RandGold(30, 40),
		300,
		70,
		100
		
	) {
		SetMaxHp(CalculatePowerUpHp());
		SetHp(CalculatePowerUpHp());
	}

	void BasicAttack(Player* player) override;
	void SpecialAttack(Player* player) override;
	void PrintAsciiArt(short startX, short startY) override;
	void MonsterAppearanceScript() override;
	void MonsterDeadScript() override;
};