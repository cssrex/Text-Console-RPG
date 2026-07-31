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
	Equipment
};

enum class ItemEffectType {
	None,

	// 회복
	HealHP,
	HealMP,
	HealBoth,
	HealHPMP,
	FullRecovery,
	Antidote
	Antidote,

	// 강화
	EnhanceStone
};

enum class EquipmentType {
	Weapon,
	Armor
};

enum class EquipmentSlot {
	Weapon,
	Helmet,
	Armor,
	Gloves,
	Boots
};