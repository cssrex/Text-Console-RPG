#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "Store.h"
#include "Player.h"
#include "Inventory.h"
#include "LogManager.h"
#include "SceneAsciiArt.h"

using namespace std;

Blacksmith::Blacksmith()
{
    // 강화석
    items_.push_back(make_unique<MaterialItem>("강화석(SR)", 30, 30, MaterialType::EnhanceStone));
    items_.push_back(make_unique<MaterialItem>("강화석(SSR)", 50, 30, MaterialType::EnhanceStone));
    items_.push_back(make_unique<MaterialItem>("강화석(U)", 100, 30, MaterialType::EnhanceStone));

    // 무기
    items_.push_back(make_unique<EquipmentItem>("나무 검", 0, 1, 10, 0, 0, 0, EquipmentType::Weapon, EquipmentSlot::Weapon));
    items_.push_back(make_unique<EquipmentItem>("킹슬레이어", 100, 1, 25, 0, 0, 0, EquipmentType::Weapon, EquipmentSlot::Weapon));
    items_.push_back(make_unique<EquipmentItem>("아론다이트", 300, 1, 50, 0, 0, 0, EquipmentType::Weapon, EquipmentSlot::Weapon));
    items_.push_back(make_unique<EquipmentItem>("엑스칼리버", 500, 1, 100, 0, 0, 0, EquipmentType::Weapon, EquipmentSlot::Weapon));

    // 헬멧
    items_.push_back(make_unique<EquipmentItem>("나무 헬멧", 0, 1, 0, 5, 10, 0, EquipmentType::Armor, EquipmentSlot::Helmet));
    items_.push_back(make_unique<EquipmentItem>("풀플레이트 헬멧", 50, 1, 0, 15, 30, 0, EquipmentType::Armor, EquipmentSlot::Helmet));
    items_.push_back(make_unique<EquipmentItem>("요정 헬멧", 100, 1, 0, 35, 60, 0, EquipmentType::Armor, EquipmentSlot::Helmet));
    items_.push_back(make_unique<EquipmentItem>("드래곤 헬멧", 200, 1, 0, 45, 80, 0, EquipmentType::Armor, EquipmentSlot::Helmet));

    // 갑옷
    items_.push_back(make_unique<EquipmentItem>("나무 갑옷", 0, 1, 0, 10, 10, 0, EquipmentType::Armor, EquipmentSlot::Armor));
    items_.push_back(make_unique<EquipmentItem>("풀플레이트 갑옷", 50, 1, 0, 25, 30, 0, EquipmentType::Armor, EquipmentSlot::Armor));
    items_.push_back(make_unique<EquipmentItem>("요정 갑옷", 100, 1, 0, 45, 60, 0, EquipmentType::Armor, EquipmentSlot::Armor));
    items_.push_back(make_unique<EquipmentItem>("드래곤 갑옷", 200, 1, 0, 55, 80, 0, EquipmentType::Armor, EquipmentSlot::Armor));

    // 장갑
    items_.push_back(make_unique<EquipmentItem>("나무 장갑", 0, 1, 0, 5, 10, 0, EquipmentType::Armor, EquipmentSlot::Gloves));
    items_.push_back(make_unique<EquipmentItem>("풀플레이트 장갑", 50, 1, 0, 15, 30, 0, EquipmentType::Armor, EquipmentSlot::Gloves));
    items_.push_back(make_unique<EquipmentItem>("요정 장갑", 100, 1, 0, 35, 60, 0, EquipmentType::Armor, EquipmentSlot::Gloves));
    items_.push_back(make_unique<EquipmentItem>("드래곤 장갑", 200, 1, 0, 45, 80, 0, EquipmentType::Armor, EquipmentSlot::Gloves));

    // 신발
    items_.push_back(make_unique<EquipmentItem>("나무 신발", 0, 1, 0, 5, 10, 0, EquipmentType::Armor, EquipmentSlot::Boots));
    items_.push_back(make_unique<EquipmentItem>("풀플레이트 신발", 50, 1, 0, 15, 30, 0, EquipmentType::Armor, EquipmentSlot::Boots));
    items_.push_back(make_unique<EquipmentItem>("요정 신발", 100, 1, 0, 35, 60, 0, EquipmentType::Armor, EquipmentSlot::Boots));
    items_.push_back(make_unique<EquipmentItem>("드래곤 신발", 200, 1, 0, 45, 80, 0, EquipmentType::Armor, EquipmentSlot::Boots));
}

void Blacksmith::StoreMenu(Player& player, Inventory& inventory) {
    while (true) {
        LogManager::GetInstance().ClearScreen();
        LogManager::GetInstance().PrintEquipmentStoreMenu();
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
            cout << EquipmentShopAscii;
            ShowItems();
            cout << "구매할 아이템 : ";

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

        case 2:{
            LogManager::GetInstance().ClearScreen();
            cout << EquipmentShopAscii;
            SellMenu(player, inventory);
            break;
        }

        case 3:
            LogManager::GetInstance().ClearScreen();
            cout << EquipmentShopAscii;
            Enhance(player, inventory);
            break;

        default:
            cout << "잘못된 입력입니다.\n";
            break;
        }
    }
}

void Blacksmith::Enhance(Player& player, Inventory& inventory) {
    cout <<
        R"(+======================================================================================================================+
|                                                      강화 목록                                                       |
+======================================================================================================================+
|                                                                                                                      |
)";
    cout << R"(|                               1. 무기               2. 헬멧             3. 갑옷                                      |
|                               4. 장갑               5. 신발             0. 돌아가기                                  |
|                                                                                                                      |
+======================================================================================================================+
)";
    cout << "▶ 번호를 입력해주세요 : ";
    cout << "장비 강화\n";
    cout << "1. 무기\n";
    cout << "2. 헬멧\n";
    cout << "3. 갑옷\n";
    cout << "4. 장갑\n";
    cout << "5. 신발\n";
    cout << "0. 돌아가기\n";

    int menu;
    cin >> menu;
    EquipmentSlot slot;
    switch (menu) {
    case 1:
        slot = EquipmentSlot::Weapon;
        break;

    case 2:
        slot = EquipmentSlot::Helmet;
        break;

    case 3:
        slot = EquipmentSlot::Armor;
        break;

    case 4:
        slot = EquipmentSlot::Gloves;
        break;

    case 5:
        slot = EquipmentSlot::Boots;
        break;

    case 0:
        return;

    default:
        cout << "잘못된 입력입니다.\n";
        return;
    }

    int index = inventory.SelectEquipment(slot);
    if (index == -1) return;

    EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(inventory.GetInventory()[index].get());

    if (equipment == nullptr) {
        cout << "장비가 아닙니다.\n";
        return;
    }

    if (inventory.IsEquipped(*equipment)) {
        cout << "착용 중인 장비는 강화할 수 없습니다.\n";
        return;
    }

    // 강화석 선택
    cout << "\n사용할 강화석\n";
    cout << "1. 강화석(SR) (성공률 25%)\n";
    cout << "2. 강화석(SSR) (성공률 50%)\n";
    cout << "3. 강화석(U) (성공률 100%)\n";
    cout << "0. 돌아가기\n";

    int stoneMenu;
    cin >> stoneMenu;

    string stoneName;
    double successRate;

    switch (stoneMenu) {
    case 0:
        return;

    case 1:
        stoneName = "강화석(SR)";
        successRate = 0.25;
        break;

    case 2:
        stoneName = "강화석(SSR)";
        successRate = 0.5;
        break;

    case 3:
        stoneName = "강화석(U)";
        successRate = 1.0;
        break;

    default:
        cout << "잘못된 입력입니다.\n";
        return;
    }

    // 강화석 보유 확인
    int stoneIndex = inventory.FindMaterial(stoneName);
    if (stoneIndex == -1) {
        cout << "해당 강화석이 없습니다.\n";
        return;
    }

    // 강화석 소비
    inventory.RemoveItem(stoneIndex, 1);

    // 강화 시도
    int random = rand() % 100;
    if (random < successRate * 100) {
        cout << equipment->GetName() << " 강화 성공!\n";
        equipment->Enhance();
    }
    else {
        cout << equipment->GetName() << " 강화 실패\n";
    }
}