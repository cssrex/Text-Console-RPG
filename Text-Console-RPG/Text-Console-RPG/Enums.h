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
	Consumable,
	Equipment,
	Loot,
	Material
};

enum class ItemEffectType {
	None,

	// 회복
	HealHP,
	HealMP,
	HealHPMP,
	FullRecovery,
	Antidote,
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

enum class DayType {
	MORNING,
	NIGHT
};

enum class MaterialType {
	EnhanceStone,
};

enum class BuyResult {
	Success,
	InvalidItem,
	NotEnoughGold
};