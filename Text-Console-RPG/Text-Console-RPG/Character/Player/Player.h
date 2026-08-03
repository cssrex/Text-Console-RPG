#pragma once

#include "Character.h"

class Inventory;
class Player : public Character {
private:
    int exp_;
    int maxExp_;
    int gold_;
    int defense_; 

    // 레벨업 시 스텟 증가 수치
    int hpBonusPerLevel_ = 20;
    int mpBonusPerLevel_ = 10;
    int attackBonusPerLevel_ = 5;   
    int defenseBonusPerLevel_ = 2;

    Inventory* inventory;

public:
    Player(std::string name);
    virtual ~Player() = default;

    // 상태창 오버라이딩(UI 디자인 레이아웃)
    void PrintStatus() const override;

    // 피격 로직 오버라이딩
    void TakeDamage(int damage) override;

    // 플레이어 전용 메서드
    void AddExp(int exp);
    void AddGold(int gold);
    void LevelUp();
    void LevelDown();

    int GetExp() const { return exp_; }
    int GetMaxExp() const { return maxExp_; }
    int GetGold() const { return gold_; }
    int GetDefense() const { return defense_; }
    void SetDefense(int defense) { defense_ = defense; }
    Inventory* GetInventory() { return inventory; }
};

