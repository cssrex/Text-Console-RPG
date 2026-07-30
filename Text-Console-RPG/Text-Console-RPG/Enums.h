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
	WORKSHOP
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

	// 강화
	EnhanceStone
};