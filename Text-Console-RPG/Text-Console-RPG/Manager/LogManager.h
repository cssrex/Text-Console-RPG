#pragma once

#include <string>

class LogManager
{
private:

private:
	LogManager();
	~LogManager();
	LogManager(const LogManager&) = delete;
	LogManager& operator=(const LogManager&) = delete;

public:
	void PrintInitializeCharacter();
	void PrintStartMenu();
	void PrintMainMenu();
	void PrintHotel();
	void PrintStoreMenu();
	void PrintDungeonMenu();

public:
	static LogManager& GetInstance();




public:
	// 캐릭터 (Character) 로그
	void PrintTakeDamage(const std::string& name, int damage, int currentHp, int maxHp);
	void PrintHeal(const std::string& name, int value);
	void PrintAddStatusEffect(const std::string& name, const std::string& effectName);
	void PrintRemoveStatusEffect(const std::string& name, const std::string& effectName);

	void PrintCharacterStatus(const std::string& name, int level, int hp, int maxHp, int mp, int maxMp, int attack);
	void PrintShowAllSkillHeader(const std::string& name);
	void PrintShowAllSkillItem(int index, const std::string& skillName, int cost);
	void PrintShowAllSkillFooter();

	// 플레이어 (Player) 로그
	void PrintPlayerTakeDamage(const std::string& name, int actualDamage, int defense, int currentHp, int maxHp);
	void PrintPlayerStatus(const std::string& name, int level, int exp, int maxExp, int hp, int maxHp, int mp, int maxMp, int attack, int defense);
	void PrintSkillListHeader();
	void PrintSkillItem(int index, const std::string& skillName, int cost);
	void PrintActiveStatusEffectsHeader();
	void PrintActiveStatusEffectItem(const std::string& effectName, int turn);
	void PrintPlayerStatusFooter();
	void PrintAddExp(int exp, int currentExp, int maxExp);
	void PrintLevelUp(int oldLevel, int newLevel);
	void PrintLevelDown(int level);
	void PrintAddGold(int gold);

	// 스킬 (Skill) 로그
	void PrintSkillUseBasic(const std::string& casterName, const std::string& targetName, int damage);
	void PrintSkillOneUse(const std::string& casterName, const std::string& skillName, const std::string& targetName, int damage);
	void PrintSkillTwoUse(const std::string& casterName, const std::string& skillName, const std::string& targetName, int damage);
	void PrintSkillMpLack(const std::string& skillName);

	// 상태이상 (StatusEffect) 로그
	void PrintStatusEffectDamage(const std::string& effectName, const std::string& targetName, int damage);
};

