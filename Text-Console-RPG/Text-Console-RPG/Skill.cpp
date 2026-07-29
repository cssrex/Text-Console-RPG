#include <iostream>

#include "Skill.h"
#include "Character.h"
#include "StatusEffect.h"

using namespace std;

Skill::Skill(const string& name, int cost, int percent, StatusEffect* statusEffect)
    : name_(name), cost_(cost), percent_(percent), statusEffect_(statusEffect) {
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

// 평타 (코스트 0, 기본 데미지)
BasicAttack::BasicAttack()
    : Skill("평타", 0, 100, nullptr) {
}

void BasicAttack::Use(Character& caster, Character& target) {
    int damage = (caster.GetAttack() * percent_) / 100;
    cout << caster.GetName() << "의 평타! " << target.GetName()
        << "에게 " << damage << "의 피해를 입혔습니다.\n";
    target.TakeDamage(damage);
}

// 스킬 1 (MP 15 소모, 150% 데미지 + 출혈 부여)
SkillOne::SkillOne()
    : Skill("강격", 15, 150, new BleedEffect(10, 3)) {
}

void SkillOne::Use(Character& caster, Character& target) {
    if (!CanUse(caster.GetMp())) {
        cout << "MP가 부족하여 " << name_ << " 스킬을 사용할 수 없습니다!\n";
        return;
    }

    caster.UseMp(cost_);
    int damage = (caster.GetAttack() * percent_) / 100;
    cout << caster.GetName() << "의 " << name_ << "! " << target.GetName()
        << "에게 " << damage << "의 강력한 피해를 입혔습니다.\n";
    target.TakeDamage(damage);

    // 상태이상 동적 할당
    target.AddStatusEffect(new BleedEffect(10, 3));
}

// 스킬 2 (MP 25 소모, 120% 데미지 + 화상 부여)
SkillTwo::SkillTwo()
    : Skill("화염 베기", 25, 120, new BurnEffect(20, 2)) {
}

void SkillTwo::Use(Character& caster, Character& target) {
    if (!CanUse(caster.GetMp())) {
        cout << "MP가 부족하여 " << name_ << " 스킬을 사용할 수 없습니다!\n";
        return;
    }

    caster.UseMp(cost_);
    int damage = (caster.GetAttack() * percent_) / 100;
    cout << caster.GetName() << "의 " << name_ << "! " << target.GetName()
        << "에게 " << damage << "의 피해를 입혔습니다.\n";
    target.TakeDamage(damage);

    // 상태이상 동적 할당
    target.AddStatusEffect(new BurnEffect(20, 2));
}