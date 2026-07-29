#include <iostream>

#include "StatusEffect.h"
#include "Character.h"

using namespace std;

StatusEffect::StatusEffect(const string& name, int damage, int turn)
    : name_(name), damage_(damage), turn_(turn) {
}

void StatusEffect::ApplyEffect(Character& target) {
    if (turn_ > 0) {
        cout << "[" << name_ << "] 효과 발생! " << target.GetName()
            << "에게 " << damage_ << "의 지속 피해를 입힙니다.\n";
        target.TakeDamage(damage_);
        turn_--;
    }
}

bool StatusEffect::IsExpired() const {
    return turn_ <= 0;
}

// 출혈
BleedEffect::BleedEffect(int damage, int turn)
    : StatusEffect("출혈", damage, turn) {
}

// 독
PoisonEffect::PoisonEffect(int damage, int turn)
    : StatusEffect("독", damage, turn) {
}

// 화상
BurnEffect::BurnEffect(int damage, int turn)
    : StatusEffect("화상", damage, turn) {
}