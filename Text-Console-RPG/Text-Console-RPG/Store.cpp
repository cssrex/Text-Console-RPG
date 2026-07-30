#include "Store.h"
#include "Player.h"
#include "Inventory.h"

Store::Store() {
    // 가격과 회복량은 임의로 부여함
    potionList_.push_back({ "HP 회복약 (소)", 100, 0,ItemType::Consumable,50,ItemEffectType::HealHP });
    potionList_.push_back({ "HP 회복약 (중)", 300, 0,ItemType::Consumable,100,ItemEffectType::HealHP });
}

// 상점 메뉴
void Store::StoreMenu(Player& player, Inventory& inventory) {
    int menu;
    while (true) {
        cout << "\n===== 상점 =====" << endl;
        cout << "1. 아이템 구매" << endl;
        cout << "2. 아이템 판매" << endl;
        cout << "0. 나가기" << endl;
        cout << "선택 : ";

        cin >> menu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (menu) {
        case 1:
            BuyItem(player, inventory);
            break;
        case 2:
            SellItem(player, inventory);
            break;
        case 0:
            return;
        default:
            cout << "잘못된 입력입니다." << endl;
            break;
        }
    }
}

// 아이템 구매
void Store::BuyItem(Player& player, Inventory& inventory) {
    cout << "\n===== 구매 목록 =====" << endl;
    for (int i = 0; i < potionList_.size(); i++) {
        cout << i + 1 << ". " << potionList_[i].name_ << " " << potionList_[i].price_ << " 골드" << endl;
    }

    int select;
    cout << "구매할 아이템 : ";
    cin >> select;

    if (select < 1 || select > static_cast<int>(potionList_.size())){
        cout << "잘못된 선택입니다." << endl;
        return;
    }

    Item item = potionList_[select - 1];

    if (player.GetGold() < item.price_) {
        cout << "골드가 부족합니다." << endl;
        return;
    }

    player.SetGold(player.GetGold() - item.price_);
    inventory.AddItem(item, 1);

    cout << item.name_
        << " 구매 완료!"
        << endl;
}


// 아이템 판매
void Store::SellItem(Player& player, Inventory& inventory) {
    const vector<Item>& items = inventory.GetInventory();

    if (items.empty()){
        cout << "판매할 아이템이 없습니다." << endl;
        return;
    }

    cout << "\n===== 판매 목록 =====" << endl;

    for (int i = 0; i < items.size(); i++) {
        cout << i + 1 << ". " << items[i].name_ << " x " << items[i].count_ << " (" << items[i].price_ / 2 << " 골드)" << endl;
    }

    int select;
    cout << "판매할 아이템 : ";
    cin >> select;

    if (select < 1 || select > static_cast<int>(items.size())) {
        cout << "잘못된 선택입니다." << endl;
        return;
    }

    int index = select - 1;
    Item item = items[index];
    int sellPrice = item.price_ / 2;
    player.SetGold(player.GetGold() + sellPrice);
    // 개수 감소
    if (item.count_ > 1) {
        // const라 직접 수정 불가
        // 아래 방식 사용하려면 Inventory에 함수 추가 필요
    }
    else {
        inventory.RemoveItem(index);
    }


    cout << item.name_ << " 판매 완료! " << sellPrice < " 골드 획득" << endl;
}