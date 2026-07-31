#include <iostream>
#include <iomanip>

#include "Character.h"
#include "Player.h"
#include "Skill.h"
#include "StatusEffect.h"
#include "LogManager.h"
#include "Inventory.h"

using namespace std;

// 초기 스텟 설정
Player::Player(string name)
    : Character(name, 1, 200, 50, 30), exp_(0), maxExp_(100), gold_(0), defense_(10) {

    // 기본 스킬 생성
    skills_.push_back(new BasicAttack());
    skills_.push_back(new SkillOne());
    skills_.push_back(new SkillTwo());

    inventory = new Inventory{};
}

void Player::PrintStatus() const {
    LogManager::GetInstance().ClearScreen();
    LogManager::GetInstance().PrintPlayerStatus(name_, level_, exp_, maxExp_, hp_, maxHp_, mp_, maxMp_, attack_, defense_);

    LogManager::GetInstance().PrintSkillListHeader();
    for (size_t i = 0; i < skills_.size(); ++i) {
        LogManager::GetInstance().PrintSkillItem(i + 1, skills_[i]->GetName(), skills_[i]->GetCost());
    }

    if (!statusEffects_.empty()) {
        LogManager::GetInstance().PrintActiveStatusEffectsHeader();
        for (auto effect : statusEffects_) {
            LogManager::GetInstance().PrintActiveStatusEffectItem(effect->GetName(), effect->GetTurn());
        }
    }
    LogManager::GetInstance().PrintPlayerStatusFooter();
}

// 피해 계산
void Player::TakeDamage(int damage) {
    int actualDamage = damage - defense_;
    if (actualDamage < 1) actualDamage = 1;

    hp_ -= actualDamage;
    if (hp_ < 0) hp_ = 0;

    LogManager::GetInstance().PrintPlayerTakeDamage(name_, actualDamage, defense_, hp_, maxHp_);
}

// 경험치 획득
void Player::AddExp(int exp) {
    exp_ += exp;
    LogManager::GetInstance().PrintAddExp(exp, exp_, maxExp_);

    while (exp_ >= maxExp_) {
        exp_ -= maxExp_;
        LevelUp();
    }
}

// 레벨업
void Player::LevelUp() {
    int oldLevel = level_;
    level_++;
    maxExp_ += 25;

    int hpBonus = level_ * hpBonusPerLevel_;
    int attackBonus = level_ * attackBonusPerLevel_;
    int defenseBonus = defenseBonusPerLevel_;

    maxHp_ += hpBonus;
    maxMp_ += 10;
    attack_ += attackBonus;
    defense_ += defenseBonus;

    hp_ = maxHp_;
    mp_ = maxMp_;

    LogManager::GetInstance().PrintLevelUp(oldLevel, level_);
}

void Player::LevelDown() {
    if (level_ > 1) {
        level_--;
        LogManager::GetInstance().PrintLevelDown(level_);
    }
}

void Player::AddGold(int gold) {
    gold_ += gold;
    LogManager::GetInstance().PrintAddGold(gold);
}