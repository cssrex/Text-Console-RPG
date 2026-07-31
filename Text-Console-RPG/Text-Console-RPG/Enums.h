#pragma once

enum class Scene {
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
	Equipment
};

enum class ItemEffectType {
	None,

	// 회복
	HealHP,
	HealMP,
	HealHPMP,
	FullRecovery,
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

enum class DayType
{
	MORNING,
	NIGHT
};