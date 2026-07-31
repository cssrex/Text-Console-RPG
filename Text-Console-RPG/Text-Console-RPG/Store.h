#pragma once

#include <vector>
#include <memory>
#include "Item.h"

using namespace std;

class Player;
class Inventory;

class Store {
protected:
    // 판매 아이템 목록
    vector<unique_ptr<Item>> items_;

public:
    virtual ~Store() = default;

    // 상점 메뉴
    virtual void StoreMenu(Player& player, Inventory& inventory) = 0;

    // 구매
    void BuyItem(Player& player, Inventory& inventory, int index);

    // 판매
    bool SellItem(Player& player, Inventory& inventory, int index);

    // 판매 메뉴
    void SellMenu(Player& player, Inventory& inventory);

    // 아이템 출력
    void ShowItems() const;
};

class PotionStore : public Store {
public:
    PotionStore();

    void StoreMenu(Player& player, Inventory& inventory) override;
};

class Blacksmith : public Store {
public:
    BlackSmith();

    void StoreMenu(Player& player, Inventory& inventory) override;
    void Enhance(Player& player, Inventory& inventory);
};