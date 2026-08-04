#include <iostream>

#include "Character.h"
#include "Skill.h"
#include "StatusEffect.h"
#include "LogManager.h"
#include "GameSound.h"

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

    GameSound::PlayMonsterHitSfx();
    LogManager::GetInstance().PrintTakeDamage(name_, damage, hp_, maxHp_);
}

// 체력 회복
void Character::Heal(int value) {
    hp_ += value;
    if (hp_ > maxHp_) {
        hp_ = maxHp_;
    }

    GameSound::PlayHealSfx();
    LogManager::GetInstance().PrintHeal(name_, value);
}

// MP 회복
void Character::HealMp(int amount) {
    mp_ += amount;
    if (mp_ > maxMp_) {
        mp_ = maxMp_;
    }

    GameSound::PlayHealSfx();
    LogManager::GetInstance().PrintMpHeal(name_, amount);
}

// 마나 소모
void Character::UseMp(int amount) {
    mp_ -= amount;
    if (mp_ < 0) mp_ = 0;
}

// 상태이상 추가
void Character::AddStatusEffect(StatusEffect* effect) {
    if (effect == nullptr) return;

    // 이미 동일한 상태이상이 걸려있는지 탐색
    for (auto existingEffect : statusEffects_) {
        if (existingEffect->GetName() == effect->GetName()) {
            // 이미 존재함 -> 턴 수 갱신 (새로 들어온 effect의 초기 턴 수로 리셋)
            existingEffect->ResetTurn(effect->GetTurn());

            // 턴 갱신 로그
            LogManager::GetInstance().PrintRefreshStatusEffect(name_, effect->GetName(), existingEffect->GetTurn());
            GameSound::PlayHitBeep();

            // 동적 할당 객체 메모리 해제
            delete effect; 
            return;
        }
    }

    // 신규 상태이상 추가
    statusEffects_.push_back(effect);
    LogManager::GetInstance().PrintAddStatusEffect(name_, effect->GetName(), effect->GetTurn());
    GameSound::PlayHitBeep();
}

// Turn 기반 상태이상 갱신(턴 종료 시 호출)
void Character::UpdateStatusEffects() {
    for (auto it = statusEffects_.begin(); it != statusEffects_.end();) {
        // 매턴마다 걸려있는 상태효과의 데미지를 적용
        (*it)->ApplyEffect(*this);

        // 효과 적용 후 턴을 1 차감
        (*it)->DecreaseTurn();

        // 남은 턴이 0 이하로 만료되었으면 메모리 해제 및 삭제
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

// 상태이상 해제
void Character::ClearStatusEffects() {
    for (auto effect : statusEffects_)
    {
        delete effect;
    }

    statusEffects_.clear();
    GameSound::PlayHealSfx();
    LogManager::GetInstance().PrintRemoveAllStatusEffect(name_);
}

// 상태이상 여부 검사 
bool Character::HasStatusEffect() const {
    return !statusEffects_.empty();
}