#include "LogManager.h"
#include "Global.h"
#include "GameManager.h"
#include "Player.h"
#include "Dungeon.h"
#include "Monster.h"
#include "SceneAsciiArt.h"
#include "Utils.h"
#include <limits>
#include "GameSound.h"

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

void LogManager::PrintPrologue() {
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	string dummy;
	PrintKnightDream_1AsciiArt();
	GameSound::PlayPrologueBgm();
	cout << ".======================================================================================================================.\n";
	Sleep(1000);
	cout << " 밤, 마을 어귀. 갑옷은 반쯤 부서지고, 걸음마다 피가 배어나온다. \n";
	Sleep(1000);
	cout << "아무도 그를 알아보지 못한다. 그가 누구인지, 어디서 왔는지도. ";
	Sleep(2000);
	cout << "\n▶ 다음으로 넘아가려면 Enter 키를 누르세요";
	getline(cin, dummy);
	LogManager::ClearScreen();
	PrintKnightDream_2AsciiArt();
	cout << ".======================================================================================================================.\n";
	Sleep(1000);
	cout << " 기사는 투구를 벗는다. 드러난 얼굴은 - 나다. 다만 더 늙어있고 많이 지쳐보인다. \n";
	Sleep(1000);
	cout << "\" 놀라지 마라. 나는... 한 달 뒤의 너다. \"";
	Sleep(2000);
	cout << "\n▶ 다음으로 넘아가려면 Enter 키를 누르세요";
	getline(cin, dummy);
	LogManager::ClearScreen();
	PrintDragonPortraitAsciiArt();
	cout << ".======================================================================================================================.\n";
	Sleep(1000);
	cout << "\" 용을 죽였다. 하지만 그땐 이미 늦었어. 마을에는... 아무것도 남지 않았다. \"";
	Sleep(2000);
	cout << "\n▶ 다음으로 넘아가려면 Enter 키를 누르세요";
	getline(cin, dummy);
	LogManager::ClearScreen();
	PrintVillageRuinsAsciiArt();
	cout << ".======================================================================================================================.\n";
	Sleep(1000);
	cout << " \" 이번엔 다르다. 너에겐 아직 시간이 있고 내가 알려준 정보가 있으니까. \" \n";
	Sleep(1000);
	cout << "\" 그 지옥같은 불바다를 보고싶지 않다면, 던전으로 가서 강해져라. 그리고 용을 죽여라. \"";
	Sleep(2000);
	cout << "\n▶ 다음으로 넘아가려면 Enter 키를 누르세요";
	getline(cin, dummy);
	LogManager::ClearScreen();
	PrintKnightDream_2AsciiArt();
	cout << ".======================================================================================================================.\n";
	cout << "\" 부탁한다.. 이번엔 ... 지켜줘..  \"\n";
	Sleep(1000);
	cout << " 그는, 아무 흔적도 없이 사라졌다. ";
	Sleep(2000);
	cout << "\n▶ 다음으로 넘아가려면 Enter 키를 누르세요";
	getline(cin, dummy);
	LogManager::ClearScreen();
}


void LogManager::PrintMainMenu() {
	if (GameManager::GetInstance().GetDayType() == DayType::MORNING) PrintTownScene();
	else PrintTownScene(true);
	int day = GameManager::GetInstance().GetDay();
	Utils::MoveCursorTo(1, 1);
	if (day == 0)
	{
		std::cout << "D - Day";
	}
	else
	{
		std::cout << "D - " << day;
	}
	Utils::MoveCursorTo(0, 15);
	cout << R"(
+======================================================================================================================+
|                                                                                                                      |
|                               1. 던전 입장          2. 상점             3. 여관                                      |
|                                                                                                                      |
|                               4. 플레이어 정보      5. 인벤토리         0. 게임 종료                                 |
|                                                                                                                      |
+======================================================================================================================+
)";
}

void LogManager::PrintHotelMenu() {
	PrintHouseAsciiArt();
}

void LogManager::PrintRemoveAllStatusEffect(std::string name)
{
}

void LogManager::PrintStoreMenu() {
	PrintShopMainAsciiArt();
	cout << R"(
+======================================================================================================================+
|                                                                                                                      |
|                                1. 포션 상점          2. 대장간          0. 나가기                                    |
|                                                                                                                      |
+======================================================================================================================+
)";
}

void LogManager::PrintDungeonMenu() {
	PrintDungeonEntranceAsciiArt();
	cout << R"(
+======================================================================================================================+
|                                                                                                                      |
|                                1. 슬라임 던전        2. 고블린 던전        3. 오크 던전                              |
|                                                                                                                      |
|                                4. 드래곤 던전        0. 나가기                                                       |
|                                                                                                                      |
+======================================================================================================================+
)";
}

void LogManager::PrintPassDay()
{
	int day = GameManager::GetInstance().GetDay();
	std::cout << "여관에서 쉬어갑니다. 하루가 지났습니다 ! ( " << day + 1 << " -> " << day << " )\n";
}

void LogManager::PrintDayOver() {
	PrintTimeoutEndingAsciiArt();
}

void LogManager::PrintGameClear() {
	PrintGameClearEndingAsciiArt();
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
	system("pause > nul");
}

// 캐릭터 (Character) 관련
void LogManager::PrintTakeDamage(const string& name, int damage, int currentHp, int maxHp) {
	cout << name << "이(가) " << damage << "의 피해를 입었습니다. (남은 HP: " << currentHp << " / " << maxHp << ")\n";
}

void LogManager::PrintHeal(const string& name, int value) {
	cout << name << "의 체력이 " << value << "만큼 회복되었습니다.\n";
}

void LogManager::PrintMpHeal(const string& name, int value) {
	cout << name << "의 MP가 " << value << "만큼 회복되었습니다.\n";
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
	int hp, int maxHp, int mp, int maxMp, int attack, int defense, int bonusAttack, int bonusDefense,
	const string& weaponName,
	const string& helmetName,
	const string& armorName,
	const string& glovesName,
	const string& bootsName) {

	int expPercent = (maxExp > 0) ? (exp * 100 / maxExp) : 0;
	string expBar = "";
	int expBlocks = expPercent / 20;
	for (int i = 0; i < 5; ++i) {
		expBar += (i < expBlocks) ? "■" : "□";
	}

	string hpBar = MakeGaugeBar(hp, maxHp, 20);
	string mpBar = MakeGaugeBar(mp, maxMp, 20);

	cout << "==================================================\n";
	cout << "                  [ 캐릭터 정보 ]                  \n";
	cout << "==================================================\n";
	cout << "  이름 : " << left << setw(23) << name << "직업 : 모험가\n";
	cout << "  레벨 : Lv. " << left << setw(17) << level << "경험치 : [" << expBar << "] " << expPercent << "%\n";
	cout << "--------------------------------------------------\n";
	cout << "  [ 기본 능력치 (Stats) ]\n";
	cout << "   • HP      : " << hpBar << " " << right << setw(3) << hp << " / " << setw(3) << maxHp << "\n";
	cout << "   • MP      : " << mpBar << " " << right << setw(3) << mp << " / " << setw(3) << maxMp << "\n";
	cout << "   • Power   : " << attack;
	if (bonusAttack > 0) cout << " (+" << bonusAttack << ")";
	cout << "\n";
	cout << "   • Defense : " << defense;
	if (bonusDefense > 0) cout << " (+" << bonusDefense << ")";
	cout << "\n\n";
	// 착용 중인 장비 출력
	cout << "  [ 착용 장비 ]\n";
	cout << "   • 무기    : " << weaponName << "\n";
	cout << "   • 헬멧    : " << helmetName << "\n";
	cout << "   • 갑옷    : " << armorName << "\n";
	cout << "   • 장갑    : " << glovesName << "\n";
	cout << "   • 신발    : " << bootsName << "\n";
	cout << "--------------------------------------------------\n";
}

void LogManager::PrintSkillListHeader() { cout << "  [ 보유 스킬 (Skills) ]\n"; }
void LogManager::PrintSkillItem(int index, const string& skillName, int cost, const string& description) {
	cout << "   [" << index << "] " << skillName << " (소모 MP : " << cost << ")\n";
	cout << "       - " << description << "\n"; 
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
	system("pause > nul");
}

void LogManager::PrintLevelUp(int oldLevel, int newLevel, int oldMaxHp, int newMaxHp, int oldMaxMp, 
	int newMaxMp, int oldAttack, int newAttack, int oldDefense, int newDefense) {
	std::cout << "\n=========================================\n";
	std::cout << "★ 레벨 업! (Lv. " << oldLevel << " -> Lv. " << newLevel << ") ★\n";
	std::cout << "=========================================\n";
	std::cout << " [최대 HP] " << oldMaxHp << " -> " << newMaxHp << " (+" << (newMaxHp - oldMaxHp) << ")\n";
	std::cout << " [최대 MP] " << oldMaxMp << " -> " << newMaxMp << " (+" << (newMaxMp - oldMaxMp) << ")\n";
	std::cout << " [공격력]   " << oldAttack << " -> " << newAttack << " (+" << (newAttack - oldAttack) << ")\n";
	std::cout << " [방어력]   " << oldDefense << " -> " << newDefense << " (+" << (newDefense - oldDefense) << ")\n";
	std::cout << "=========================================\n";
	std::cout << "※ HP와 MP가 모두 회복되었습니다!\n\n";
	system("pause > nul");
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

// 상태이상 (StatusEffect) 관련
void LogManager::PrintStatusEffectDamage(const string& effectName, const string& targetName, int damage) {
	cout << "[" << effectName << "] 효과 발생! " << targetName << "에게 " << damage << "의 지속 피해를 입깁니다.\n";
}

int GetVisualWidth(const std::string& str) {
	int width = 0;
	for (size_t i = 0; i < str.length(); ) {
		unsigned char c = static_cast<unsigned char>(str[i]);
		if (c < 0x80) {
			width += 1;
			i += 1;
		}
		else {
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
	PrintDungeonEntranceAsciiArt();

	cout << "\n";
	cout << ".======================================================================================================================.\n\n";
	std::string s;
	for (int i = 0; i < roomList.size(); ++i) {
		s += std::to_string(i + 1) + ". " + roomList[i];
		if (i != roomList.size() - 1) s+="    ";
	}
	int visualWidth = GetVisualWidth(s);
	int padding = (120 - visualWidth) / 2;
	for (int i = 0; i < padding; i++) cout << " ";
	cout << s << "\n\n";
	cout << "                                                0. 나가기\n\n";
	cout << ".======================================================================================================================.\n";
	for (int i = 16; i < 22; i++)
	{
		Utils::MoveCursorTo(0, i);
		cout << "|";
		Utils::MoveCursorTo(119, i);
		cout << "|";
	}
	Utils::MoveCursorTo(0, 22);
	cout << "▶ 행동을 선택하세요: ";

}

void LogManager::PrintDungeonBattleMainMenu(Room*& room, int floor, Player*& player, Monster*& monster)
{
	ClearScreen();

	cout << ".======================================================================================================================.\n";
	cout << "|                                                                                                                      |\n";
	cout << ".======================================================================================================================.\n";

	Utils::MoveCursorTo(50, 1);
	cout << "[ " << room->name_ << " (" << floor << "층) ]";
	Utils::MoveCursorTo(0, 3);

	monster->PrintAsciiArt(40, 4);
	PrintDungeonPlayerStatus(player);
	PrintDungeonMonsterStatus(monster);

	for (int i = 3; i < 25; i++)
	{
		Utils::MoveCursorTo(0, i);
		cout << "|";
		Utils::MoveCursorTo(119, i);
		cout << "|";
	}
	Utils::MoveCursorTo(0, 25);

	cout << ".======================================================================================================================.\n";
	cout << "\t\t\t\t\t\t[ 행동을 선택하세요! ]\n";
	cout << "\t\t\t\t   1. 기본 공격       2. 스킬       3. 인벤토리\n";
	cout << ".======================================================================================================================.\n";
	for (int i = 26; i < 28; i++)
	{
		Utils::MoveCursorTo(0, i);
		cout << "|";
		Utils::MoveCursorTo(119, i);
		cout << "|";
	}
	Utils::MoveCursorTo(0, 29);
	cout << "▶ 행동을 선택하세요: ";
}

void LogManager::PrintDungeonBattleMonsterTurn(Room*& room, int floor, Player*& player, Monster*& monster)
{
	ClearScreen();

	cout << ".======================================================================================================================.\n";
	cout << "|                                                                                                                      |\n";
	cout << ".======================================================================================================================.\n";

	Utils::MoveCursorTo(50, 1);
	cout << "[ " << room->name_ << " (" << floor << "층) ]";
	Utils::MoveCursorTo(0, 3);

	monster->PrintAsciiArt(40, 4);
	PrintDungeonPlayerStatus(player);
	PrintDungeonMonsterStatus(monster);

	for (int i = 3; i < 25; i++)
	{
		Utils::MoveCursorTo(0, i);
		cout << "|";
		Utils::MoveCursorTo(119, i);
		cout << "|";
	}
	Utils::MoveCursorTo(0, 25);

	cout << ".======================================================================================================================.\n";
	cout << "\t\t\t\t\t\t[ 몬스터 턴! ]\n";
	cout << "\n";
	cout << ".======================================================================================================================.\n";
	for (int i = 26; i < 28; i++)
	{
		Utils::MoveCursorTo(0, i);
		cout << "|";
		Utils::MoveCursorTo(119, i);
		cout << "|";
	}
	Utils::MoveCursorTo(0, 29);
}

void LogManager::PrintDungeonPlayerStatus(Player*& player)
{
	int playerCurrentHp = player->GetHp();
	int playerMaxHp = player->GetMaxHp();

	int fillCount = 0;
	if (playerMaxHp > 0) {
		fillCount = static_cast<int>((static_cast<double>(playerCurrentHp) / playerMaxHp) * 10.0);
	}

	if (playerCurrentHp > 0 && fillCount == 0) {
		fillCount = 1;
	}

	if (fillCount > 10) fillCount = 10;
	if (fillCount < 0) fillCount = 0;

	string playerHpBar = "";
	for (int i = 0; i < fillCount; ++i) {
		playerHpBar += "█";
	}
	for (int i = fillCount; i < 10; ++i) {
		playerHpBar += " ";
	}

	int playerCurrentMp = player->GetMp();
	int playerMaxMp = player->GetMaxMp();

	fillCount = 0;
	if (playerMaxMp > 0) {
		fillCount = static_cast<int>((static_cast<double>(playerCurrentMp) / playerMaxMp) * 10.0);
	}

	if (playerMaxMp > 0 && fillCount == 0) {
		fillCount = 1;
	}

	if (fillCount > 10) fillCount = 10;
	if (fillCount < 0) fillCount = 0;

	string playerMpBar = "";
	for (int i = 0; i < fillCount; ++i) {
		playerMpBar += "█";
	}
	for (int i = fillCount; i < 10; ++i) {
		playerMpBar += " ";
	}

	Utils::MoveCursorTo(5, 19);
	cout << "[플레이어 정보]";
	Utils::MoveCursorTo(5, 20);
	cout << "이름 : " << player->GetName() << " (Lv." << player->GetLevel() << ")";
	Utils::MoveCursorTo(5, 21);
	cout << "HP   : " << playerHpBar << " " << playerCurrentHp << " / " << playerMaxHp;
	Utils::MoveCursorTo(5, 22);
	cout << "MP   : " << playerMpBar << " " << playerCurrentMp << " / " << playerMaxMp;


}

void LogManager::PrintDungeonMonsterStatus(Monster*& monster)
{
	int monsterCurrentHp = monster->GetHp();
	int monsterMaxHp = monster->GetMaxHp();

	int fillCount = 0;
	if (monsterMaxHp > 0) {
		fillCount = static_cast<int>((static_cast<double>(monsterCurrentHp) / monsterMaxHp) * 10.0);
	}

	if (monsterMaxHp > 0 && fillCount == 0) {
		fillCount = 1;
	}

	if (fillCount > 10) fillCount = 10;
	if (fillCount < 0) fillCount = 0;

	string monsterHpBar = "";
	for (int i = 0; i < fillCount; ++i) {
		monsterHpBar += "█";
	}
	for (int i = fillCount; i < 10; ++i) {
		monsterHpBar += " ";
	}

	Utils::MoveCursorTo(87, 5);
	cout << "[몬스터 정보]";
	Utils::MoveCursorTo(87, 6);
	cout << "이름 : " << monster->GetName() << " (Lv." << monster->GetLevel() << ")";
	Utils::MoveCursorTo(87, 7);
	cout << "HP   : " << monsterHpBar << " " << monsterCurrentHp << " / " << monsterMaxHp;

}

void LogManager::PrintDungeonProgressOption(Room*& room, int floor, const string& rewardItem, int rewardGold, int rewardExp)
{
	ClearScreen();
	cout << ".======================================================================================================================.\n";
	cout << "|                                                                                                                      |\n";
	Utils::MoveCursorTo(47, 1);
	cout << room->name_ << " " << floor << "층 클리어!\n";
	Utils::MoveCursorTo(0, 2);
	PrintDungeonCaveAsciiArt(0, 2);
	cout << "\n";
	cout << ".======================================================================================================================.\n";
	std::string s = rewardItem + " 획득!  " + std::to_string(rewardGold) + "G 획득!  " + std::to_string(rewardExp) + "exp 획득!";
	int visualWidth = GetVisualWidth(s);
	int padding = (120 - visualWidth) / 2;
	for (int i = 0; i < padding; i++) cout << " ";
	cout << s << "\n\n";
	cout << " \t\t\t\t\t\t[ 행동을 선택하세요! ]\n\n";
	cout << " \t\t\t\t\t\t   1. 다음 층으로\n";
	cout << " \t\t\t\t\t\t   0. 던전 떠나기\n\n";
	cout << ".======================================================================================================================.\n";
	for (int i = 18; i < 25; i++)
	{
		Utils::MoveCursorTo(0, i);
		cout << "|";
		Utils::MoveCursorTo(119, i);
		cout << "|";
	}
	Utils::MoveCursorTo(0, 26);
	cout << "▶ 행동을 선택하세요: ";
}

void LogManager::PrintDungeonReward(const std::string& item, int gold, int exp)
{
	// 보상 뭔지 출력

}

void LogManager::PrintDungeonKillList(const std::map<std::string, int>& killedMonsterList_)
{
	cout << "\n";
	cout << ".======================================================================================================================.\n";
	cout << "| [몬스터 처치 정보]                                                                                                   |\n";
	for (auto iter = killedMonsterList_.begin(); iter != killedMonsterList_.end(); iter++)
	{
		string line = " * " + iter->first + " : " + to_string(iter->second) + "마리";

		cout << "|" << line;

		if (GetVisualWidth(line) < 118)
		{
			cout << string(118 - GetVisualWidth(line), ' ');
		}

		cout << "|\n";
	}
	cout << ".======================================================================================================================.\n";
}

void LogManager::PrintPotionStoreMenu() {
	cout << PotionShopAscii;
	cout << R"(+======================================================================================================================+
|                                                                                                                      |
|                               1. 구매               2. 판매             0. 돌아가기                                  |
|                                                                                                                      |
+======================================================================================================================+
)";
}

void LogManager::PrintEquipmentStoreMenu() {
	cout << EquipmentShopAscii;
	cout << R"(+======================================================================================================================+
|                                                                                                                      |
|                        1. 구매            2. 판매            3. 강화            0. 돌아가기                          |
|                                                                                                                      |
+======================================================================================================================+
)";
}

void LogManager::PrintDungeonPlayerDeath()
{
	ClearScreen();
	PrintPlayerDeathAsciiArt();
	cout << "\n";
	cout << ".======================================================================================================================.\n\n";
	cout << "                                            ** [플레이어가 사망했습니다] **\n\n";
	cout << "                                       패널티로 레벨이 감소하며, 하루가 지나갑니다.\n\n";
	cout << ".======================================================================================================================.\n";
	for (int i = 16; i < 21; i++)
	{
		Utils::MoveCursorTo(0, i);
		cout << "|";
		Utils::MoveCursorTo(119, i);
		cout << "|";
	}
	Utils::MoveCursorTo(0, 22);

	system("pause > nul");
}

int LogManager::GetDisplayWidth(const std::string& str) const {
	int width = 0;

	for (int i = 0; i < str.size();)
	{
		unsigned char c = str[i];

		if (c >= 0xE0)
		{
			width += 2;
			i += 3;
		}
		else
		{
			width += 1;
			i += 1;
		}
	}

	return width;
}