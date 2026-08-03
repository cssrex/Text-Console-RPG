#pragma once

#include <string>
#include <vector>

struct Room;
class Monster;
class Player;
class LogManager {
private:

private:
	LogManager();
	~LogManager();
	LogManager(const LogManager&) = delete;
	LogManager& operator=(const LogManager&) = delete;
	
public:
	static LogManager& GetInstance();

public:
	void ClearScreen();
	void PrintInpuErrorMessage();

	void PrintRemoveAllStatusEffect(std::string name);

	// 게임 매니저 관련
	void PrintInitializeCharacter();
	void PrintStartMenu();
	void PrintMainMenu();
	void PrintHotelMenu();
	void PrintStoreMenu();
	void PrintDungeonMenu();
	void PrintDayOver();
	void PrintGameClear();

	// 캐릭터 (Character) 관련
	void PrintTakeDamage(const std::string& name, int damage, int currentHp, int maxHp);
	void PrintHeal(const std::string& name, int value);
	void PrintMpHeal(const std::string& name, int value);
	void PrintAddStatusEffect(const std::string& name, const std::string& effectName);
	void PrintRemoveStatusEffect(const std::string& name, const std::string& effectName);
	void PrintCharacterStatus(const std::string& name, int level, int hp, int maxHp, int mp, int maxMp, int attack);
	
	void PrintShowAllSkillHeader(const std::string& name); 
	void PrintShowAllSkillItem(int index, const std::string& skillName, int cost);
	void PrintShowAllSkillFooter();

	
	// 플레이어 (Player) 관련
	void PrintPlayerTakeDamage(const std::string& name, int actualDamage, int defense, int currentHp, int maxHp);
	void PrintPlayerStatus(const std::string& name, int level, int exp, int maxExp, int hp, int maxHp, int mp, int maxMp, int attack, int defense);
	void PrintSkillListHeader();
	void PrintSkillItem(int index, const std::string& skillName, int cost);
	void PrintActiveStatusEffectsHeader();
	void PrintActiveStatusEffectItem(const std::string& effectName, int turn);
	void PrintPlayerStatusFooter();
	void PrintAddExp(int exp, int currentExp, int maxExp);
	void PrintLevelUp(int oldLevel, int newLevel, int oldMaxHp, int newMaxHp, int oldMaxMp, 
		int newMaxMp, int oldAttack, int newAttack, int oldDefense, int newDefense);
	void PrintLevelDown(int level);
	void PrintAddGold(int gold);

	// 스킬 (Skill) 관련
	void PrintSkillUseBasic(const std::string& casterName, const std::string& targetName, int damage);
	void PrintSkillOneUse(const std::string& casterName, const std::string& skillName, const std::string& targetName, int damage);
	void PrintSkillTwoUse(const std::string& casterName, const std::string& skillName, const std::string& targetName, int damage);
	void PrintSkillMpLack(const std::string& skillName);

	// 상태이상 (StatusEffect) 관련
	void PrintStatusEffectDamage(const std::string& effectName, const std::string& targetName, int damage);

	// 던전 (Dungeon) 관련
	void PrintDungeonList(const std::vector<std::string>& roomList);
	void PrintDungeonBattleMainMenu(Room*& room, int floor, Player*& player, Monster*& monster);
	void PrintDungeonPlayerStatus(Player*& player);
	void PrintDungeonMonsterStatus(Monster*& monster);
	void PrintDungeonProgressOption(Room*& room, int floor, const std::string& rewardItem, int rewardGold, int rewardExp);
	void PrintDungeonReward(const std::string& item, int gold, int exp);
	void PrintDungeonPlayerDeath();
};