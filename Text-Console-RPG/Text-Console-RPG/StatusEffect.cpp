#include <iostream>

#include "StatusEffect.h"
#include "Character.h"
#include "LogManager.h"

using namespace std;

StatusEffect::StatusEffect(const string& name, int damage, int turn)
    : name_(name), damage_(damage), turn_(turn) {
}

void StatusEffect::ApplyEffect(Character& target) {
    if (turn_ > 0) {
        LogManager::GetInstance().PrintStatusEffectDamage(name_, target.GetName(), damage_);
        target.TakeDamage(damage_);
        turn_--;
    }
}

bool StatusEffect::IsExpired() const {
    return turn_ <= 0;
}

// 출혈 자식 클래스 생성자
BleedEffect::BleedEffect(int damage, int turn)
    : StatusEffect("출혈", damage, turn) {
}

// 독 자식 클래스 생성자
PoisonEffect::PoisonEffect(int damage, int turn)
    : StatusEffect("독", damage, turn) {
}

// 화상 자식 클래스 생성자
BurnEffect::BurnEffect(int damage, int turn)
    : StatusEffect("화상", damage, turn) {
}