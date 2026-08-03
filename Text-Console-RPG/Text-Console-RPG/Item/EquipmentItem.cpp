#include "Item.h"
#include "Player.h"
#include "LogManager.h"
#include <iostream>

using namespace std;

void EquipmentItem::Equip(Player& player) {
	auto PrintMessage = [](const string& message) {
			const int BOX_WIDTH = 117;

			cout << "| " << message;
			int space =	BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(message);

			for (int i = 0; i < space; i++)	cout << " ";
			cout << "|\n";
		};

	switch (equipmentType_) {
	case EquipmentType::Weapon:
		player.SetAttack(player.GetAttack() + attackValue_);
		break;

	case EquipmentType::Armor:
		player.SetDefense(player.GetDefense() + defenseValue_);
		player.SetMaxHp(player.GetMaxHp() + healthValue_);
		break;

	default:
		PrintMessage("잘못된 장비 타입입니다.");
		break;
	}
}

void EquipmentItem::TakeOff(Player& player) {
	auto PrintMessage = [](const string& message) {
			const int BOX_WIDTH = 117;

			cout << "| " << message;
			int space =	BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(message);

			for (int i = 0; i < space; i++) cout << " ";
			cout << "|\n";
		};

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
		PrintMessage("잘못된 장비 타입입니다.");
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