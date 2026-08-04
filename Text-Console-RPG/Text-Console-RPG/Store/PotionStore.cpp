#include <iostream>
#include <conio.h>
#include "Store.h"
#include "Player.h"
#include "Inventory.h"
#include "SceneAsciiArt.h"
#include "LogManager.h"
#include "Enums.h"

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

    // 엘릭서
    items_.push_back(make_unique<ConsumableItem>("엘릭서", 25, 20, 0, ItemEffectType::HealHPMP));
    items_.push_back(make_unique<ConsumableItem>("파워 엘릭서", 50, 10, 0, ItemEffectType::FullRecovery));

    // 상태 이상 해제 물약
    items_.push_back(make_unique<ConsumableItem>("만병통치약", 10, 30, 0, ItemEffectType::Antidote));
}


// 상점 메뉴
void PotionStore::StoreMenu(Player& player, Inventory& inventory) {
    const int BOX_WIDTH = 117;

    while (true)
    {
        LogManager::GetInstance().ClearScreen();
        LogManager::GetInstance().PrintPotionStoreMenu();


        cout << "▶ 번호를 입력해주세요 : ";
        int menu;
        cin >> menu;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "잘못된 입력입니다.";
            _getch();

            continue;
        }



        switch (menu)
        {
        case 0:
            return;



        case 1:
        {
            LogManager::GetInstance().ClearScreen();
            cout << PotionShopAscii;


            cout <<
                R"(+======================================================================================================================+
|                                                      구매 목록                                                       |
+======================================================================================================================+
|                                                                                                                      |
)";


            string goldText =
                "골드 : " + to_string(player.GetGold());


            cout << "| " << goldText;


            int space =
                BOX_WIDTH -
                LogManager::GetInstance().GetDisplayWidth(goldText);


            for (int i = 0; i < space; i++)
                cout << " ";


            cout << "|\n";


            cout << "| ";

            for (int i = 0; i < BOX_WIDTH; i++)
                cout << " ";

            cout << "|\n";


            ShowItems();


            cout << "▶ 번호를 입력해주세요 : ";


            int index;

            cin >> index;


            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "잘못된 입력입니다." << endl;

                _getch();

                break;
            }


            if (index == 0)
            {
                break;
            }



            BuyResult result =
                BuyItem(
                    player,
                    inventory,
                    index - 1
                );



            switch (result)
            {
            case BuyResult::Success:

                cout << "아이템 구매가 완료되었습니다." << endl;

                break;


            case BuyResult::NotEnoughGold:

                cout << "골드가 부족합니다." << endl;

                break;


            case BuyResult::InvalidItem:

                cout << "존재하지 않는 아이템입니다." << endl;

                break;
            }


            _getch();

            break;
        }



        case 2:
        {
            LogManager::GetInstance().ClearScreen();
            cout << PotionShopAscii;

            SellMenu(
                player,
                inventory,
                PotionShopAscii
            );


            break;
        }



        default:

            cout << "잘못된 입력입니다." << endl;

            _getch();

            break;
        }
    }
}