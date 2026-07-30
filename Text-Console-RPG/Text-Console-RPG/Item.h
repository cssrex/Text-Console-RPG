struct Item {
	string name_;
	int price_ = 0;
	int count_ = 0;

	ItemType itemType_ = ItemType::Loot;

	// 소모품
	int effectValue_ = 0;
	ItemEffectType itemEffectType_ = ItemEffectType::None;

	// 장비
	int attackValue_ = 0;
	int defenseValue_ = 0;
};