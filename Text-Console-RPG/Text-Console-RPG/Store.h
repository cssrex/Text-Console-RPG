#ifndef STORE_H
#define STORE_H

#include <vector>
#include "Enums.h"
#include "Item.h"

using namespace std;

class Player;
class Inventory;

class Store {
private:
    vector<Item> potionList_;

public:
    Store();
    
    // 상점 메인
    void StoreMenu(Player& player, Inventory& inventory);

    // 포션 구매
    void BuyItem(Player& player, Inventory& inventory);

    // 아이템 판매
    void SellItem(Player& player, Inventory& inventory);
};

#endif