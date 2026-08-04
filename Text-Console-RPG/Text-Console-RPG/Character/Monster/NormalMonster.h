#pragma once
#include "Monster.h"

class NormalMonster : public Monster
{
public:
	using Monster::Monster; // 부모 생성자 그대로 사용

	bool HyperAttackTurn() const override { return false; }
};