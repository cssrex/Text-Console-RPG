#pragma once

#include <string>
#include <memory>
#include <utility>
#include "Enums.h"

using namespace std;

class Player;

// 아이템 부모 클래스
class Item {
protected:
    string name_;
    int price_;
    int count_;
    ItemType itemType_;

public:
    Item(ItemType type, const string& name, int price, int count): itemType_(type), name_(name), price_(price), count_(count){}
    virtual ~Item() = default;

    virtual unique_ptr<Item> Clone() const = 0;

    string GetName() const {
        return name_;
    }

    int GetPrice() const {
        return price_;
    }

    int GetCount() const {
        return count_;
    }

    ItemType GetType() const {
        return itemType_;
    }

    void AddCount(int count = 1) {
        count_ += count;
    }

    void RemoveCount(int count) {
        count_ -= count;
        if (count_ < 0) count_ = 0;
    }
};

// 소모품
class ConsumableItem : public Item {
private:
    int effectValue_;
    ItemEffectType effectType_;

    int HealHP(Player& player, int value);
    int HealMP(Player& player, int value);
    pair<int, int> HealHPMP(Player& player, int value);
    pair<int, int> FullRecovery(Player& player);

public:
    ConsumableItem(const string& name, int price, int count, int value, ItemEffectType type): Item(ItemType::Consumable, name, price, count), effectValue_(value), effectType_(type) {}

    unique_ptr<Item> Clone() const override { return make_unique<ConsumableItem>(name_, price_, 1, effectValue_, effectType_); }

    bool Use(Player& player);

    ItemEffectType GetEffectType() const { return effectType_; }

    int GetEffectValue() const { return effectValue_; }
};

// 장비
class EquipmentItem : public Item {
private:
    int attackValue_;
    int defenseValue_;

    EquipmentType equipmentType_;
    EquipmentSlot equipmentSlot_;

public:
    EquipmentItem(const string& name, int price, int count, int attack, int defense, EquipmentType type, EquipmentSlot slot): Item(ItemType::Equipment, name, price, count), attackValue_(attack), defenseValue_(defense), equipmentType_(type), equipmentSlot_(slot) {}

    unique_ptr<Item> Clone() const override { return make_unique<EquipmentItem>(name_, price_, 1, attackValue_, defenseValue_, equipmentType_, equipmentSlot_); }

    void Equip(Player& player);
    void TakeOff(Player& player);

    int GetAttackValue() const { return attackValue_; }
    int GetDefenseValue() const { return defenseValue_; }

    EquipmentType GetEquipmentType() const { return equipmentType_; }
    EquipmentSlot GetEquipmentSlot() const { return equipmentSlot_; }
};

// 전리품
class LootItem : public Item {
public:
    LootItem(const string& name, int price, int count): Item(ItemType::Loot, name, price, count) {}

    unique_ptr<Item> Clone() const override { return make_unique<LootItem>(name_, price_, 1); }
};