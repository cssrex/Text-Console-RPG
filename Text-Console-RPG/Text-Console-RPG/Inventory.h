#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum class ItemType {
	Loot,
	Consumable,
	Weapon,
	Armor
};

enum class ItemEffectType {
	None,

	// 회복
	HealHP,
	HealMP,
	HealBoth,
	FullRecovery,

	// 강화
	EnhanceStone
};

struct Item {
	string name_;
	int price_ = 0;
	int count_ = 0;

	ItemType itemType_ = ItemType::Loot;

	// 소모품
	int effectValue_ = 0;
	ItemEffectType itemEffectType_ = ItemEffectType::None;

	// 장비
	int powerValue_ = 0;
	int defenseValue_ = 0;
};

class Player;

class Inventory {
private:
	vector<Item> inventory_;
	vector<Item> equipment_;

public:
	// 아이템 획득
	void AddItem(const Item& item, int count);

	// 인벤토리 메뉴
	void InventoryMenu(Player& player);

	// 아이템 선택
	int SelectWeapon();
	int SelectArmor();
	int SelectConsumable();
	int SelectLoot();

	// 장비 상세 메뉴
	void EquipmentMenu(Player& player, int index);

	// 소모품 사용
	void UseConsumable(Player& player, int index);
	// 강화석 사용
	void UseEnhanceStone(Player& player);

	// 장비 착용
	void WearEquipment(Player& player, int index);
	// 장비 해제
	void TakeOffEquipment(Player& player, int index);

	bool IsEquipped(const Item& item);

	const vector<Item>& GetInventory() const {
		return inventory_;
	}

	const vector<Item>& GetEquipment() const {
		return equipment_;
	}
};
#endif