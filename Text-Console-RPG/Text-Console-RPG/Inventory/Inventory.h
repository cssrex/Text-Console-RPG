#pragma once

#include <vector>
#include <map>
#include <memory>
#include "Item.h"

using namespace std;

class Player;

class Inventory {
private:
	// 인벤토리 소유
	vector<unique_ptr<Item>> inventory_;

	// 참조 장비 슬롯
	map<EquipmentSlot, EquipmentItem*> equipment_;

public:
	// 아이템 획득
	void AddItem(unique_ptr<Item> item);

	// 인벤토리 메뉴
	void InventoryMenu(Player& player);

	// 아이템 선택
	int SelectEquipment(EquipmentType type);
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
	void TakeOffEquipment(Player& player, EquipmentSlot slot);
	// 착용 중인 장비인지 검사
	bool IsEquipped(const EquipmentItem& item);

	// 인벤토리에서 제거
	bool RemoveItem(int index, int count);

	const vector<unique_ptr<Item>>& GetInventory() const { return inventory_; }

	const map<EquipmentSlot, EquipmentItem*>& GetEquipment() const { return equipment_; }
};