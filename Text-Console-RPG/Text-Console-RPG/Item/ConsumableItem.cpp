#include <iostream>
#include <algorithm>
#include "Item.h"
#include "Player.h"
#include "LogManager.h"

using namespace std;

bool ConsumableItem::Use(Player& player) {
	auto PrintMessage = [](const string& message) {
			const int BOX_WIDTH = 117;

			cout << "| " << message;
			int space = BOX_WIDTH - LogManager::GetInstance().GetDisplayWidth(message);

			for (int i = 0; i < space; i++) cout << " ";
			cout << "|\n";
		};

	switch (effectType_) {
		// HP 회복약 (소), (중), (대)
	case ItemEffectType::HealHP: {
		if (player.GetHp() >= player.GetMaxHp()) {
			PrintMessage("HP가 이미 최대치입니다.");
			return false;
		}

		int healHp = HealHP(player, effectValue_);

		PrintMessage(name_ + " HP " + to_string(healHp) + " 회복");

		return true;
	}

	// MP 회복약 (소), (중), (대)
	case ItemEffectType::HealMP: {
		if (player.GetMp() >= player.GetMaxMp()) {
			PrintMessage("MP가 이미 최대치입니다.");
			return false;
		}

		int healMp = HealMP(player, effectValue_);

		PrintMessage(name_ + " MP " + to_string(healMp) + " 회복");

		return true;
	}

	// 엘릭서
	case ItemEffectType::HealHPMP: {
		if (player.GetHp() >= player.GetMaxHp() &&
			player.GetMp() >= player.GetMaxMp()) {
			PrintMessage("HP와 MP가 이미 최대치입니다.");
			return false;
		}

		pair<int, int> result = HealHPMP(player,player.GetMaxHp() / 2,player.GetMaxMp() / 2);

		PrintMessage(name_ +" HP " +to_string(result.first) +", MP " +to_string(result.second) +" 회복");

		return true;
	}

	// 파워 엘릭서
	case ItemEffectType::FullRecovery:{
		if (player.GetHp() >= player.GetMaxHp() &&
			player.GetMp() >= player.GetMaxMp()) {
			PrintMessage("HP와 MP가 이미 최대치입니다.");
			return false;
		}

		pair<int, int> result = FullRecovery(player);

		PrintMessage(name_ +" HP " +to_string(result.first) +", MP " +to_string(result.second) +" 회복"	);

		return true;
	}

	// 상태 이상 해제 물약
	case ItemEffectType::Antidote: {
		if (player.HasStatusEffect()) {
			player.ClearStatusEffects();

			PrintMessage("상태이상이 제거되었습니다.");

			return true;
		}

		PrintMessage("제거할 상태이상이 없습니다.");

		return false;
	}

	default:
		return false;
	}
}

int ConsumableItem::HealHP(Player& player, int value) {
	int before = player.GetHp();

	player.SetHp(min(player.GetHp() + value,player.GetMaxHp()));

	return player.GetHp() - before;
}

int ConsumableItem::HealMP(Player& player, int value) {
	int before = player.GetMp();

	player.SetMp(min(player.GetMp() + value,player.GetMaxMp()));

	return player.GetMp() - before;
}

pair<int, int> ConsumableItem::HealHPMP(Player& player, int hpValue, int mpValue) {
	int beforeHp = player.GetHp();
	int beforeMp = player.GetMp();

	player.SetHp(min(player.GetHp() + hpValue,player.GetMaxHp()));

	player.SetMp(min(player.GetMp() + mpValue,player.GetMaxMp()));

	return {
		player.GetHp() - beforeHp,
		player.GetMp() - beforeMp
	};
}

pair<int, int> ConsumableItem::FullRecovery(Player& player) {
	int beforeHp = player.GetHp();
	int beforeMp = player.GetMp();

	player.SetHp(
		player.GetMaxHp()
	);

	player.SetMp(
		player.GetMaxMp()
	);

	return {
		player.GetHp() - beforeHp,
		player.GetMp() - beforeMp
	};
}