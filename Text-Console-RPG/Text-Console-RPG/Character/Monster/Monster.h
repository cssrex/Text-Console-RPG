#pragma once

#include "Character.h"
#include <random>

class Monster : public Character
{
protected:
	std::string dropItem_;
	int dropGold_;
	int rewardExp_;

	// °ñµå ·£´ý È¹µæ
	int randGold(int minGold, int maxGold){

		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(minGold, maxGold);

		return dis(gen);
	}
	

public:
	Monster(const std::string& name, int level, int maxHp, int maxMp, int attack, const std::string& getdropItem, int getdropGold, int getrewardExp) :
			Character(name, level, maxHp, maxMp, attack), dropItem_(getdropItem), dropGold_(getdropGold), rewardExp_(getrewardExp) {}
	virtual ~Monster() = default;


	std::string getdropItem() const { return dropItem_; }
	int getdropGold() const { return dropGold_; }
	int getrewardExp() const { return rewardExp_; }

	virtual void Attack(Character& target) = 0;
	virtual void SpecialAttack(Character& target);
	void TakeDamage(int damage) override;
	virtual void TakeTurn(Character& target);
};

