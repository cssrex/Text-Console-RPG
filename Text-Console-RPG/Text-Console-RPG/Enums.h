#pragma once

enum class Scene
{
	START,
	MAIN,
	DUNGEON,
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