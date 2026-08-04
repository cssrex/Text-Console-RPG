#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Store.h"
#include "Player.h"
#include "Inventory.h"
#include "SceneAsciiArt.h"
#include "LogManager.h"

using namespace std;

constexpr double SELL_RATE = 0.6;

// 아이템 출력
void Store::ShowItems() const {
    const int BOX_WIDTH = 117;
    for (int i = 0; i < static_cast<int>(items_.size()); i++) {
        string itemInfo = to_string(i + 1) + ". " + items_[i]->GetName() + ": " + to_string(items_[i]->GetPrice()) + " 골드";

        if (items_[i]->GetType() != ItemType::Equipment) {
            itemInfo += " x " + to_string(items_[i]->GetCount());
        }

        cout << "| " << itemInfo;
        int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(itemInfo);
        for (int j = 0; j < space; j++) cout << " ";
        cout << "|\n";
    }

    string back = "0. 돌아가기";
    cout << "| " << back;
    int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(back);
    for (int i = 0; i < space; i++) cout << " ";
    cout << "|\n";

    cout <<
        "+======================================================================================================================+\n";
}

// 아이템 구매
BuyResult Store::BuyItem(Player& player, Inventory& inventory, int index) {
    if (index < 0 || index >= static_cast<int>(items_.size())) {
        return BuyResult::InvalidItem;
    }

    Item* item = items_[index].get();
    int price = item->GetPrice();

    if (player.GetGold() < price) {
        return BuyResult::NotEnoughGold;
    }

    player.SetGold(player.GetGold() - price);
    inventory.AddItem(item->Clone());
    item->RemoveCount(1);

    if (item->GetCount() == 0) {
        items_.erase(items_.begin() + index);
    }

    return BuyResult::Success;
}

// 아이템 판매
bool Store::SellItem(Player& player, Inventory& inventory, int index) {
    const auto& items = inventory.GetInventory();

    if (index < 0 || index >= static_cast<int>(items.size())) {
        cout << "존재하지 않는 아이템입니다." << endl;
        _getch();
        return false;
    }

    Item* item = items[index].get();
    string name = item->GetName();
    int price = static_cast<int>(item->GetPrice() * SELL_RATE);

    if (!inventory.RemoveItem(index, 1)) {
        _getch();
        return false;
    }

    player.AddGold(price);
    cout << name << "을(를) 판매했습니다. (+" << price << " 골드)" << endl;
    _getch();

    return true;
}

// 판매 메뉴
void Store::SellMenu(Player& player, Inventory& inventory, const string& ascii) {
    while (true) {
        const int BOX_WIDTH = 117;

        LogManager::GetInstance().ClearScreen();

        cout << ascii;
        cout <<
R"(+======================================================================================================================+
|                                                      판매 목록                                                       |
+======================================================================================================================+
|                                                                                                                      |
|                               1. 무기               2. 방어구             3. 소모품                                  |
|                                         4. 전리품             0. 돌아가기                                            |
|                                                                                                                      |
+======================================================================================================================+
)";

        cout << "▶ 번호를 입력해주세요 : ";

        int menu;
        cin >> menu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "잘못된 입력입니다." << endl;
            _getch();

            continue;
        }

        int index = -1;

        switch (menu) {
        case 0:
            return;

        case 1:
            while (true) {
                LogManager::GetInstance().ClearScreen();
                cout << ascii;

                index = inventory.SelectEquipment(EquipmentType::Weapon);

                if (index == -1) {
                    break;
                }

                if (index == -2) {
                    continue;
                }

                SellItem(player, inventory, index);
            }
            break;

        case 2:
            while (true) {
                LogManager::GetInstance().ClearScreen();
                cout << ascii;

                index = inventory.SelectEquipment(EquipmentType::Armor);

                if (index == -1) {
                    break;
                }

                if (index == -2) {
                    continue;
                }

                SellItem(player, inventory, index);
            }
            break;

        case 3:
            while (true) {
                LogManager::GetInstance().ClearScreen();
                cout << ascii;

                index = inventory.SelectConsumable();

                if (index == -1) {
                    break;
                }

                if (index == -2) {
                    continue;
                }

                SellItem(player, inventory, index);
            }
            break;

        case 4:
            while (true) {
                LogManager::GetInstance().ClearScreen();
                cout << ascii;

                index = inventory.SelectLoot();

                if (index == -1) {
                    break;
                }

                if (index == -2) {
                    continue;
                }

                SellItem(player, inventory, index);
            }
            break;

        default:
            cout << "잘못된 입력입니다." << endl;
            _getch();
            continue;
        }

        if (index >= 0) {
            SellItem(player, inventory, index);
        }
    }
}