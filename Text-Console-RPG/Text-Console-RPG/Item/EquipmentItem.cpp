#include "Item.h"
#include "Player.h"
#include "LogManager.h"
#include <iostream>

using namespace std;

void EquipmentItem::Equip(Player& player) {
    cout << "\n" << name_ + "을(를) 착용했습니다.\n";

    switch (equipmentType_) {
    case EquipmentType::Weapon:
        player.SetAttack(player.GetAttack() + attackValue_);
        cout << "공격력 +" + to_string(attackValue_) << "증가!\n";

        break;

    case EquipmentType::Armor:
        player.SetDefense(player.GetDefense() + defenseValue_);
        player.SetMaxHp(player.GetMaxHp() + healthValue_);

        if (defenseValue_ > 0) {
            cout << "방어력 +" + to_string(defenseValue_) << "증가!\n";
        }
        if (healthValue_ > 0) {
            cout << "최대 HP +" + to_string(healthValue_) << "증가!\n";
        }

        break;

    default:
        cout << "잘못된 장비 타입입니다.\n";
        break;
    }
}

void EquipmentItem::TakeOff(Player& player) {
    cout << "\n" << name_ + "을(를) 해제했습니다.\n";

    switch (equipmentType_) {
    case EquipmentType::Weapon:
        player.SetAttack(player.GetAttack() - attackValue_);
        cout << "공격력 -" + to_string(attackValue_) << "감소!\n";

        break;

    case EquipmentType::Armor:
        player.SetDefense(player.GetDefense() - defenseValue_);
        player.SetMaxHp(player.GetMaxHp() - healthValue_);

        if (player.GetHp() > player.GetMaxHp()) {
            player.SetHp(player.GetMaxHp());
        }

        if (defenseValue_ > 0) {
            cout << "방어력 -" + to_string(defenseValue_) << "감소!\n";
        }
        if (healthValue_ > 0) {
            cout << "최대 HP -" + to_string(healthValue_) << "감소!\n";
        }

        break;

    default:
        cout << "잘못된 장비 타입입니다.\n";

        break;
    }
}

void EquipmentItem::Enhance() {
	enhanceLevel_++;
	double rate = 1.0 + (0.1 * enhanceLevel_);

	attackValue_ = static_cast<int>(baseAttackValue_ * rate);
	defenseValue_ = static_cast<int>(baseDefenseValue_ * rate);
	healthValue_ = static_cast<int>(baseHealthValue_ * rate);
}