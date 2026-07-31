#include "Item.h"
#include "Player.h"

void EquipmentItem::Equip(Player& player) {
    switch (equipmentType_) {
    case EquipmentType::Weapon:
        player.SetAttack(player.GetAttack() + attackValue_);

        break;

    case EquipmentType::Armor:
        player.SetDefense(player.GetDefense() + defenseValue_);

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

        break;

    default:
        cout << "잘못된 장비 타입입니다." << endl;
        break;
    }
}