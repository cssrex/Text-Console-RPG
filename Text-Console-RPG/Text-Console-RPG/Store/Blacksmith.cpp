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


Blacksmith::Blacksmith() {
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

            cout << "잘못된 입력입니다." << endl;
            _getch();

            continue;
        }

        switch (menu) {
        case 0:
            return;

        case 1: {
            LogManager::GetInstance().ClearScreen();
            cout << EquipmentShopAscii;

            cout <<
R"(+======================================================================================================================+
|                                                      구매 목록                                                       |
+======================================================================================================================+
|                                                                                                                      |
)";
            string goldText = "골드 : " + to_string(player.GetGold());
            cout << "| " << goldText;
            int space = 117 - LogManager::GetInstance().GetDisplayWidth(goldText);
            for (int i = 0; i < space; i++) cout << " ";
            cout << "|\n";

            cout << "| ";
            for (int i = 0; i < 117; i++) cout << " ";
            cout << "|\n";

            ShowItems();
            cout << "▶ 번호를 입력해주세요 : ";
            int index;
            cin >> index;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "잘못된 입력입니다." << endl;
                _getch();

                break;
            }

            if (index == 0) {
                break;
            }

            BuyResult result = BuyItem(player,inventory,index - 1);

            switch (result) {
            case BuyResult::Success:
                cout << "구매 완료" << endl;
                _getch();

                break;

            case BuyResult::NotEnoughGold:
                cout << "골드가 부족합니다." << endl;
                _getch();

                break;

            case BuyResult::InvalidItem:
                cout << "존재하지 않는 아이템입니다." << endl;
                _getch();

                break;
            }

            break;
        }

        case 2: {
            LogManager::GetInstance().ClearScreen();
            cout << EquipmentShopAscii;
            SellMenu(player,inventory,EquipmentShopAscii);

            break;
        }

        case 3: {
            LogManager::GetInstance().ClearScreen();
            cout << EnhanceAscii;
            Enhance(player,inventory);

            break;
        }

        default:
            cout << "잘못된 입력입니다." << endl;
            _getch();

            break;
        }
    }
}

void Blacksmith::Enhance(Player& player, Inventory& inventory) {
    const int BOX_WIDTH = 117;

    auto PrintLine = [&](const string& text) {
            cout << "| " << text;

            int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(text);

            for (int i = 0; i < space; i++) cout << " ";
            cout << "|\n";
        };


    auto PrintResultBox = [&](const string& title, const string& message) {
            LogManager::GetInstance().ClearScreen();
            cout << EnhanceAscii;

            cout << "+======================================================================================================================+\n";

            string titleText = "                                                      " + title;
            cout << "|" << titleText;
            int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(titleText);
            for (int i = 0; i < space; i++) cout << " ";
            cout << "|\n";
            cout << "+======================================================================================================================+\n";

            PrintLine("");
            PrintLine(message);
            PrintLine("");
            cout << "+======================================================================================================================+\n";
        };

    cout <<
R"(+======================================================================================================================+
|                                                      강화 목록                                                       |
+======================================================================================================================+
|                                                                                                                      |
|                               1. 무기               2. 헬멧             3. 갑옷                                      |
|                               4. 장갑               5. 신발             0. 돌아가기                                  |
|                                                                                                                      |
+======================================================================================================================+
)";

    bool hasEquipment = false;
    for (const auto& item : inventory.GetInventory()) {
        EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(item.get());

        if (equipment != nullptr) {
            hasEquipment = true;
            break;
        }
    }


    if (!hasEquipment) {
        PrintResultBox("강화", "강화할 수 있는 장비가 없습니다.");
        cout << "▶ 아무 키나 입력해주세요 : ";
        _getch();

        return;
    }

    cout << "▶ 번호를 입력해주세요 : ";
    int menu;
    cin >> menu;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<< "잘못된 입력입니다.";
        _getch();

        return;
    }

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
        cout << "잘못된 입력입니다.";

        _getch();

        return;
    }

    LogManager::GetInstance().ClearScreen();
    cout << EnhanceAscii;
    int index = inventory.SelectEquipment(slot);

    if (index == -2) {
        return;
    }

    if (index == -1) {
        return;
    }

    EquipmentItem* equipment = dynamic_cast<EquipmentItem*>(inventory.GetInventory()[index].get());



    if (equipment == nullptr) {
        PrintResultBox("강화", "장비가 아닙니다.");

        cout << "▶ 아무 키나 입력해주세요 : ";
        _getch();

        return;
    }


    if (inventory.IsEquipped(*equipment)) {
        cout << "착용 중인 장비는 강화할 수 없습니다.\n";

        cout << "▶ 아무 키나 입력해주세요 : ";
        _getch();

        return;
    }

    LogManager::GetInstance().ClearScreen();
    cout << EnhanceAscii;

    cout <<
R"(+======================================================================================================================+
|                                                      강화석 선택                                                     |
+======================================================================================================================+
|                                                                                                                      |
)";

    int srIndex = inventory.FindMaterial("강화석(SR)");
    int ssrIndex = inventory.FindMaterial("강화석(SSR)");
    int uIndex = inventory.FindMaterial("강화석(U)");

    int srCount = (srIndex != -1) ? inventory.GetInventory()[srIndex]->GetCount() : 0;

    int ssrCount = (ssrIndex != -1) ? inventory.GetInventory()[ssrIndex]->GetCount() : 0;

    int uCount = (uIndex != -1) ? inventory.GetInventory()[uIndex]->GetCount() : 0;


    PrintLine("1. 강화석(SR)   (성공률 25%)   보유: " + to_string(srCount) + "개" );

    PrintLine("2. 강화석(SSR)  (성공률 50%)   보유: " + to_string(ssrCount) + "개" );

    PrintLine("3. 강화석(U)    (성공률 100%)  보유: " + to_string(uCount) + "개" );

    PrintLine("");

    PrintLine("0. 돌아가기");

    cout <<
        "+======================================================================================================================+\n";

    cout << "▶ 번호를 입력해주세요 : ";

    int stoneMenu;
    cin >> stoneMenu;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "잘못된 입력입니다.";
        _getch();

        return;
    }

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
        cout << "잘못된 입력입니다.";
        _getch();

        return;
    }

    int stoneIndex = inventory.FindMaterial(stoneName);



    if (stoneIndex == -1) {
        PrintResultBox("강화석 선택","보유 중인 " + stoneName + "이(가) 없습니다.");

        cout << "▶ 아무 키나 입력해주세요 : ";
        _getch();

        return;
    }

    inventory.RemoveItem(stoneIndex,1);

    int random = rand() % 100;
    string resultMessage;

    if (random < successRate * 100) {
        int beforeAttack = equipment->GetAttackValue();
        int beforeDefense = equipment->GetDefenseValue();
        int beforeHealth = equipment->GetHealthValue();

        equipment->Enhance();

        int increaseAttack = equipment->GetAttackValue() - beforeAttack;
        int increaseDefense = equipment->GetDefenseValue() - beforeDefense;
        int increaseHealth = equipment->GetHealthValue() - beforeHealth;

        resultMessage = equipment->GetName() + " 강화 성공! ";

        if (increaseAttack > 0) {
            resultMessage += "공격력 +" + to_string(increaseAttack);
        }

        if (increaseDefense > 0) {
            resultMessage += "방어력 +" + to_string(increaseDefense);
        }

        if (increaseHealth > 0) {
            resultMessage += "체력 +" + to_string(increaseHealth);
        }
    }
    else {
        resultMessage = equipment->GetName() + " 강화 실패";
    }

    PrintResultBox("강화 결과",resultMessage);


    cout << "▶ 아무 키나 입력해주세요 : ";
    _getch();
}