#include "LogManager.h"
#include "Global.h"
#include "GameManager.h"
#include "Player.h"

LogManager::LogManager()
{
}

LogManager::~LogManager()
{
}

void LogManager::PrintInitializeCharacter()
{
}

void LogManager::PrintStartMenu()
{
	cout << R"(+=====================================================================================================================+
|                                                                                                                     |
|                                                                                                                     |
|                                                                                                                     |
|                                                                                                                     |
|                                                                                                                     |
|                                                                                                                     |
|                              _______ ______  __  __ _______     _____  _____   _____                                |
|                             |__   __|  ____| \ \/ /|__   __|   |  __ \|  __ \ / ____|                               |
|                                | |  | |__     \  /    | |      | |__) | |__) | |  __                                |
|                                | |  |  __|    /  \    | |      |  _  /|  ___/| | |_ |                               |
|                                | |  | |____  / /\ \   | |      | | \ \| |    | |__| |                               |
|                                |_|  |______|/_/  \_\  |_|      |_|  \_\_|     \_____|                               |
|                                                                                                                     |
|                                                                                                                     |
|                                                                                                                     |
|                                                                                                                     |
|                                                                                                                     |
|                                                                                                                     |
+====================================================================================================================+
)";
	cout << "�� �̸��� �Է����ּ��� : ";
}

void LogManager::PrintMainMenu()
{
	cout << R"(
+=================================================================================+
|                                                                                 |
|                                                                                 |
|                                                                                 |
|              _______ ______  __  __ _______     _____  _____   _____            |
|             |__   __|  ____| \ \/ /|__   __|   |  __ \|  __ \ / ____|           |
|                | |  | |__     \  /    | |      | |__) | |__) | |  __            |
|                | |  |  __|    /  \    | |      |  _  /|  ___/| | |_ |           |
|                | |  | |____  / /\ \   | |      | | \ \| |    | |__| |           |
|                |_|  |______|/_/  \_\  |_|      |_|  \_\_|     \_____|           |
|                                                                                 |
|                                                                                 |
|                                                                                 |
|---------------------------------------------------------------------------------|
|                                                                                 |
|                                                                                 |
|                                                                                 |
|             1. ���� ����          2. ����             3. ����                   |
|                                                                                 |
|             4. �÷��̾� ����      5. �κ��丮         0. ���� ����              |
|                                                                                 |
|                                                                                 |
|                                                                                 |
+=================================================================================+
)";
}

void LogManager::PrintHotel()
{
}

void LogManager::PrintStoreMenu()
{
}

void LogManager::PrintDungeonMenu()
{
}

LogManager& LogManager::GetInstance()
{
	static LogManager instance;

	return instance;
}


// 캐릭터 (Character) 로그
void LogManager::PrintTakeDamage(const string& name, int damage, int currentHp, int maxHp)
{
	cout << name << "이(가) " << damage << "의 피해를 입었습니다. (남은 HP: " << currentHp << " / " << maxHp << ")\n";
}

void LogManager::PrintHeal(const string& name, int value)
{
	cout << name << "의 체력이 " << value << "만큼 회복되었습니다.\n";
}

void LogManager::PrintAddStatusEffect(const string& name, const string& effectName)
{
	cout << name << "에게 [" << effectName << "] 상태이상이 부여되었습니다!\n";
}

void LogManager::PrintRemoveStatusEffect(const string& name, const string& effectName)
{
	cout << name << "의 [" << effectName << "] 상태이상이 해제되었습니다.\n";
}

void LogManager::PrintCharacterStatus(const string& name, int level, int hp, int maxHp, int mp, int maxMp, int attack)
{
	cout << "-----------------------------------------------\n";
	cout << "이름: " << name << " | Lv." << level << "\n";
	cout << "HP: " << hp << " / " << maxHp << " | MP: " << mp << " / " << maxMp << "\n";
	cout << "공격력: " << attack << "\n";
	cout << "-----------------------------------------------\n";
}

void LogManager::PrintShowAllSkillHeader(const string& name)
{
	cout << "=== " << name << "의 보유 스킬 목록 ===\n";
}

void LogManager::PrintShowAllSkillItem(int index, const string& skillName, int cost)
{
	cout << "[" << index << "] " << skillName << " (소모 MP: " << cost << ")\n";
}

void LogManager::PrintShowAllSkillFooter()
{
	cout << "===============================\n";
}

// 플레이어 (Player) 로그
static string MakeGaugeBar(int current, int max, int totalBlocks = 20) {
	if (max <= 0) max = 1;
	int filledBlocks = (current * totalBlocks) / max;
	if (filledBlocks > totalBlocks) filledBlocks = totalBlocks;
	if (filledBlocks < 0) filledBlocks = 0;

	string bar = "";
	for (int i = 0; i < filledBlocks; ++i) bar += "█";
	for (int i = 0; i < totalBlocks - filledBlocks; ++i) bar += "░";
	return bar;
}

void LogManager::PrintPlayerTakeDamage(const string& name, int actualDamage, int defense, int currentHp, int maxHp)
{
	cout << name << "이(가) " << actualDamage << "의 피해를 입었습니다! (방어력 "
		<< defense << " 감쇄 / 남은 HP: " << currentHp << " / " << maxHp << ")\n";
}

void LogManager::PrintPlayerStatus(const string& name, int level, int exp, int maxExp,
	int hp, int maxHp, int mp, int maxMp,
	int attack, int defense)
{
	int expPercent = (maxExp > 0) ? (exp * 100 / maxExp) : 0;
	string expBar = "";
	int expBlocks = expPercent / 20;
	for (int i = 0; i < 5; ++i) {
		expBar += (i < expBlocks) ? "■" : "□";
	}

	string hpBar = MakeGaugeBar(hp, maxHp, 20);
	string mpBar = MakeGaugeBar(mp, maxMp, 20);

	cout << "==================================================\n";
	cout << "                 [ 캐릭터 정보 ]                  \n";
	cout << "==================================================\n";
	cout << "  이름 : " << left << setw(24) << name << "직업 : 모험가\n";
	cout << "  레벨 : Lv. " << left << setw(22) << level << "경험치 : [" << expBar << "] " << expPercent << "%\n";
	cout << "--------------------------------------------------\n";
	cout << "  [ 기본 능력치 (Stats) ]\n";
	cout << "   • HP      : " << hpBar << " " << right << setw(3) << hp << " / " << setw(3) << maxHp << "\n";
	cout << "   • MP      : " << mpBar << " " << right << setw(3) << mp << " / " << setw(3) << maxMp << "\n";
	cout << "   • Power   : " << attack << "\n";
	cout << "   • Defense : " << defense << "\n\n";
	cout << "  <장비>\n";
	cout << "   • 무기    : (없음)\n";
	cout << "   • 방어구  : (없음)\n";
	cout << "--------------------------------------------------\n";
}

void LogManager::PrintSkillListHeader() { cout << "  [ 보유 스킬 (Skills) ]\n"; }
void LogManager::PrintSkillItem(int index, const string& skillName, int cost)
{
	cout << "   [" << index << "] " << skillName << "\n";
	cout << "       └ (소모 MP: " << cost << ")\n\n";
}

void LogManager::PrintActiveStatusEffectsHeader()
{
	cout << "--------------------------------------------------\n";
	cout << "  [ 적용 중인 상태이상 ]\n";
}

void LogManager::PrintActiveStatusEffectItem(const string& effectName, int turn)
{
	cout << "   • " << effectName << " (지속: " << turn << "턴 남음)\n";
}

void LogManager::PrintPlayerStatusFooter()
{
	cout << "==================================================\n\n";
}

void LogManager::PrintAddExp(int exp, int currentExp, int maxExp)
{
	cout << exp << " 경험치를 획득했습니다. (현재: " << currentExp << " / " << maxExp << ")\n";
}

void LogManager::PrintLevelUp(int oldLevel, int newLevel)
{
	cout << "\n★ 레벨 업! (Lv. " << oldLevel << " -> Lv. " << newLevel << ") ★\n\n";
}

void LogManager::PrintLevelDown(int level)
{
	cout << "레벨이 하락하여 Lv. " << level << "이 되었습니다.\n";
}

void LogManager::PrintAddGold(int gold)
{
	cout << gold << " 골드를 획득했습니다.\n";
}


// 스킬 (Skill) 로그
void LogManager::PrintSkillUseBasic(const string& casterName, const string& targetName, int damage)
{
	cout << casterName << "의 평타! " << targetName << "에게 " << damage << "의 피해를 입혔습니다.\n";
}

void LogManager::PrintSkillOneUse(const string& casterName, const string& skillName, const string& targetName, int damage)
{
	cout << casterName << "의 " << skillName << "! " << targetName << "에게 " << damage << "의 강력한 피해를 입혔습니다.\n";
}

void LogManager::PrintSkillTwoUse(const string& casterName, const string& skillName, const string& targetName, int damage)
{
	cout << casterName << "의 " << skillName << "! " << targetName << "에게 " << damage << "의 피해를 입혔습니다.\n";
}

void LogManager::PrintSkillMpLack(const string& skillName)
{
	cout << "MP가 부족하여 " << skillName << " 스킬을 사용할 수 없습니다!\n";
}

// 상태이상 (StatusEffect) 로그
void LogManager::PrintStatusEffectDamage(const string& effectName, const string& targetName, int damage)
{
	cout << "[" << effectName << "] 효과 발생! " << targetName << "에게 " << damage << "의 지속 피해를 입깁니다.\n";
}