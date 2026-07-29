#include <iostream>

#include "Character.h"
#include "Skill.h"
#include "StatusEffect.h"

using namespace std;

Character::Character(const string& name, int level, int maxHp, int maxMp, int attack)
    : name_(name), level_(level), hp_(maxHp), maxHp_(maxHp), mp_(maxMp), maxMp_(maxMp), attack_(attack) {
}

Character::~Character() {
    for (auto skill : skills_) delete skill;
    for (auto effect : statusEffects_) delete effect;
    skills_.clear();
    statusEffects_.clear();
}

void Character::PrintStatus() const {
    cout << "-----------------------------------------------\n";
    cout << "이름: " << name_ << " | Lv." << level_ << "\n";
    cout << "HP: " << hp_ << " / " << maxHp_ << " | MP: " << mp_ << " / " << maxMp_ << "\n";
    cout << "공격력: " << attack_ << "\n";
    cout << "-----------------------------------------------\n";
}

void Character::ShowAllSkill() const {
    cout << "=== " << name_ << "의 보유 스킬 목록 ===\n";
    for (size_t i = 0; i < skills_.size(); ++i) {
        cout << "[" << i + 1 << "] " << skills_[i]->GetName()
            << " (소모 MP: " << skills_[i]->GetCost() << ")\n";
    }
    cout << "===============================\n";
}

void Character::TakeDamage(int damage) {
    hp_ -= damage;
    if (hp_ < 0) hp_ = 0;
    cout << name_ << "이(가) " << damage << "의 피해를 입었습니다. (남은 HP: " << hp_ << " / " << maxHp_ << ")\n";
}

void Character::Heal(int value) {
    hp_ += value;
    if (hp_ > maxHp_) hp_ = maxHp_;
    cout << name_ << "의 체력이 " << value << "만큼 회복되었습니다.\n";
}

void Character::UseMp(int amount) {
    mp_ -= amount;
    if (mp_ < 0) mp_ = 0;
}

void Character::HealMp(int amount) {
    mp_ += amount;
    if (mp_ > maxMp_) mp_ = maxMp_;
}

bool Character::IsDead() const {
    return hp_ <= 0;
}

void Character::AddStatusEffect(StatusEffect* effect) {
    cout << name_ << "에게 [" << effect->GetName() << "] 상태이상이 적용되었습니다!\n";
    statusEffects_.push_back(effect);
}

void Character::UpdateStatusEffects() {
    for (auto it = statusEffects_.begin(); it != statusEffects_.end();) {
        (*it)->ApplyEffect(*this);

        if ((*it)->IsExpired()) {
            cout << name_ << "의 [" << (*it)->GetName() << "] 상태이상이 해제되었습니다.\n";
            delete* it;
            it = statusEffects_.erase(it);
        }
        else {
            ++it;
        }
    }
}