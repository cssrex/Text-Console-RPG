#include <iostream>
#include <conio.h>
#include "Store.h"
#include "Player.h"
#include "Inventory.h"
#include "SceneAsciiArt.h"
#include "LogManager.h"

using namespace std;


PotionStore::PotionStore() {
    // HP 회복약
    items_.push_back(make_unique<ConsumableItem>("HP 회복약(소)", 3, 20, 100, ItemEffectType::HealHP));
    items_.push_back(make_unique<ConsumableItem>("HP 회복약(중)", 5, 20, 150, ItemEffectType::HealHP));
    items_.push_back(make_unique<ConsumableItem>("HP 회복약(대)", 15, 20, 300, ItemEffectType::HealHP));

    // MP 회복약
    items_.push_back(make_unique<ConsumableItem>("MP 회복약(소)", 3, 20, 100, ItemEffectType::HealMP));
    items_.push_back(make_unique<ConsumableItem>("MP 회복약(중)", 5, 20, 150, ItemEffectType::HealMP));
    items_.push_back(make_unique<ConsumableItem>("MP 회복약(대)", 15, 20, 300, ItemEffectType::HealMP));

    // 엘릭서 (최대 HP, MP 기반 회복)
    items_.push_back(make_unique<ConsumableItem>("엘릭서", 25, 20, 0, ItemEffectType::HealHPMP));
    items_.push_back(make_unique<ConsumableItem>("파워 엘릭서", 50, 10, 0, ItemEffectType::FullRecovery));

    // 상태 이상 해제 물약
    items_.push_back(make_unique<ConsumableItem>("만병통치약", 10, 30, 0, ItemEffectType::Antidote));
}

// 상점 메뉴
void PotionStore::StoreMenu(Player& player, Inventory& inventory) {
    while (true) {
        LogManager::GetInstance().ClearScreen();
        LogManager::GetInstance().PrintPotionStoreMenu();
        cout << "▶ 번호를 입력해주세요 : ";

        int menu;
        cin >> menu;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (menu) {
        case 0:
            return;

        case 1: {
            LogManager::GetInstance().ClearScreen();
            cout << PotionShopAscii;
            ShowItems();
            cout << "▶ 번호를 입력해주세요 : ";

            int index;
            cin >> index;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }

            // 화면 번호 -> vector index
            bool itemBuied = BuyItem(player, inventory, index - 1);
            if (itemBuied == true) {
                cout << "아무 키나 누르면 돌아갑니다.";
                _getch();
            }
            break;
        }

        case 2: {
            LogManager::GetInstance().ClearScreen();
            cout << PotionShopAscii;
            SellMenu(player, inventory);
            break;
        }

        default:
            cout << "잘못된 입력입니다.\n";
            break;
        }
    }
}