#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Inventory;

class Player;

class Store
{
private:
	vector<Item> storeItems_;

public:
	// 상점 출력
	void ShowStore();

	// 구매
	void BuyItem(Player& player, Inventory& inventory, int index);

	// 판매
	void SellItem(Player& player, Inventory& inventory, int index);
};

#endif