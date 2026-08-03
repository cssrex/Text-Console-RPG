#pragma once
#include "Character.h"
#include "Player.h"
#include "..\..\..\AsciiArt\MonsterAsciiArt.h"
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

	std::vector<std::string> slimeCry_ = { "물컹...", "출렁출렁", "부글부글..." };
	std::vector<std::string> goblinCry_ = { "키히히!", "캬악!", "케케켁!" };
	std::vector<std::string> owkCry_ = { "크르릉!", "그르르...", "쿠아앙!" };
	std::vector<std::string> dragonCry_ = { "크아아아!", "쉬이이익...", "그르렁!" };

	// 골드 랜덤 획득
	int RandGold(int minGold, int maxGold) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(minGold, maxGold);
		return dis(gen);
	}
	// 드랍템 확률 계산
	bool RollDropChance() {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(1, 100);
		return dis(gen) <= dropChance_;
	}
	// 몬스터 울음소리
	std::string RandCry(std::vector<std::string>& cry_) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, cry_.size() - 1);
		return cry_[dis(gen)];
	}

public:
	Monster(const std::string& name, int level, int maxHp, int maxMp, int attack, const std::string& getdropItem, int getdropGold, int getrewardExp, int dropChance, int sellPrice) :
		Character(name, level, maxHp, maxMp, attack), dropItem_(getdropItem), dropGold_(getdropGold), rewardExp_(getrewardExp), dropChance_(dropChance), sellPrice_(sellPrice) {
	}
	virtual ~Monster() = default;
	std::string GetDropItem() const { return dropItem_; }
	int GetDropGold() const { return dropGold_; }
	int GetRewardExp() const { return rewardExp_; }
	int GetSellPrice() const { return sellPrice_; }

	void TakeDamage(int damage) override;

	void Attack(Player* player);

	virtual void BasicAttack(Player* player) = 0;
	virtual void SpecialAttack(Player* player) = 0;

	virtual void HyperAttack(Player* player) {};

	bool SpecialAttackTurn() const;
	virtual bool HyperAttackTurn() const;
	virtual void PrintAsciiArt(short startX = 40, short startY = 0) = 0;

	virtual void MonsterAppearanceScript() {}
	virtual void MonsterDeadScript() {}
	
	virtual int CalculatePowerUpAttack() const;
};