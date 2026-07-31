#include <iostream>
#include <algorithm>
#include "Item.h"
#include "Player.h"

bool ConsumableItem::Use(Player& player) {
    switch (effectType_) {
    // HP 회복약 (소), (중), (대)
    case ItemEffectType::HealHP:
    {
        if (player.GetHp() >= player.GetMaxHp()) {
            cout << "HP가 이미 최대치입니다." << endl;
            return false;
        }

        int healHp = HealHP(player, effectValue_);
        cout << name_ << " HP " << healHp << " 회복" << endl;

        return true;
    }

    // MP 회복약 (소), (중), (대)
    case ItemEffectType::HealMP: {
        if (player.GetMp() >= player.GetMaxMp()) {
            cout << "MP가 이미 최대치입니다." << endl;
            return false;
        }

        int healMp = HealMP(player, effectValue_);
        cout << name_ << " MP " << healMp << " 회복" << endl;

        return true;
    }

    // 엘릭서
    case ItemEffectType::HealHPMP: {
        if (player.GetHp() >= player.GetMaxHp() && player.GetMp() >= player.GetMaxMp()) {
            cout << "HP와 MP가 이미 최대치입니다." << endl;
            return false;
        }

        pair<int, int> result = HealHPMP(player, player.GetMaxHp() / 2, player.GetMaxMp() / 2);

        cout << name_ << " HP " << result.first << ", MP " << result.second << " 회복" << endl;

        return true;
    }

    // 파워 엘릭서
    case ItemEffectType::FullRecovery: {
        if (player.GetHp() >= player.GetMaxHp() && player.GetMp() >= player.GetMaxMp()) {
            cout << "HP와 MP가 이미 최대치입니다." << endl;
            return false;
        }

        pair<int, int> result = FullRecovery(player);

        cout << name_ << " HP " << result.first << ", MP " << result.second << " 회복" << endl;

        return true;
    }

    // 상태 이상 해제 물약
    case ItemEffectType::Antidote: {
        if (player.HasStatusEffect()) {
            player.ClearStatusEffects();
            cout << "상태이상이 제거되었습니다." << endl;
            
            return true;
        }
        else {
            cout << "제거할 상태이상이 없습니다." << endl;

            return false;
        }
    }

    // 강화석
    case ItemEffectType::EnhanceStone:
    {
        // 추후 구현
        return false;
    }

    default:
        return false;
    }
}

int ConsumableItem::HealHP(Player& player, int value) {
    int before = player.GetHp();

    player.SetHp(min(player.GetHp() + value, player.GetMaxHp()));

    return player.GetHp() - before;
}

int ConsumableItem::HealMP(Player& player, int value) {
    int before = player.GetMp();

    player.SetMp(min(player.GetMp() + value, player.GetMaxMp()));

    return player.GetMp() - before;
}

pair<int, int> ConsumableItem::HealHPMP(Player& player, int hpValue, int mpValue) {
    int beforeHp = player.GetHp();
    int beforeMp = player.GetMp();

    player.SetHp(min(player.GetHp() + hpValue, player.GetMaxHp()));
    player.SetMp(min(player.GetMp() + mpValue, player.GetMaxMp()));

    return { player.GetHp() - beforeHp, player.GetMp() - beforeMp };
}

pair<int, int> ConsumableItem::FullRecovery(Player& player) {
    int beforeHp = player.GetHp();
    int beforeMp = player.GetMp();

    player.SetHp(player.GetMaxHp());
    player.SetMp(player.GetMaxMp());

    return { player.GetHp() - beforeHp, player.GetMp() - beforeMp };
}