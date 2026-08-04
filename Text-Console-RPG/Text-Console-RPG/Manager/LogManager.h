#pragma once

#include <string>
#include <vector>
#include <map>

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
	void PrintPassDay();
	void PrintDayOver();
	void PrintGameClear();
	void PrintGameOut();
	//게임시작 - 프롤로그
	void PrintPrologue();
	//인게임 화면 색상 출력(낮,밤,디데이)
	void ApplyTimeColor();
	//인게임 화면 색상 출력(낮으로 강제변경)
	void ApplySpecialColor();

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
	void PrintPlayerStatus(const std::string& name, int level, int exp, int maxExp,
		int hp, int maxHp, int mp, int maxMp, int attack, int defense, int bonusAttack = 0, int bonusDefense = 0,
		const std::string& weaponName = "(없음)",
		const std::string& helmetName = "(없음)",
		const std::string& armorName = "(없음)",
		const std::string& glovesName = "(없음)",
		const std::string& bootsName = "(없음)");
	void PrintSkillListHeader();
	void PrintSkillItem(int index, const std::string& skillName, int cost, const std::string& description);
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
	void PrintAddStatusEffect(const std::string& name, const std::string& effectName, int duration);
	void PrintRefreshStatusEffect(const std::string& name, const std::string& effectName, int duration);

	// 던전 (Dungeon) 관련
	void PrintDungeonList(const std::vector<std::string>& roomList);
	void PrintDungeonBattleMainMenu(Room*& room, int floor, Player*& player, Monster*& monster);
	void PrintDungeonBattleMonsterTurn(Room*& room, int floor, Player*& player, Monster*& monster);
	void PrintDungeonPlayerStatus(Player*& player);
	void PrintDungeonMonsterStatus(Monster*& monster);
	void PrintDungeonProgressOption(Room*& room, int floor, const std::string& rewardItem, int rewardGold, int rewardExp);
	void PrintDungeonReward(const std::string& item, int gold, int exp);
	void PrintDungeonKillList(const std::map<std::string, int>& killedMonsterList_);
	//몬스터 피격 데미지 출력
	void PrintMonsterHitEffect(int damage);
	//몬스터 피격 이미지 출력
	void PrintMonsterHitFlash(Monster* monster);
	//플레이어 피격 데미지 출력
	void PrintPlayerHitEffect(int damage);
	
	// 상점 (Store) 관련
	void PrintPotionStoreMenu();
	void PrintEquipmentStoreMenu();
	int GetDisplayWidth(const std::string& str) const;
	void PrintDungeonPlayerDeath();
};