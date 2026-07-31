#include <iostream>
#include "Store.h"
#include "Player.h"
#include "Inventory.h"

using namespace std;


PotionStore::PotionStore()
{
    items_.push_back(
        make_unique<ConsumableItem>(
            "HP 회복약(소)",
            3,
            20,
            100,
            ItemEffectType::HealHP
        )
    );

    items_.push_back(
        make_unique<ConsumableItem>(
            "HP 회복약(중)",
            5,
            20,
            150,
            ItemEffectType::HealHP
        )
    );

    items_.push_back(
        make_unique<ConsumableItem>(
            "HP 회복약(대)",
            15,
            20,
            300,
            ItemEffectType::HealHP
        )
    );


    items_.push_back(
        make_unique<ConsumableItem>(
            "MP 회복약(소)",
            3,
            20,
            100,
            ItemEffectType::HealMP
        )
    );

    items_.push_back(
        make_unique<ConsumableItem>(
            "MP 회복약(중)",
            5,
            20,
            150,
            ItemEffectType::HealMP
        )
    );

    items_.push_back(
        make_unique<ConsumableItem>(
            "MP 회복약(대)",
            15,
            20,
            300,
            ItemEffectType::HealMP
        )
    );


    // 최대 HP 기반 효과는 아이템 사용 시 계산
    items_.push_back(
        make_unique<ConsumableItem>(
            "엘릭서",
            25,
            20,
            0,
            ItemEffectType::HealHPMP
        )
    );

    items_.push_back(
        make_unique<ConsumableItem>(
            "파워 엘릭서",
            50,
            10,
            0,
            ItemEffectType::FullRecovery
        )
    );

    items_.push_back(
        make_unique<ConsumableItem>(
            "만병통치약",
            10,
            30,
            0,
            ItemEffectType::Antidote
        )
    );
}


void PotionStore::StoreMenu(Player& player, Inventory& inventory)
{
    while (true)
    {
        cout << endl;
        cout << "===== 포션 상점 =====" << endl;
        cout << "1. 구매" << endl;
        cout << "2. 판매" << endl;
        cout << "3. 나가기" << endl;
        cout << "선택 : ";

        int menu;
        cin >> menu;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }


        switch (menu)
        {
        case 1:
        {
            ShowItems();

            cout << "구매할 아이템 : ";

            int index;
            cin >> index;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }

            // 화면 번호 -> vector index
            BuyItem(player, inventory, index - 1);

            break;
        }


        case 2:
        {
            cout << "판매할 아이템" << endl;
            cout << "1. 무기" << endl;
            cout << "2. 방어구" << endl;
            cout << "3. 소모품" << endl;
            cout << "4. 전리품" << endl;

            int sellType;
            cin >> sellType;

            int index = -1;

            switch (sellType)
            {
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


            if (index != -1)
            {
                SellItem(player, inventory, index);
            }

            break;
        }


        case 3:
            return;


        default:
            cout << "잘못된 입력입니다." << endl;
            break;
        }
    }
}