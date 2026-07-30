#include "Inventory.h"
#include "Player.h"

// 아이템 획득
void Inventory::AddItem(const Item& item, int count){
	auto it = find_if(inventory_.begin(), inventory_.end(), [&item](const Item& inventoryItem){return inventoryItem.name_ == item.name_ && inventoryItem.itemType_ == item.itemType_;});

	if (it != inventory_.end()) {
		it->count_ += count;
	}
	else {
		Item newItem = item;
		newItem.count_ = count;
		inventory_.push_back(newItem);
	}
}

// 인벤토리 메뉴
void Inventory::InventoryMenu(Player& player) {
	int menu;
	cout << "===== 인벤토리 =====" << endl;
	cout << "1. 무기" << endl;
	cout << "2. 방어구" << endl;
	cout << "3. 소모품" << endl;
	cout << "4. 전리품" << endl;
	cin >> menu;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		return;
	}

	switch (menu) {
	case 1: {
		int index = SelectWeapon();
		if (index != -1) {
			EquipmentMenu(player, index);
		}
		break;
	}

	case 2: {
		int index = SelectArmor();
		if (index != -1) {
			EquipmentMenu(player, index);
		}
		break;
	}

	case 3: {
		int index = SelectConsumable();
		if (index != -1) {
			UseConsumable(player, index);
		}
		break;
	}

	case 4: {
		int index = SelectLoot();
		if (index != -1) {
			cout << inventory_[index].name_	<< " 판매 가능"	<< endl;
		}
		break;
	}
	}
}

// 무기 선택
int Inventory::SelectWeapon() {
	vector<int> indexes;
	cout << "[ 무기 ]" << endl;
	int number = 1;
	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		if (inventory_[i].itemType_ == ItemType::Weapon) {
			cout << number << ". " << inventory_[i].name_ << endl;
			indexes.push_back(i);
			number++;
		}
	}

	if (indexes.empty()) {
		cout << "보유한 무기가 없습니다." << endl;
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

// 방어구 선택
int Inventory::SelectArmor() {
	vector<int> indexes;
	cout << "[ 방어구 ]" << endl;
	int number = 1;
	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		if (inventory_[i].itemType_ == ItemType::Armor) {
			cout << number << ". " << inventory_[i].name_ << endl;
			indexes.push_back(i);
			number++;
		}
	}

	if (indexes.empty()) {
		cout << "보유한 방어구가 없습니다."	<< endl;
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

// 소모품 선택
int Inventory::SelectConsumable() {
	vector<int> indexes;
	cout << "[ 소모품 ]" << endl;
	int number = 1;
	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		if (inventory_[i].itemType_ == ItemType::Consumable) {
			cout << number << ". " << inventory_[i].name_ << " x " << inventory_[i].count_ << endl;
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
	for (int i = 0; i < static_cast<int>(inventory_.size()); i++) {
		if (inventory_[i].itemType_ == ItemType::Loot) {
			cout << number << ". " << inventory_[i].name_ << " x " << inventory_[i].count_ << endl;
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

	bool equipped = IsEquipped(item);
	const Item& item = inventory_[index];
	cout << endl << "[" << item.name_ << "]" << endl;

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
			for (int i = 0; i < static_cast<int>(equipment_.size()); i++) {
				if (equipment_[i].name_ == item.name_) {
					TakeOffEquipment(player, i);
					break;
				}
			}
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
bool Inventory::IsEquipped(const Item& item) {
	for (const auto& equipment : equipment_) {
		if (equipment.name_ == item.name_) return true;
	}
	return false;
}

// 소모품 사용
void Inventory::UseConsumable(Player& player, int index) {
	if (index < 0 || index >= static_cast<int>(inventory_.size())) {
		cout << "잘못된 아이템입니다." << endl << endl;
		return;
	}

	Item& item = inventory_[index];

	if (item.itemType_ != ItemType::Consumable) {
		cout << "사용할 수 없는 아이템입니다." << endl << endl;
		return;
	}

	switch (item.itemEffectType_) {
	case ItemEffectType::HealHP: {
		if (player.getHp() >= player.getMaxHp()) {
			cout << "HP가 이미 최대치입니다." << endl << endl;
			return;
		}

		int beforeHp = player.getHp();

		player.setHp(min(player.getHp() + item.effectValue_,player.getMaxHp()));

		cout << item.name_ << " 사용 HP " << player.getHp() - beforeHp << " 회복 (" << beforeHp << " -> " << player.getHp() << ")" << endl << endl;

		break;
	}


	case ItemEffectType::HealMP: {
		if (player.getMp() >= player.getMaxMp()) {
			cout << "MP가 이미 최대치입니다." << endl << endl;
			return;
		}

		int beforeMp = player.getMp();

		player.setMp(min(player.getMp() + item.effectValue_, player.getMaxMp()));

		cout << item.name_ << " 사용 MP " << player.getMp() - beforeMp << " 회복 (" << beforeMp << " -> " << player.getMp() << ")" << endl << endl;

		break;
	}


	case ItemEffectType::HealBoth: {
		if (player.getHp() >= player.getMaxHp()	&& player.getMp() >= player.getMaxMp()) {
			cout << "HP와 MP가 이미 최대치입니다."
				<< endl << endl;
			return;
		}

		int beforeHp = player.getHp();
		int beforeMp = player.getMp();

		player.setHp(min(player.getHp() + player.getMaxHp() / 2, player.getMaxHp()));
		player.setMp(min(player.getMp() + player.getMaxMp() / 2, player.getMaxMp()));

		cout << item.name_ << " 사용 HP " << player.getHp() - beforeHp << " 회복, MP " << player.getMp() - beforeMp << " 회복" << endl << endl;

		break;
	}


	case ItemEffectType::FullRecovery: {
		if (player.getHp() >= player.getMaxHp() && player.getMp() >= player.getMaxMp()) {
			cout << "HP와 MP가 이미 최대치입니다."
				<< endl << endl;
			return;
		}

		int beforeHp = player.getHp();
		int beforeMp = player.getMp();

		player.setHp(player.getMaxHp());
		player.setMp(player.getMaxMp());

		cout << item.name_ << " 사용 HP " << player.getHp() - beforeHp << " 회복, MP " << player.getMp() - beforeMp << " 회복" << endl << endl;

		break;
	}

	default:
		cout << "사용할 수 없는 아이템입니다." << endl << endl;
		return;
	}

	// 사용 성공
	item.count_--;
	if (item.count_ == 0)
	{
		inventory_.erase(inventory_.begin() + index);
	}
}

// 장비 착용
void Inventory::WearEquipment(Player& player, int index) {
	if (index < 0 || index >= static_cast<int>(inventory_.size())) {
		cout << "잘못된 장비입니다." << endl;
		return;
	}

	const Item& item = inventory_[index];

	if (item.itemType_ != ItemType::Weapon && item.itemType_ != ItemType::Armor) {
		cout << "장착할 수 없는 아이템입니다." << endl;
		return;
	}

	if (IsEquipped(item))
	{
		cout << "이미 착용 중인 장비입니다." << endl;
		return;
	}

	equipment_.push_back(item);

	// 능력치 증가
	if (item.itemType_ == ItemType::Weapon) {
		player.SetPower(player.GetPower() + item.powerValue_);
	}
	else if (item.itemType_ == ItemType::Armor) {
		player.SetDefense(player.GetDefense() + item.defenseValue_);
	}
	cout << item.name_ << " 장착" << endl << endl;
}

// 장비 해제
void Inventory::TakeOffEquipment(Player& player, int index) {
	if (index < 0 || index >= static_cast<int>(equipment_.size())) {
		cout << "잘못된 장비입니다." << endl << endl;
		return;
	}

	const Item& item = equipment_[index];

	// 능력치 감소
	if (item.itemType_ == ItemType::Weapon) {
		player.SetPower(player.GetPower() - item.powerValue_);
	}
	else if (item.itemType_ == ItemType::Armor){
		player.SetDefense(player.GetDefense() - item.defenseValue_);
	}

	cout << item.name_ << " 해제" << endl << endl;
	equipment_.erase(equipment_.begin() + index);
}

// 인벤토리에서 제거
void Inventory::RemoveItem(int index, int count){
	if (index < 0 || index >= static_cast<int>(inventory_.size())) return;

	Item& item = inventory_[index];

	// 제거할 개수가 현재 보유 개수보다 많으면 전부 제거
	if (count >= item.count_) {
		inventory_.erase(inventory_.begin() + index);
	}
	else {
		item.count_ -= count;
	}
}