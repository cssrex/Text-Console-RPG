#include <iostream>

#include "Skill.h"
#include "Character.h"
#include "StatusEffect.h"
#include "LogManager.h"
#include "GameSound.h"

using namespace std;

Skill::Skill(const string& name, const string& description, int cost, int percent, StatusEffect* statusEffect)
    : name_(name), description_(description), cost_(cost), percent_(percent), statusEffect_(statusEffect) {
}

Skill::~Skill() {
    if (statusEffect_ != nullptr) {
        delete statusEffect_;
        statusEffect_ = nullptr;
    }
}

bool Skill::CanUse(int currentMp) const {
    return currentMp >= cost_;
}

// 기본공격
NormalAttack::NormalAttack()
    : Skill("기본 공격", "상대에게 기본 데미지를 입힙니다.", 0, 100, nullptr) {
}

void NormalAttack::Use(Character& caster, Character& target) {
    GameSound::PlayAttackSfx();
    int damage = (caster.GetAttack() * percent_) / 100;
    LogManager::GetInstance().PrintSkillUseBasic(caster.GetName(), target.GetName(), damage);
    target.TakeDamage(damage);
}

// 강화평타 (MP 5 소모, 기본 공격력의 120% 데미지)
BasicAttack::BasicAttack()
    : Skill("강화평타", "기본 공격력의 120% 데미지를 줍니다.", 5, 120, nullptr) {
}

void BasicAttack::Use(Character& caster, Character& target) {
    if (!CanUse(caster.GetMp())) {
        LogManager::GetInstance().PrintSkillMpLack(name_);
        return;
    }
    caster.UseMp(cost_);
    GameSound::PlayStrongSkillSfx();
    int damage = (caster.GetAttack() * percent_) / 100;
    LogManager::GetInstance().PrintSkillUseBasic(caster.GetName(), target.GetName(), damage);
    target.TakeDamage(damage);
}

// 스킬 1 (MP 10 소모, 150 % 데미지 + 출혈 부여)
SkillOne::SkillOne()
    : Skill("강격", "기본 공격력의 150% 데미지를 주고 출혈을 부여합니다.", 10, 150, new BleedEffect(10, 3)) {
}

void SkillOne::Use(Character& caster, Character& target) {
    if (!CanUse(caster.GetMp())) {
        LogManager::GetInstance().PrintSkillMpLack(name_);
        return;
    }

    caster.UseMp(cost_);
    GameSound::PlayStrongSkillSfx();
    int damage = (caster.GetAttack() * percent_) / 100;
    LogManager::GetInstance().PrintSkillOneUse(caster.GetName(), name_, target.GetName(), damage);
    target.TakeDamage(damage);

    // 상태이상 동적 할당
    target.AddStatusEffect(new BleedEffect(10, 3));
}

// 스킬 2 (MP 25 소모, 180% 데미지 + 화상 부여)
SkillTwo::SkillTwo()
    : Skill("화염 베기", "기본 공격력의 180% 데미지를 주고 화상을 부여합니다.", 15, 180, new BurnEffect(20, 2)) {
}

void SkillTwo::Use(Character& caster, Character& target) {
    if (!CanUse(caster.GetMp())) {
        LogManager::GetInstance().PrintSkillMpLack(name_);
        return;
    }

    caster.UseMp(cost_);
    GameSound::PlayStrongSkillSfx();
    int damage = (caster.GetAttack() * percent_) / 100;
    LogManager::GetInstance().PrintSkillTwoUse(caster.GetName(), name_, target.GetName(), damage);
    target.TakeDamage(damage);

    // 상태이상 동적 할당
    target.AddStatusEffect(new BurnEffect(20, 2));
}