#include <iostream>

#include "StatusEffect.h"
#include "Character.h"
#include "LogManager.h"

using namespace std;

StatusEffect::StatusEffect(const string& name, int damage, int turn)
    : name_(name), damage_(damage), turn_(turn) {
}

// 매턴마다 캐릭터에게 상태효과 데미지를 적용하는 함수
void StatusEffect::ApplyEffect(Character& target) {
    if (turn_ > 0) {
        LogManager::GetInstance().PrintStatusEffectDamage(name_, target.GetName(), damage_);
        target.TakeDamage(damage_);
    }
}

// 상태효과의 남은 턴 수를 1 줄이는 함수
void StatusEffect::DecreaseTurn() {
    if (turn_ > 0) {
        turn_--;
    }
}

// 남은 턴이 없어서 효과가 종료되었는지 검사하는 함수
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