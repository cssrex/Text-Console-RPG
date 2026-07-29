#include <iostream>
#include <iomanip>

#include "Player.h"
#include "Skill.h"
#include "StatusEffect.h"

using namespace std;

static string MakeGaugeBar(int current, int max, int totalBlocks = 20) {
    if (max <= 0) max = 1;
    int filledBlocks = (current * totalBlocks) / max;
    if (filledBlocks > totalBlocks) filledBlocks = totalBlocks;
    if (filledBlocks < 0) filledBlocks = 0;

    string bar = "";
    for (int i = 0; i < filledBlocks; ++i) bar += "█";
    for (int i = 0; i < totalBlocks - filledBlocks; ++i) bar += "░";
    return bar;
}

// 초기 스텟 설정
Player::Player(string name)
    : Character(name, 1, 200, 50, 30), exp_(0), maxExp_(100), gold_(0), defense_(10) {

    // 기본 스킬 생성
    skills_.push_back(new BasicAttack());
    skills_.push_back(new SkillOne());
    skills_.push_back(new SkillTwo());
}

void Player::PrintStatus() const {
    int expPercent = (maxExp_ > 0) ? (exp_ * 100 / maxExp_) : 0;
    string expBar = "";
    int expBlocks = expPercent / 20;
    for (int i = 0; i < 5; ++i) {
        if (i < expBlocks) expBar += "■";
        else expBar += "□";
    }

    string hpBar = MakeGaugeBar(hp_, maxHp_, 20);
    string mpBar = MakeGaugeBar(mp_, maxMp_, 20);

    cout << "==================================================\n";
    cout << "                 [ 캐릭터 정보 ]                  \n";
    cout << "==================================================\n";
    cout << "  이름 : " << left << setw(24) << name_ << "직업 : 모험가\n";
    cout << "  레벨 : Lv. " << left << setw(22) << level_ << "경험치 : [" << expBar << "] " << expPercent << "%\n";
    cout << "--------------------------------------------------\n";
    cout << "  [ 기본 능력치 (Stats) ]\n";
    cout << "   • HP      : " << hpBar << " " << right << setw(3) << hp_ << " / " << setw(3) << maxHp_ << "\n";
    cout << "   • MP      : " << mpBar << " " << right << setw(3) << mp_ << " / " << setw(3) << maxMp_ << "\n";
    cout << "   • Power   : " << attack_ << "\n";
    cout << "   • Defense : " << defense_ << "\n\n";
    cout << "  <장비>\n";
    cout << "   • 무기    : (없음)\n";
    cout << "   • 방어구  : (없음)\n";
    cout << "--------------------------------------------------\n";
    cout << "  [ 보유 스킬 (Skills) ]\n";

    for (size_t i = 0; i < skills_.size(); ++i) {
        cout << "   [" << i + 1 << "] " << skills_[i]->GetName() << "\n";
        cout << "       └ (소모 MP: " << skills_[i]->GetCost() << ")\n\n";
    }

    if (!statusEffects_.empty()) {
        cout << "--------------------------------------------------\n";
        cout << "  [ 적용 중인 상태이상 ]\n";
        for (auto effect : statusEffects_) {
            cout << "   • " << effect->GetName() << " (지속: " << effect->GetTurn() << "턴 남음)\n";
        }
    }
    cout << "==================================================\n\n";
}

// 피해 계산
void Player::TakeDamage(int damage) {
    int actualDamage = damage - defense_;
    if (actualDamage < 1) actualDamage = 1;

    hp_ -= actualDamage;
    if (hp_ < 0) hp_ = 0;

    cout << name_ << "이(가) " << actualDamage << "의 피해를 입었습니다! (방어력 "
        << defense_ << " 감쇄 / 남은 HP: " << hp_ << " / " << maxHp_ << ")\n";
}

// 경험치 획득
void Player::AddExp(int exp) {
    exp_ += exp;
    cout << exp << " 경험치를 획득했습니다. (현재: " << exp_ << " / " << maxExp_ << ")\n";

    while (exp_ >= maxExp_) {
        exp_ -= maxExp_;
        LevelUp();
    }
}

// 레벨업
void Player::LevelUp() {
    level_++;
    maxExp_ += 25;

    int hpBonus = level_ * 20;
    int attackBonus = level_ * 5;
    int defenseBonus = 2;

    maxHp_ += hpBonus;
    maxMp_ += 10;
    attack_ += attackBonus;
    defense_ += defenseBonus;

    hp_ = maxHp_;
    mp_ = maxMp_;

    cout << "\n★ 레벨 업! (Lv. " << level_ - 1 << " -> Lv. " << level_ << ") ★\n\n";
}

void Player::LevelDown() {
    if (level_ > 1) level_--;
}

void Player::AddGold(int gold) {
    gold_ += gold;
    cout << gold << " 골드를 획득했습니다.\n";
}