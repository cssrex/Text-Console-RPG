#include <iostream>
#include "Store.h"
#include "Player.h"
#include "Inventory.h"

using namespace std;

Blacksmith::Blacksmith()
{
    // 판매 아이템 목록
    items_.push_back(make_unique<EquipmentItem>("낡은 검", 100, 1, 10, 0, EquipmentType::Weapon, EquipmentSlot::Weapon));
    items_.push_back(make_unique<EquipmentItem>("가죽 갑옷", 100, 1, 0, 15, EquipmentType::Armor, EquipmentSlot::Armor));
}

void Blacksmith::StoreMenu(Player& player, Inventory& inventory) {
    while (true) {
        cout << "===== 대장간 =====" << endl;
        cout << "1. 장비 구매" << endl;
        cout << "2. 장비 판매" << endl;
        cout << "3. 무기 강화" << endl;
        cout << "4. 나가기" << endl;

        int menu;
        cin >> menu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (menu) {
        case 1:
        {
            int index = SelectItem();
            if (index != -1)
                BuyItem(player, inventory, index);
            break;
        }

        case 2: {
            int index = inventory.SelectEquipmentForSell();

            if (index != -1)
                SellItem(player, inventory, index);

            break;
        }

        case 3:
            Enhance(player, inventory);
            break;

        case 4:
            return;

        default:
            cout << "잘못된 입력입니다." << endl;
            break;
        }
    }
}

void Blacksmith::Enhance(Player& player, Inventory& inventory) {

}