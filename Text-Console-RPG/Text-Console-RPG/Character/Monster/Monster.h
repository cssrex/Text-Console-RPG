#pragma once
#include "Character.h"
#include "Player.h"
#include <random>



class Monster : public Character
{
protected:
	std::string dropItem_;
	int dropGold_;
	int rewardExp_;
	int dropChance_;
	int sellPrice_;
	int turnCount_ = 0;
	// 골드 랜덤 획득
	int RandGold(int minGold, int maxGold){
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(minGold, maxGold);
		return dis(gen);
	}
	// 드랍템 확률 계산
	bool RollDropChance()
	{
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(1, 100);
		return dis(gen) <= dropChance_;
	}
	
public:
	Monster(const std::string& name, int level, int maxHp, int maxMp, int attack, const std::string& getdropItem, int getdropGold, int getrewardExp, int dropChance, int sellPrice) :
			Character(name, level, maxHp, maxMp, attack), dropItem_(getdropItem), dropGold_(getdropGold), rewardExp_(getrewardExp), dropChance_(dropChance), sellPrice_(sellPrice) {}
	virtual ~Monster() = default;
	std::string GetDropItem() const { return dropItem_; }
	int GetDropGold() const { return dropGold_; }
	int GetRewardExp() const { return rewardExp_; }
	void TakeDamage(int damage) override;
	virtual void Attack(Player* player);
	virtual void BasicAttack(Player* player) = 0;
	virtual void SpecialAttack(Player* player) = 0;
	virtual void HyperAttack(Player* player) {};
	
	virtual bool SpecialAttackTurn() const;
	virtual bool HyperAttackTurn() const;
	void Reward(Player* player);
};