#include <iostream>
#include "Inventory.h"
#include "Player.h"

// 아이템 획득
void Inventory::AddItem(unique_ptr<Item> item) {
	// 장비는 개수 안 합쳐짐
	if (item->GetType() == ItemType::Equipment) {
		inventory_.push_back(move(item));
		return;
	}

	// 같은 이름의 아이템이 있으면 개수 합치기
	for (auto& inventoryItem : inventory_) {
		if (inventoryItem->GetName() == item->GetName()) {
			inventoryItem->AddCount(item->GetCount());
			return;
		}
	}

	// 새로운 아이템 추가
	inventory_.push_back(move(item));
}

// 인벤토리 메뉴
bool Inventory::InventoryMenu(Player& player) {
	int menu;
	cout << "===== 인벤토리 =====" << endl;
	cout << "1. 무기" << endl;
	cout << "2. 방어구" << endl;
	cout << "3. 소모품" << endl;
	cout << "4. 전리품" << endl;
	cout << "0. 돌아가기" << endl;
	cin >> menu;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		return false;
	}

	switch (menu) {
	case 0: {
		return false;
	}
	case 1: {
		int index = SelectEquipment(EquipmentType::Weapon);
		if (index != -1) {
			EquipmentMenu(player, index);
		}
		return true;
	}

	case 2: {
		int index = SelectEquipment(EquipmentType::Armor);
		if (index != -1) {
			EquipmentMenu(player, index);
		}
		return true;
	}

	case 3: {
		int index = SelectConsumable();
		if (index != -1) {
			UseConsumable(player, index);
		}
		return true;
	}

	case 4: {
		int index = SelectLoot();
		if (index != -1) {
			cout << inventory_[index]->GetName() << endl;
		}
		return true;
	}

	default:
		return false;
	}
}

// 무기/방어구 선택
int Inventory::SelectEquipment(EquipmentType type) {
	vector<int> indexes;
	if (type == EquipmentType::Weapon) cout << "[ 무기 ]" << endl;
	else if (type == EquipmentType::Armor) cout << "[ 방어구 ]" << endl;

	int number = 1;

	// slot 순서로 순회
	vector<EquipmentSlot> slots;
	if (type == EquipmentType::Weapon)
	{
		slots = {
			EquipmentSlot::Weapon
		};
	}
	else if (type == EquipmentType::Armor)
	{
		slots = {
			EquipmentSlot::Helmet,
			EquipmentSlot::Armor,
			EquipmentSlot::Gloves,
			EquipmentSlot::Boots
		};
	}

	for (auto slot : slots) {
		for (int i = 0; i < static_cast<int>(inventory_.size()); ++i) {
			if (inventory_[i]->GetType() != ItemType::Equipment) continue;

			EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(inventory_[i].get());

			if (equipment == nullptr) continue;

			if (equipment->GetEquipmentType() == type && equipment->GetEquipmentSlot() == slot) {
				cout << number << ". " << equipment->GetName() << endl;
				indexes.push_back(i);
				number++;
			}
		}
	}

	if (indexes.empty()) {
		if (type == EquipmentType::Weapon) cout << "보유한 무기가 없습니다." << endl;
		else cout << "보유한 방어구가 없습니다." << endl;

		return -1;
	}

	int select;
	cout << "번호 선택 : ";
	cin >> select;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		return -1;
	}

	if (select < 1 || select > static_cast<int>(indexes.size())) {
		return -1;
	}

	return indexes[select - 1];
}

// 소모품 선택
int Inventory::SelectConsumable() {
	vector<int> indexes;
	cout << "[ 소모품 ]" << endl;
	int number = 1;
	for (int i = 0; i < static_cast<int>(inventory_.size()); ++i) {
		if (inventory_[i]->GetType() == ItemType::Consumable) {
			cout << number << ". " << inventory_[i]->GetName() << " x " << inventory_[i]->GetCount() << endl;
			indexes.push_back(i);
			number++;
		}
	}

	if (indexes.empty()) {
		cout << "소모품이 없습니다." << endl;
		return -1;
	}

	int select;
	cout << "번호 선택 : ";
	cin >> select;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		return -1;
	}

	if (select < 1 || select > static_cast<int>(indexes.size())) return -1;
	return indexes[select - 1];
}

// 전리품 선택
int Inventory::SelectLoot() {
	vector<int> indexes;
	cout << "[ 전리품 ]" << endl;
	int number = 1;
	for (int i = 0; i < static_cast<int>(inventory_.size()); ++i) {
		if (inventory_[i]->GetType() == ItemType::Loot) {
			cout << number << ". " << inventory_[i]->GetName() << " x " << inventory_[i]->GetCount() << endl;
			indexes.push_back(i);
			number++;
		}
	}

	if (indexes.empty())
	{
		cout << "전리품이 없습니다." << endl;
		return -1;
	}

	int select;
	cout << "번호 선택 : ";
	cin >> select;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		return -1;
	}

	if (select < 1 || select > static_cast<int>(indexes.size())) return -1;
	return indexes[select - 1];
}

// 장비 착용/해제하기
void Inventory::EquipmentMenu(Player& player, int index) {
	if (index < 0 || index >= static_cast<int>(inventory_.size())) return;

	EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(inventory_[index].get());
	if (equipment == nullptr) {
		cout << "장착할 수 없는 아이템입니다." << endl;
		return;
	}

	bool equipped = IsEquipped(*equipment);
	cout << "[" << equipment->GetName() << "]" << endl;

	if (equipped) {
		cout << "1. 해제하기" << endl;
	}
	else {
		cout << "1. 착용하기" << endl;
	}
	cout << "2. 돌아가기" << endl;

	int menu;
	cin >> menu;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		return;
	}

	if (menu < 1 || menu > 2)
	{
		cout << "잘못된 입력입니다." << endl;
		return;
	}

	switch (menu) {
	case 1:
		if (equipped) {
			TakeOffEquipment(player, equipment->GetEquipmentSlot());
		}
		else {
			WearEquipment(player, index);
		}
		break;
	case 2:
		return;
	}
}

// 착용 중인 장비인지 검사
bool Inventory::IsEquipped(const EquipmentItem& item) {
	auto it = equipment_.find(item.GetEquipmentSlot());

	if (it == equipment_.end()) return false;

	return it->second == &item;
}

// 소모품 사용
void Inventory::UseConsumable(Player& player, int index) {
	if (index < 0 || index >= static_cast<int>(inventory_.size())) {
		cout << "잘못된 아이템입니다." << endl << endl;
		return;
	}

	ConsumableItem* item = dynamic_cast<ConsumableItem*>(inventory_[index].get());

	if (item == nullptr) {
		cout << "사용할 수 없는 아이템입니다." << endl << endl;
		return;
	}

	if (item->Use(player)) {
		item->RemoveCount(1);

		if (item->GetCount() == 0) inventory_.erase(inventory_.begin() + index);
	}
}

// 장비 착용
void Inventory::WearEquipment(Player& player, int index) {
	if (index < 0 || index >= static_cast<int>(inventory_.size())) {
		cout << "잘못된 장비입니다." << endl;
		return;
	}

	EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(inventory_[index].get());

	if (equipment == nullptr) {
		cout << "장착할 수 없는 아이템입니다." << endl;
		return;
	}

	EquipmentSlot slot = equipment->GetEquipmentSlot();

	// 착용 중 장비 해제
	auto it = equipment_.find(slot);

	if (it != equipment_.end()) {
		it->second->TakeOff(player);
		equipment_.erase(it);
	}

	equipment_[slot] = equipment;
	equipment->Equip(player);
}

// 장비 해제
void Inventory::TakeOffEquipment(Player& player, EquipmentSlot slot) {
	auto it = equipment_.find(slot);

	if (it == equipment_.end()) {
		cout << "착용한 장비가 없습니다." << endl;
		return;
	}

	it->second->TakeOff(player);
	equipment_.erase(it);
}

// 인벤토리에서 제거
bool Inventory::RemoveItem(int index, int count){
	if (index < 0 || index >= static_cast<int>(inventory_.size())) return false;

	Item* item = inventory_[index].get();

	if (item->GetType() == ItemType::Equipment) {
		EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(item);

		if (equipment && IsEquipped(*equipment)) {
			cout << "착용 중인 장비입니다." << endl;
			return false;
		}
	}

	// 제거할 개수가 현재 보유 개수보다 많으면 전부 제거
	if (count >= item->GetCount()) {
		inventory_.erase(inventory_.begin() + index);
	}
	else {
		item->RemoveCount(count);
	}

	return true;
}