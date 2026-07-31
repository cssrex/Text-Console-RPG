#include "Inventory.h"
#include "Player.h"

// 아이템 구매
void Store::BuyItem(Player& player, Inventory& inventory, int index)
{
	if (index < 0 || index >= static_cast<int>(shopItems_.size()))
	{
		cout << "잘못된 아이템입니다." << endl;
		return;
	}

	Item item = storeItems_[index];


	if (player.GetGold() < item.price_)
	{
		cout << "골드가 부족합니다." << endl;
		return;
	}

	player.SetGold(player.GetGold() - item.price_);
	inventory.AddItem(item, 1);
	cout << item.name_ << " 구매 완료" << endl;
}

// 아이템 판매
void Store::SellItem(Player& player, Inventory& inventory, int index)
{
	auto& items = inventory.GetInventory();


	if (index < 0 || index >= static_cast<int>(items.size()))
	{
		cout << "잘못된 아이템입니다." << endl;
		return;
	}

	Item item = items[index];
	int sellPrice = item.price_ / 0.6;

	player.SetGold(player.GetGold() + sellPrice);
	cout << item.name_ << " 판매 " << sellPrice << "골드 획득" << endl;


	items[index].count_--;
	if (items[index].count_ == 0)
	{
		items.erase(items.begin() + index);
	}
}