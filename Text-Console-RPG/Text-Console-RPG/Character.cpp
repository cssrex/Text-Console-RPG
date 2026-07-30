#include <iostream>

#include "Character.h"
#include "Skill.h"
#include "StatusEffect.h"
#include "LogManager.h"

using namespace std;

Character::Character(const string& name, int level, int hp, int mp, int attack)
    : name_(name), level_(level), hp_(hp), maxHp_(hp), mp_(mp), maxMp_(mp), attack_(attack) {
}

Character::~Character() {
    for (auto skill : skills_) {
        delete skill;
    }
    skills_.clear();

    for (auto effect : statusEffects_) {
        delete effect;
    }
    statusEffects_.clear();
}

void Character::PrintStatus() const {
    LogManager::GetInstance().PrintCharacterStatus(name_, level_, hp_, maxHp_, mp_, maxMp_, attack_);
}

void Character::ShowAllSkill() const {
    LogManager::GetInstance().PrintShowAllSkillHeader(name_);
    for (size_t i = 0; i < skills_.size(); ++i) {
        LogManager::GetInstance().PrintShowAllSkillItem(i + 1, skills_[i]->GetName(), skills_[i]->GetCost());
    }
    LogManager::GetInstance().PrintShowAllSkillFooter();
}

// 기본 피격 처리
void Character::TakeDamage(int damage) {
    hp_ -= damage;
    if (hp_ < 0) hp_ = 0;
    LogManager::GetInstance().PrintTakeDamage(name_, damage, hp_, maxHp_);
}

// 체력 회복
void Character::Heal(int value) {
    hp_ += value;
    if (hp_ > maxHp_) {
        hp_ = maxHp_;
    }

    LogManager::GetInstance().PrintHeal(name_, value);
}

// 마나 소모
void Character::UseMp(int amount) {
    mp_ -= amount;
    if (mp_ < 0) mp_ = 0;
}

// 상태이상 추가
void Character::AddStatusEffect(StatusEffect* effect) {
    LogManager::GetInstance().PrintAddStatusEffect(name_, effect->GetName());
    statusEffects_.push_back(effect);
}

// Turn 기반 상태이상 갱신(턴 종료 시 호출)
void Character::UpdateStatusEffects() {
    for (auto it = statusEffects_.begin(); it != statusEffects_.end();) {
        (*it)->ApplyEffect(*this);

        if ((*it)->IsExpired()) {
            LogManager::GetInstance().PrintRemoveStatusEffect(name_, (*it)->GetName());
            delete* it;
            it = statusEffects_.erase(it);
        }
        else {
            ++it;
        }
    }
}