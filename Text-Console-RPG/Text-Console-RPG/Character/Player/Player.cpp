#include <iostream>
#include <iomanip>

#include "Character.h"
#include "Player.h"
#include "Skill.h"
#include "StatusEffect.h"
#include "LogManager.h"
#include "Inventory.h"
#include "GameSound.h";

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

	// 기본 장비 이름 및 보너스 스탯 초기화
	string weapon = "(없음)", helmet = "(없음)", armor = "(없음)", gloves = "(없음)", boots = "(없음)";
	int bonusAttack = 0;
	int bonusDefense = 0;

	// 착용 중인 장비 맵(map) 순회 및 보너스 계산
	if (inventory != nullptr) {
		const auto& equippedMap = inventory->GetEquipment();

		for (const auto& pair : equippedMap) {
			EquipmentSlot slot = pair.first;
			EquipmentItem* item = pair.second;

			if (item != nullptr) {
				// 보너스 능력치 합산
				bonusAttack += item->GetAttackValue();
				bonusDefense += item->GetDefenseValue();

				// 슬롯별 장비 이름 등록
				switch (slot) {
				case EquipmentSlot::Weapon: weapon = item->GetName(); break;
				case EquipmentSlot::Helmet: helmet = item->GetName(); break;
				case EquipmentSlot::Armor:  armor = item->GetName(); break;
				case EquipmentSlot::Gloves: gloves = item->GetName(); break;
				case EquipmentSlot::Boots:  boots = item->GetName(); break;
				}
			}
		}
	}
	LogManager::GetInstance().PrintPlayerStatus(
		name_, level_, exp_, maxExp_,
		hp_, maxHp_, mp_, maxMp_,
		attack_, defense_,
		bonusAttack, bonusDefense,
		weapon, helmet, armor, gloves, boots
	);

	// 스킬 및 상태이상 목록 출력
	LogManager::GetInstance().PrintSkillListHeader();
	for (size_t i = 0; i < skills_.size(); ++i) {
		LogManager::GetInstance().PrintSkillItem(i + 1, skills_[i]->GetName(), skills_[i]->GetCost(), skills_[i]->GetDescription());
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
    
    LogManager::GetInstance().PrintPlayerHitEffect(actualDamage);

    hp_ -= actualDamage;
    if (hp_ < 0) hp_ = 0;

    if (hp_ == 0) {
        GameSound::PlayPlayerDeathSfx();
    }
    else {
        GameSound::PlayMonsterHitSfx();
    }
    LogManager::GetInstance().PrintPlayerTakeDamage(name_, actualDamage, defense_, hp_, maxHp_);
}

// 경험치 획득
void Player::AddExp(int exp) {
    exp_ += exp;

    GameSound::PlayRewardSfx();
    LogManager::GetInstance().PrintAddExp(exp, exp_, maxExp_);

    while (exp_ >= maxExp_) {
        exp_ -= maxExp_;
        LevelUp();
    }
}

// 레벨업
void Player::LevelUp() {
	GameSound::PlayLevelUpSfx();

    int oldLevel = level_;
    int oldMaxHp = maxHp_;
    int oldMaxMp = maxMp_;
    int oldAttack = attack_;
    int oldDefense = defense_;

    level_++;
    maxExp_ += 25;

    int hpBonus = level_ * hpBonusPerLevel_;
    /*int mpBonus = level_ * mpBonusPerLevel_;*/
    int attackBonus = level_ * attackBonusPerLevel_;
    int defenseBonus = defenseBonusPerLevel_;

    maxHp_ += hpBonus;
   /* maxMp_ += mpBonus;*/
    attack_ += attackBonus;
    defense_ += defenseBonus;

    hp_ = maxHp_;
    mp_ = maxMp_;

    LogManager::GetInstance().PrintLevelUp(oldLevel, level_, oldMaxHp, maxHp_, oldMaxMp, maxMp_,
        oldAttack, attack_, oldDefense, defense_);
}

void Player::LevelDown() {
    if (level_ > 1) {
        level_--;
        exp_ = 0;
        maxExp_ -= 25;

        GameSound::PlayCancelSfx();
        LogManager::GetInstance().PrintLevelDown(level_);
    }
}

void Player::AddGold(int gold) {
    gold_ += gold;

    GameSound::PlayGoldRewardSfx();
    LogManager::GetInstance().PrintAddGold(gold);
}