#include "Item.h"
#include "Player.h"
#include <iostream>

void EquipmentItem::Equip(Player& player) {
    switch (equipmentType_) {
    case EquipmentType::Weapon:
        player.SetAttack(player.GetAttack() + attackValue_);

        break;

    case EquipmentType::Armor:
        player.SetDefense(player.GetDefense() + defenseValue_);
        player.SetMaxHp(player.GetMaxHp() + healthValue_);

        break;

    default:
        cout << "잘못된 장비 타입입니다." << endl;
        break;
    }
}

void EquipmentItem::TakeOff(Player& player) {
    switch (equipmentType_) {
    case EquipmentType::Weapon:
        player.SetAttack(player.GetAttack() - attackValue_);
        break;

    case EquipmentType::Armor:
        player.SetDefense(player.GetDefense() - defenseValue_);
        player.SetMaxHp(player.GetMaxHp() - healthValue_);
        if (player.GetHp() > player.GetMaxHp()) {
            player.SetHp(player.GetMaxHp());
        }

        break;

    default:
        cout << "잘못된 장비 타입입니다." << endl;
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