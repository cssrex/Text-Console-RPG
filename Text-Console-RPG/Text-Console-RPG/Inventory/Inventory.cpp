#include <iostream>
#include <conio.h>
#include "Inventory.h"
#include "Player.h"
#include "LogManager.h"
#include "SceneAsciiArt.h"

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

	while (true) {
		LogManager::GetInstance().ClearScreen();
		PrintBagIconAsciiArt();
		cout <<
R"(+======================================================================================================================+
|                                                      인벤토리                                                        |
+======================================================================================================================+
|                                                                                                                      |
|                               1. 무기               2. 방어구           3. 소모품                                    |
|                                        4. 전리품             0. 돌아가기                                             |
|                                                                                                                      |
+======================================================================================================================+
)";
		cout << "▶ 번호를 입력해주세요 : ";

		cin >> menu;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "잘못된 입력입니다.\n";
			_getch();
			continue;
		}

		switch (menu) {
		case 0: {
			return false;
		}

		case 1: {
			LogManager::GetInstance().ClearScreen();
			PrintBagIconAsciiArt();

			int index = SelectEquipment(EquipmentType::Weapon);
			if (index != -1) {
				EquipmentMenu(player, index);
			}

			continue;
		}

		case 2: {
			LogManager::GetInstance().ClearScreen();
			PrintBagIconAsciiArt();

			int index = SelectEquipment(EquipmentType::Armor);
			if (index != -1) {
				EquipmentMenu(player, index);
			}

			continue;
		}

		case 3: {
			LogManager::GetInstance().ClearScreen();
			PrintBagIconAsciiArt();

			SelectConsumableInTown();

			continue;
		}

		case 4: {
			LogManager::GetInstance().ClearScreen();
			PrintBagIconAsciiArt();

			SelectLootInTown();

			continue;
		}

		default:
			cout << "잘못된 입력입니다.\n";
			_getch();
		}
	}
}

// 무기/방어구 선택
int Inventory::SelectEquipment(EquipmentType type) {
	vector<int> indexes;

	if (type == EquipmentType::Weapon) {
		cout <<
R"(+======================================================================================================================+
|                                                        무기                                                          |
+======================================================================================================================+
|                                                                                                                      |
)";
	}
	else if (type == EquipmentType::Armor) {
		cout <<
R"(+======================================================================================================================+
|                                                       방어구                                                         |
+======================================================================================================================+
|                                                                                                                      |
)";
	}

	const int BOX_WIDTH = 117;
	int number = 1;

	vector<EquipmentSlot> slots;

	if (type == EquipmentType::Weapon) {
		slots = {EquipmentSlot::Weapon
		};
	}
	else if (type == EquipmentType::Armor) {
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
				string itemInfo = to_string(number) + ". " + equipment->GetName();
				cout << "| " << itemInfo;

				int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(itemInfo);

				for (int j = 0; j < space; j++) { cout << " "; }
				cout << "|\n";
				indexes.push_back(i);
				number++;
			}
		}
	}

	if (indexes.empty()) {
		string emptyMessage;
		if (type == EquipmentType::Weapon) emptyMessage = "보유한 무기가 없습니다.";
		else emptyMessage = "보유한 방어구가 없습니다.";

		cout << "| " << emptyMessage;
		int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(emptyMessage);
		for (int i = 0; i < space; i++) { cout << " "; }
		cout << "|\n";

		cout << "| ";
		for (int i = 0; i < BOX_WIDTH; i++) { cout << " "; }
		cout << "|\n";

		cout <<
			R"(+======================================================================================================================+
)";

		cout << "▶ 아무 키나 입력해주세요. : ";
		_getch();

		return -1;
	}

	string back = "0. 돌아가기";
	cout << "| " << back;
	int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(back);
	for (int i = 0; i < space; i++) { cout << " "; }
	cout << "|\n";

	cout <<
		R"(+======================================================================================================================+
)";

	int select;
	cout << "▶ 번호를 입력해주세요 : ";
	cin >> select;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "잘못된 입력입니다.";
		_getch();

		return -2;
	}

	if (select == 0) return -1;
	if (select < 1 || select > static_cast<int>(indexes.size())) {
		cout << "잘못된 입력입니다.";
		_getch();

		return -2;
	}

	return indexes[select - 1];
}

// 소모품 선택
int Inventory::SelectConsumable() {
	vector<int> indexes;
	cout <<
R"(+======================================================================================================================+
|                                                       소모품                                                         |
+======================================================================================================================+
|                                                                                                                      |
)";

	const int BOX_WIDTH = 117;
	int number = 1;

	// 아이템 출력
	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		if (inventory_[i]->GetType() == ItemType::Consumable) {
			string itemInfo = to_string(number) + ". " + inventory_[i]->GetName() + " x " + to_string(inventory_[i]->GetCount());
			cout << "| " << itemInfo;
			int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(itemInfo);
			for (int j = 0; j < space; j++) cout << " ";
			cout << "|\n";

			indexes.push_back(i);
			number++;
		}
	}

	// 아이템이 없을 때
	if (indexes.empty()) {
		string emptyMessage = "보유한 소모품이 없습니다.";
		cout << "| " << emptyMessage;
		int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(emptyMessage);
		for (int i = 0; i < space; i++) { cout << " "; }
		cout << "|\n";

		cout << "| ";
		for (int i = 0; i < BOX_WIDTH; i++) { cout << " "; }
		cout << "|\n";

		cout <<
			R"(+======================================================================================================================+
)";

		cout << "▶ 아무 키나 입력해주세요. : ";
		_getch();

		return -1;
	}

	string back = "0. 돌아가기";
	cout << "| " << back;
	int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(back);
	for (int i = 0; i < space; i++) { cout << " "; }
	cout << "|\n";

	cout <<
		R"(+======================================================================================================================+
)";

	int select;
	cout << "▶ 번호를 입력해주세요. : ";
	cin >> select;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "잘못된 입력입니다.";
		_getch();

		return -2;
	}

	if (select == 0) return -1;
	if (select < 1 || select > static_cast<int>(indexes.size())) {
		cout << "잘못된 입력입니다.";
		_getch();
		
		return -2;
	}

	return indexes[select - 1];
}

// 전리품 선택
int Inventory::SelectLoot() {
	vector<int> indexes;
	cout <<
R"(+======================================================================================================================+
|                                                       전리품                                                         |
+======================================================================================================================+
|                                                                                                                      |
)";

	const int BOX_WIDTH = 117;
	int number = 1;
	// 아이템 출력
	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		if (inventory_[i]->GetType() == ItemType::Loot) {
			string itemInfo = to_string(number) + ". " + inventory_[i]->GetName() + " x " + to_string(inventory_[i]->GetCount());
			cout << "| " << itemInfo;
			int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(itemInfo);
			for (int j = 0; j < space; j++) cout << " ";
			cout << "|\n";

			indexes.push_back(i);
			number++;
		}
	}

	// 아이템이 없을 때
	if (indexes.empty()) {
		string emptyMessage = "보유한 전리품이 없습니다.";
		cout << "| " << emptyMessage;
		int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(emptyMessage);
		for (int i = 0; i < space; i++) { cout << " "; }
		cout << "|\n";

		cout << "| ";
		for (int i = 0; i < BOX_WIDTH; i++) { cout << " "; }
		cout << "|\n";

		cout <<
			R"(+======================================================================================================================+
)";

		cout << "▶ 아무 키나 입력해주세요. : ";
		_getch();

		return -1;
	}

	string back = "0. 돌아가기";
	cout << "| " << back;
	int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(back);
	for (int i = 0; i < space; i++) { cout << " "; }
	cout << "|\n";

	cout <<
		R"(+======================================================================================================================+
)";

	int select;
	cout << "▶ 번호를 입력해주세요. : ";
	cin >> select;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "잘못된 입력입니다.";
		_getch();

		return -2;
	}

	if (select == 0) return -1;
	if (select < 1 || select > static_cast<int>(indexes.size())) {
		cout << "잘못된 입력입니다.";
		_getch();
		
		return -2;
	}

	return indexes[select - 1];
}

// 장비 착용/해제하기
void Inventory::EquipmentMenu(Player& player, int index) {
	if (index < 0 || index >= static_cast<int>(inventory_.size())) return;

	EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(inventory_[index].get());

	if (equipment == nullptr) {
		cout << "| 장착할 수 없는 아이템입니다.\n";

		return;
	}

	bool equipped = IsEquipped(*equipment);

	LogManager::GetInstance().ClearScreen();
	PrintBagIconAsciiArt();
	cout <<
R"(+======================================================================================================================+
|                                                      장비 정보                                                       |
+======================================================================================================================+
)";

	const int BOX_WIDTH = 117;

	// 장비 이름
	string itemName = "[" + equipment->GetName() + "]";
	cout << "| " << itemName;
	int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(itemName);
	for (int i = 0; i < space; i++) { cout << " "; }
	cout << "|\n";

	cout << "| ";
	for (int i = 0; i < BOX_WIDTH; i++) { cout << " "; }
	cout << "|\n";

	// 메뉴 출력
	string menu1;
	if (equipped)
		menu1 = "1. 해제하기";
	else
		menu1 = "1. 착용하기";

	cout << "| " << menu1;
	space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(menu1);
	for (int i = 0; i < space; i++) { cout << " "; }
	cout << "|\n";

	string menu2 = "2. 돌아가기";
	cout << "| " << menu2;
	space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(menu2);
	for (int i = 0; i < space; i++) { cout << " "; }
	cout << "|\n";

	cout <<
R"(+======================================================================================================================+
)";

	int menu;
	cout << "▶ 번호를 입력해주세요 : ";
	cin >> menu;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "잘못된 입력입니다.";
		_getch();

		return;
	}

	switch (menu) {
	case 1:
		if (equipped) {
			TakeOffEquipment(player,equipment->GetEquipmentSlot());
		}
		else {
			WearEquipment(player,index);
		}
		_getch();

		break;

	case 2:
		return;

	default: {
		cout << "잘못된 입력입니다.";
		_getch();

		break;
	}
	}
}

// 착용 중인 장비인지 검사
bool Inventory::IsEquipped(const EquipmentItem& item) {
	auto it = equipment_.find(item.GetEquipmentSlot());

	if (it == equipment_.end()) return false;

	return it->second == &item;
}

// 전투 - 소모품 사용
bool Inventory::UseConsumable(Player& player, int index) {
	if (index < 0 || index >= static_cast<int>(inventory_.size())) {
		return false;
	}

	ConsumableItem* item = dynamic_cast<ConsumableItem*>(inventory_[index].get());

	if (item == nullptr) {
		return false;
	}

	// 실제 사용 성공 여부
	if (!item->Use(player)) {
		return false;
	}

	// 사용에 성공했을 때만 수량 감소
	item->RemoveCount(1);

	if (item->GetCount() == 0) {
		inventory_.erase(inventory_.begin() + index);
	}

	return true;
}

// 장비 착용
void Inventory::WearEquipment(Player& player, int index) {
	if (index < 0 || index >= static_cast<int>(inventory_.size())) {
		return;
	}

	EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(inventory_[index].get());

	if (equipment == nullptr) {
		return;
	}

	EquipmentSlot slot = equipment->GetEquipmentSlot();

	// 해당 슬롯 장비 착용 중 -> 착용 중 장비 해제 -> 새 장비 착용
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
		return;
	}

	it->second->TakeOff(player);
	equipment_.erase(it);
}

// 인벤토리에서 제거
bool Inventory::RemoveItem(int index, int count) {
	if (index < 0 || index >= static_cast<int>(inventory_.size())) return false;

	Item* item = inventory_[index].get();

	if (item->GetType() == ItemType::Equipment) {
		EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(item);

		if (equipment && IsEquipped(*equipment)) {
			cout << "착용 중인 장비입니다.\n";

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

// 강화용 장비 선택
int Inventory::SelectEquipment(EquipmentSlot slot) {
	vector<int> indexes;

	cout <<
R"(+======================================================================================================================+
|                                                      강화 장비                                                       |
+======================================================================================================================+
|                                                                                                                      |
)";

	const int BOX_WIDTH = 117;
	int number = 1;

	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(inventory_[i].get());

		if (equipment == nullptr) continue;

		if (equipment->GetEquipmentSlot() == slot) {
			string itemInfo = to_string(number) + ". " + equipment->GetName() + " (+" + to_string(equipment->GetEnhanceLevel()) + ")";
			cout << "| " << itemInfo;
			int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(itemInfo);
			for (int j = 0; j < space; j++) cout << " ";
			cout << "|\n";

			indexes.push_back(i);
			number++;
		}
	}

	if (indexes.empty()) {
		string emptyMessage = "강화 가능한 장비가 없습니다.";
		cout << "| " << emptyMessage;
		int space = BOX_WIDTH -	LogManager::GetInstance().GetDisplayWidth(emptyMessage);
		for (int i = 0; i < space; i++) cout << " ";
		cout << "|\n";

		cout <<
R"(|                                                                                                                      |
+======================================================================================================================+
)";
		cout << "▶ 아무 키나 입력해주세요: ";
		_getch();

		return -1;
	}

	cout << "| ";
	for (int i = 0; i < BOX_WIDTH; i++) cout << " ";
	cout << "|\n";
	cout <<
		R"(+======================================================================================================================+
)";

	int select;
	cout << "▶ 번호를 입력해주세요 : ";
	cin >> select;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "잘못된 입력입니다.";
		_getch();

		return -2;
	}

	if (select == 0) return -2;

	if (select < 1 || select > static_cast<int>(indexes.size())) {
		cout << "잘못된 입력입니다.";
		_getch();
		
		return -2;
	}

	return indexes[select - 1];
}

// 재료 아이템 검색 (MaterialType)
int Inventory::FindMaterial(MaterialType type) {
	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		MaterialItem* material = dynamic_cast<MaterialItem*>(inventory_[i].get());

		if (material == nullptr) continue;
		if (material->GetMaterialType() == type) return i;
	}

	return -1;
}

// 재료 아이템 검색 (이름)
int Inventory::FindMaterial(const string& name) {
	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		MaterialItem* material = dynamic_cast<MaterialItem*>(inventory_[i].get());

		if (material == nullptr) continue;
		if (material->GetName() == name) return i;
	}

	return -1;
}

// 전투 중 소모품만 보이는 메뉴
bool Inventory::BattleConsumableMenu(Player& player) {
	vector<int> indexes;
	int number;
	int menu;

	while (true) {
		indexes.clear();
		number = 1;

		cout << "\n=========== 소모품 ============\n\n";

		// 소모품만 출력
		for (int i = 0; i < static_cast<int>(inventory_.size()); ++i) {
			if (inventory_[i]->GetType() != ItemType::Consumable) continue;

			cout << "[" << number << "] " << inventory_[i]->GetName() << " x " << inventory_[i]->GetCount() << "\n";

			indexes.push_back(i);
			number++;
		}

		// 소모품이 없는 경우
		if (indexes.empty()) {
			cout << "보유한 소모품이 없습니다.\n";
			cout << "\n===============================\n\n";
			cout << "▶ 아무 키나 입력해 주세요:";

			_getch();

			return false;
		}

		cout << "\n===============================\n";
		cout << "0. 돌아가기 (취소)\n\n";
		cout << "▶ 선택: ";

		cin >> menu;

		// 문자열 등 잘못된 입력
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "잘못된 입력입니다.\n";
			_getch();

			return false;
		}

		// 취소
		if (menu == 0) {
			return false;
		}

		// 존재하지 않는 메뉴 번호
		if (menu < 1 || menu > static_cast<int>(indexes.size())) {
			cout << "존재하지 않는 아이템입니다.\n";
			_getch();

			return false;
		}

		// 메뉴 번호 → 실제 inventory_ 인덱스
		int index = indexes[menu - 1];

		// 소모품 사용
		bool used = UseConsumable(player, index);
		_getch();

		return used;
	}
}

// 마을 소모품 선택
int Inventory::SelectConsumableInTown() {
	vector<int> indexes;

	cout <<
		R"(+======================================================================================================================+
|                                                       소모품                                                         |
+======================================================================================================================+
|                                                                                                                      |
)";

	const int BOX_WIDTH = 117;
	int number = 1;

	// 아이템 출력
	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		if (inventory_[i]->GetType() == ItemType::Consumable) {
			string itemInfo = to_string(number) + ". " +
				inventory_[i]->GetName() + " x " +
				to_string(inventory_[i]->GetCount());

			cout << "| " << itemInfo;

			int space = BOX_WIDTH -
				LogManager::GetInstance().GetDisplayWidth(itemInfo);

			for (int j = 0; j < space; j++) {
				cout << " ";
			}

			cout << "|\n";

			indexes.push_back(i);
			number++;
		}
	}

	// 아이템이 없을 때
	if (indexes.empty()) {
		string emptyMessage = "보유한 소모품이 없습니다.";

		cout << "| " << emptyMessage;

		int space = BOX_WIDTH -
			LogManager::GetInstance().GetDisplayWidth(emptyMessage);

		for (int i = 0; i < space; i++) {
			cout << " ";
		}

		cout << "|\n";

		cout << "| ";
		for (int i = 0; i < BOX_WIDTH; i++) {
			cout << " ";
		}
		cout << "|\n";

		cout <<
			R"(+======================================================================================================================+
)";

		cout << "▶ 아무 키나 입력해주세요. : ";
		_getch();

		return -1;
	}

	cout <<
		"+======================================================================================================================+\n";

	cout << "▶ 아무 키나 입력해주세요 : ";
	_getch();

	return -1;
}

void Inventory::SelectLootInTown() {
	cout <<
		R"(+======================================================================================================================+
|                                                       전리품                                                         |
+======================================================================================================================+
|                                                                                                                      |
)";

	const int BOX_WIDTH = 117;
	int number = 1;

	// 전리품 출력
	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		if (inventory_[i]->GetType() == ItemType::Loot) {
			string itemInfo = to_string(number) + ". " +
				inventory_[i]->GetName() + " x " +
				to_string(inventory_[i]->GetCount());

			cout << "| " << itemInfo;

			int space = BOX_WIDTH -
				LogManager::GetInstance().GetDisplayWidth(itemInfo);

			for (int j = 0; j < space; j++) {
				cout << " ";
			}

			cout << "|\n";

			number++;
		}
	}

	// 목록 끝
	cout <<
		"+======================================================================================================================+\n";

	cout << "▶ 아무 키나 입력해주세요 : ";
	_getch();
}