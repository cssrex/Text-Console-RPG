#pragma once

enum class Scene
{
	START,
	MAIN,
	DUNGEON,
	HOTEL,
	STORE,
	END,
	NONE,
};

enum class ItemType {
	Loot,
	Consumable,
	Weapon,
	Armor
};

enum class ItemEffectType {
	None,

	// 회복
	HealHP,
	HealMP,
	HealBoth,
	FullRecovery,
	Antidote

	// 강화
	EnhanceStone
};