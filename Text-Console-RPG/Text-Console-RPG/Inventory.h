#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Enums.h"
#include "Item.h"

using namespace std;

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

	// 착용 중인 장비인지 검사
	bool IsEquipped(const Item& item);

	// 인벤토리에서 제거
	void RemoveItem(int index, int count);

	const vector<Item>& GetInventory() const {
		return inventory_;
	}

	const vector<Item>& GetEquipment() const {
		return equipment_;
	}
};
#endif