#include "LogManager.h"
#include "Global.h"
#include "GameManager.h"
#include "Player.h"
#include "Dungeon.h"
#include "Monster.h"

LogManager::LogManager() {
}

LogManager::~LogManager() {
}

void LogManager::PrintInitializeCharacter() {
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
+=====================================================================================================================+
)";
	cout << "▶ 이름을 입력해주세요 : ";
}


void LogManager::PrintMainMenu() {
	
	cout << R"(
+======================================================================================+
|                                                                                      |
|                1. 던전 입장          2. 상점             3. 여관                     |
|                                                                                      |
|                4. 플레이어 정보      5. 인벤토리         0. 게임 종료                |
|                                                                                      |
+======================================================================================+
)";
}

void LogManager::PrintHotel() {

}

void LogManager::PrintStoreMenu() {
	cout << R"(
+======================================================================================+
|                                                                                      |
|               1. 포션 상점          2. 대장간          0. 나가기                     |
|                                                                                      |
+======================================================================================+
)";
}

void LogManager::PrintDungeonMenu() {
	cout << R"(
+======================================================================================+
|                                                                                      |
|              1. 슬라임 던전        2. 고블린 던전        3. 오크 던전                |
|                                                                                      |
|              4. 드래곤 던전        0. 나가기                                         |
|                                                                                      |
+======================================================================================+
)";
}

LogManager& LogManager::GetInstance() {
	static LogManager instance;

	return instance;
}

void LogManager::ClearScreen()
{
	system("cls");
}

void LogManager::PrintInpuErrorMessage()
{
	cout << "잘못된 입력입니다\n";
}

// 캐릭터 (Character) 관련
void LogManager::PrintTakeDamage(const string& name, int damage, int currentHp, int maxHp) {
	cout << name << "이(가) " << damage << "의 피해를 입었습니다. (남은 HP: " << currentHp << " / " << maxHp << ")\n";
}

void LogManager::PrintHeal(const string& name, int value) {
	cout << name << "의 체력이 " << value << "만큼 회복되었습니다.\n";
}

void LogManager::PrintAddStatusEffect(const string& name, const string& effectName) {
	cout << name << "에게 [" << effectName << "] 상태이상이 부여되었습니다!\n";
}

void LogManager::PrintRemoveStatusEffect(const string& name, const string& effectName) {
	cout << name << "의 [" << effectName << "] 상태이상이 해제되었습니다.\n";
}

void LogManager::PrintCharacterStatus(const string& name, int level, int hp, int maxHp, int mp, int maxMp, int attack) {
	cout << "-----------------------------------------------\n";
	cout << "이름: " << name << " | Lv." << level << "\n";
	cout << "HP: " << hp << " / " << maxHp << " | MP: " << mp << " / " << maxMp << "\n";
	cout << "공격력: " << attack << "\n";
	cout << "-----------------------------------------------\n";
}

void LogManager::PrintShowAllSkillHeader(const string& name) {
	cout << "=== " << name << "의 보유 스킬 목록 ===\n";
}

void LogManager::PrintShowAllSkillItem(int index, const string& skillName, int cost) {
	cout << "[" << index << "] " << skillName << " (소모 MP: " << cost << ")\n";
}

void LogManager::PrintShowAllSkillFooter() {
	cout << "===============================\n";
}

// 스킬매니저 (SKillManager) 관련
void LogManager::PrintShowAllSkillHeader(const string& name) {
	cout << "\n=== " << name << "의 보유 스킬 목록 ===\n"; // [추가]
}

void LogManager::PrintShowAllSkillItem(int index, const string& skillName, int cost) {
	cout << "[" << index << "] " << skillName << " (소모 MP: " << cost << ")\n"; // [추가]
}

void LogManager::PrintShowAllSkillFooter() {
	cout << "===============================\n"; // [추가]
}

void LogManager::PrintSkillMpLack(const string& skillName) {
	cout << "MP가 부족하여 " << skillName << " 스킬을 사용할 수 없습니다!\n"; // [추가]
}

// 플레이어 (Player) 관련
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

void LogManager::PrintPlayerTakeDamage(const string& name, int actualDamage, int defense, int currentHp, int maxHp) {
	cout << name << "이(가) " << actualDamage << "의 피해를 입었습니다! (방어력 "
		<< defense << " 감쇄 / 남은 HP: " << currentHp << " / " << maxHp << ")\n";
}

void LogManager::PrintPlayerStatus(const string& name, int level, int exp, int maxExp,
	int hp, int maxHp, int mp, int maxMp,
	int attack, int defense) {
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
void LogManager::PrintSkillItem(int index, const string& skillName, int cost) {
	cout << "   [" << index << "] " << skillName << "\n";
	cout << "       └ (소모 MP: " << cost << ")\n\n";
}

void LogManager::PrintActiveStatusEffectsHeader() {
	cout << "--------------------------------------------------\n";
	cout << "  [ 적용 중인 상태이상 ]\n";
}

void LogManager::PrintActiveStatusEffectItem(const string& effectName, int turn) {
	cout << "   • " << effectName << " (지속: " << turn << "턴 남음)\n";
}

void LogManager::PrintPlayerStatusFooter() {
	cout << "==================================================\n\n";
}

void LogManager::PrintAddExp(int exp, int currentExp, int maxExp) {
	cout << exp << " 경험치를 획득했습니다. (현재: " << currentExp << " / " << maxExp << ")\n";
}

void LogManager::PrintLevelUp(int oldLevel, int newLevel) {
	cout << "\n★ 레벨 업! (Lv. " << oldLevel << " -> Lv. " << newLevel << ") ★\n\n";
}

void LogManager::PrintLevelDown(int level) {
	cout << "레벨이 하락하여 Lv. " << level << "이 되었습니다.\n";
}

void LogManager::PrintAddGold(int gold) {
	cout << gold << " 골드를 획득했습니다.\n";
}

// 스킬 (Skill) 관련
void LogManager::PrintSkillUseBasic(const string& casterName, const string& targetName, int damage) {
	cout << casterName << "의 평타! " << targetName << "에게 " << damage << "의 피해를 입혔습니다.\n";
}

void LogManager::PrintSkillOneUse(const string& casterName, const string& skillName, const string& targetName, int damage) {
	cout << casterName << "의 " << skillName << "! " << targetName << "에게 " << damage << "의 강력한 피해를 입혔습니다.\n";
}

void LogManager::PrintSkillTwoUse(const string& casterName, const string& skillName, const string& targetName, int damage) {
	cout << casterName << "의 " << skillName << "! " << targetName << "에게 " << damage << "의 피해를 입혔습니다.\n";
}

void LogManager::PrintSkillMpLack(const string& skillName) {
	cout << "MP가 부족하여 " << skillName << " 스킬을 사용할 수 없습니다!\n";
}

// 상태이상 (StatusEffect) 관련
void LogManager::PrintStatusEffectDamage(const string& effectName, const string& targetName, int damage) {
	cout << "[" << effectName << "] 효과 발생! " << targetName << "에게 " << damage << "의 지속 피해를 입깁니다.\n";
}

int GetVisualWidth(const std::string& str) {
	int width = 0;
	for (size_t i = 0; i < str.length(); ) {
		unsigned char c = static_cast<unsigned char>(str[i]);
		if (c < 0x80) {
			// ASCII 문자 (1칸)
			width += 1;
			i += 1;
		}
		else {
			// UTF-8 멀티바이트 문자 (한글, 특수문자 등 - 콘솔 2칸)
			width += 2;
			if ((c & 0xE0) == 0xC0) i += 2;
			else if ((c & 0xF0) == 0xE0) i += 3;
			else if ((c & 0xF8) == 0xF0) i += 4;
			else i += 1;
		}
	}
	return width;
}

void LogManager::PrintDungeonList(const vector<string>& roomList)
{
	ClearScreen();
	cout << "+=================================================================================+\n";
	cout << "|                                                                                 |\n";
	cout << "|                         /\\                                                      |\n";
	cout << "|                        /  \\                                                     |\n";
	cout << "|                       / /\\ \\                                                    |\n";
	cout << "|                      / /  \\ \\                                                   |\n";
	cout << "|                     / /____\\ \\                                                  |\n";
	cout << "|                    /  _______ \\                                                 |\n";
	cout << "|                   /  /       \\  \\                                               |\n";
	cout << "|                  /  /  [   ]  \\  \\                                              |\n";
	cout << "|                 /__/   |   |   \\__\\                                             |\n";
	cout << "|                        |   |                                                    |\n";
	cout << "|                                                                                 |\n";
	cout << "|---------------------------------------------------------------------------------|\n";
	cout << "|                                                                                 |\n";

	const int totalWidth = 81;

	for (size_t i = 0; i < roomList.size(); ++i) {
		std::string itemText = std::to_string(i + 1) + ". " + roomList[i];
		int itemWidth = GetVisualWidth(itemText);

		int rightPadding = totalWidth - 33 - itemWidth;
		if (rightPadding < 0) rightPadding = 0;

		cout << "|                                 "
			<< itemText
			<< std::string(rightPadding, ' ')
			<< "|\n";
		cout << "|                                                                                 |\n";
	}

	std::string backText = "0. 뒤로가기";
	int backWidth = GetVisualWidth(backText);
	int backRightPadding = totalWidth - 33 - backWidth;
	if (backRightPadding < 0) backRightPadding = 0;

	cout << "|                                 "
		<< backText
		<< std::string(backRightPadding, ' ')
		<< "|\n";
	cout << "|                                                                                 |\n";
	cout << "+=================================================================================+\n";
	cout << "▶ 행동을 선택해주세요: ";
}

void LogManager::PrintDungeonBattleMainMenu(Room*& room, int floor, Monster*& monster)
{
	int currentHp = monster->GetHp();
	int maxHp = monster->GetMaxHp();

	int fillCount = 0;
	if (maxHp > 0) {
		fillCount = static_cast<int>((static_cast<double>(currentHp) / maxHp) * 10.0);
	}
	
	if (fillCount > 10) fillCount = 10;
	if (fillCount < 0) fillCount = 0;

	string hpBar = "";
	for (int i = 0; i < fillCount; ++i) {
		hpBar += "█";
	}
	for (int i = fillCount; i < 10; ++i) {
		hpBar += " ";
	}

	ClearScreen();
	cout << "==================================================\n";
	cout << "	       [ " << room->name_ << " (" << floor << "층) ]\n";
	cout << "==================================================\n";
	cout << "     이름 : " << monster->GetName() << "\t\t   레벨 : Lv. " << monster->GetLevel() << "\n\n\n";

		// 몬스터 이미지 출력

		//

	cout << "--------------------------------------------------\n";
	cout << "              [ 몬스터 능력치 (Stats) ]           \n";
	cout << "           • HP    : " << hpBar << " " << currentHp << " / " << maxHp << "\n";
	cout << "           • Power : " << monster->GetAttack() << "\n";
	cout << "==================================================\n";
	cout << "               [ 행동을 선택하세요! ]            \n\n";
	cout << "  1. 기본 공격   2. 스킬   3. 인벤토리   4. 용병  \n\n";
	cout << "==================================================\n";
	cout << "▶ 행동을 선택하세요: ";
}

void LogManager::PrintDungeonProgressOption(Room*& room, int floor)
{
	ClearScreen();
	cout << room->name_ << " " << floor << "층 클리어!\n";
	cout << "==================================================\n";
	cout << "               [ 행동을 선택하세요! ]            \n\n";
	cout << "  1. 현재 층 재도전\n";
	cout << "  2. 다음 층으로\n";
	cout << "  0. 던전 떠나기\n";
	cout << "==================================================\n";
	cout << "▶ 행동을 선택하세요: ";
}

void LogManager::PrintDungeonReward(const std::string& item, int gold, int exp)
{
	// 보상 뭔지 출력

}

