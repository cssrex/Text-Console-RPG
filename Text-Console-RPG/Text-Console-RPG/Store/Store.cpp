#include <iostream>
#include <iomanip>
#include "Store.h"
#include "Player.h"
#include "Inventory.h"
#include "SceneAsciiArt.h"
#include "LogManager.h"

using namespace std;

constexpr double SELL_RATE = 0.6; // 판매 가격: 원가의 60%

int Store::GetDisplayWidth(const string& str) const
{
    int width = 0;

    for (int i = 0; i < str.size();)
    {
        unsigned char c = str[i];

        if (c >= 0xE0) // UTF-8 한글
        {
            width += 2;
            i += 3;
        }
        else
        {
            width += 1;
            i += 1;
        }
    }

    return width;
}

void Store::ShowItems() const {
    cout <<
        R"(+======================================================================================================================+
|                                                      구매 목록                                                       |
+======================================================================================================================+
|                                                                                                                      |
)";

    const int BOX_WIDTH = 117;

    for (int i = 0; i < static_cast<int>(items_.size()); i++) {
        string itemInfo = to_string(i + 1) + ". "
            + items_[i]->GetName()
            + ": "
            + to_string(items_[i]->GetPrice())
            + " 골드";

        if (items_[i]->GetType() != ItemType::Equipment) {
            itemInfo += " x " + to_string(items_[i]->GetCount());
        }

        cout << "| " << itemInfo;

        int space = BOX_WIDTH - GetDisplayWidth(itemInfo);

        for (int j = 0; j < space; j++) {
            cout << " ";
        }

        cout << "|\n";
    }
    string back = "0. 돌아가기";

    cout << "| " << back;

    int space = BOX_WIDTH - GetDisplayWidth(back);

    for (int i = 0; i < space; i++) {
        cout << " ";
    }

    cout << "|\n";

    cout << R"(|                                                                                                                      |
+======================================================================================================================+)";
}

// 아이템 구매
bool Store::BuyItem(Player& player, Inventory& inventory, int index) {
    if (index < 0 || index >= static_cast<int>(items_.size())) { // 돌아가기 및 예외처리
        return false;
    }

    Item* item = items_[index].get();
    string name = item->GetName();
    int price = item->GetPrice();

    if (player.GetGold() < price) {
        cout << "골드가 부족합니다.\n";
        return true;
    }
    player.SetGold(player.GetGold() - price);
    cout << price << " 골드를 소모했습니다.\n";
    inventory.AddItem(item->Clone());
    item->RemoveCount(1);

    if (item->GetCount() == 0) {
        items_.erase(items_.begin() + index);
    }
    cout << name << " 구매 완료\n";

    return true;
}

// 아이템 판매
bool Store::SellItem(Player& player, Inventory& inventory, int index) {
    const auto& items = inventory.GetInventory();

    if (index < 0 || index >= static_cast<int>(items.size())) {
        cout << "잘못된 아이템입니다.\n";
        return false;
    }

    Item* item = items[index].get();
    string name = item->GetName();
    int price = static_cast<int>(item->GetPrice() * SELL_RATE);

    if (!inventory.RemoveItem(index, 1)) {
        return false;
    }

    player.AddGold(price);
    cout << name << "을(를) 판매했습니다. (+" << price << " 골드)\n";
    return true;
}

// 판매 메뉴
void Store::SellMenu(Player& player, Inventory& inventory) {
    cout <<
        R"(+======================================================================================================================+
|                                                      판매 목록                                                       |
+======================================================================================================================+
|                                                                                                                      |
)";
    cout << R"(|                               1. 무기               2. 방어구           3. 소모품                                    |
|                                        4. 전리품             0. 돌아가기                                             |
|                                                                                                                      |
+======================================================================================================================+
)";
    cout << "▶ 번호를 입력해주세요 : ";

    int menu;
    cin >> menu;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    int index = -1;

    switch (menu) {
    case 0:
        return;

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

    default:
        cout << "잘못된 입력입니다.\n";
        return;

    }

    if (index != -1) {
        SellItem(player, inventory, index);
    }
}