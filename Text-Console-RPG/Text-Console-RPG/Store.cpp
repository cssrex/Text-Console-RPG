#include <iostream>
#include "Store.h"
#include "Player.h"
#include "Inventory.h"

using namespace std;

constexpr double SELL_RATE = 0.6; // 판매 가격: 원가의 60%

void Store::ShowItems() const {
    cout << "===== 구매 =====" << endl;

    for (int i = 0; i < static_cast<int>(items_.size()); i++) {
        cout << i + 1 << ". " << items_[i]->GetName() << " : " << items_[i]->GetPrice() << "골드" << endl;
    }
}

// 아이템 구매
void Store::BuyItem(Player& player, Inventory& inventory, int index) {
    if (index < 0 || index >= static_cast<int>(items_.size())) return;

    Item* item = items_[index].get();

    if (player.GetGold() < item->GetPrice()) {
        cout << "골드가 부족합니다." << endl;
        return;
    }
    string name = item->GetName();
    player.AddGold(-item->GetPrice());
    inventory.AddItem(item->Clone());
    item->RemoveCount(1);

    if (item->GetCount() == 0) {
        items_.erase(items_.begin() + index);
    }
    cout << name << " 구매 완료" << endl;
}

// 아이템 판매
bool Store::SellItem(Player& player, Inventory& inventory, int index) {
    const auto& items = inventory.GetInventory();

    if (index < 0 || index >= static_cast<int>(items.size())) {
        cout << "잘못된 아이템입니다." << endl;
        return;
    }

    Item* item = items[index].get();
    string name = item->GetName();
    int price = static_cast<int>(item->GetPrice() * SELL_RATE);

    if (!inventory.RemoveItem(index, 1)) {
        return false;
    }

    player.AddGold(price);
    cout << name << "을(를) 판매했습니다. (+" << price << " 골드)" << endl;

    return true;
}

// 판매 메뉴
void Store::SellMenu(Player& player, Inventory& inventory) {
    cout << "판매할 아이템" << endl;
    cout << "1. 무기" << endl;
    cout << "2. 방어구" << endl;
    cout << "3. 소모품" << endl;
    cout << "4. 전리품" << endl;

    int menu;
    cin >> menu;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    int index = -1;

    switch (menu) {
    case 1:
        index = inventory.SelectEquipment(EquipmentType::Weapon);
        break;

    case 2:
        index = inventory.SelectEquipment(EquipmentType::Armor);
        break;

    case 3:
        index = inventory.SelectConsumable();
        break;

    case 4:
        index = inventory.SelectLoot();
        break;
    }

    if (index != -1) {
        SellItem(player, inventory, index);
    }
}