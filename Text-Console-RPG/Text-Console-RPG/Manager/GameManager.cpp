#include "GameManager.h"
#include "LogManager.h"
#include "Dungeon.h"
#include "Global.h"
#include "Player.h"
#include "Store.h"
#include "Inventory.h"
#include "MonsterAsciiArt.h"
#include "GameSound.h"

GameManager::GameManager() {
	stores_.push_back(new PotionStore());
	stores_.push_back(new Blacksmith());
	dungeon_ = new Dungeon();
	player_ = nullptr;
	curScene_ = Scene::NONE;
	nextScene_ = Scene::START;
	day_ = 2;
	dayType_ = DayType::MORNING;
	isInputZero_ = false;
}

GameManager::~GameManager() {
	for (int i = 0; i < stores_.size(); ++i) {
		delete stores_[i];
	}
	delete dungeon_;
	delete player_;
}

void GameManager::Update() {
	ChangeScene();
}

void GameManager::ChangeDayType() {
	if (dayType_ == DayType::MORNING) {
		dayType_ = DayType::NIGHT;
	}
	else {
		SubDays();
		dayType_ = DayType::MORNING;
	}
}

DayType GameManager::GetDayType() const
{
	return dayType_;
}

int GameManager::GetDay() const
{
	return day_;
}

bool GameManager::EndDay()
{
	return day_ < 0;
}

void GameManager::SubDays()
{
	day_--;
}

void GameManager::StartMenu() {
	LogManager::GetInstance().PrintStartMenu();
	string name;
	cin >> name;
	InitializePlayer(name);
	//LogManager::GetInstance().PrintPrologue();
	SetNextScene(Scene::MAIN);

}

void GameManager::ShowMainMenu() {
	int num;
	while (true) {
		if (dayType_ == DayType::MORNING) GameSound::PlayStartAdventureBgmLoop();
		else GameSound::PlayTownNightBgmLoop();
		system("cls");
		LogManager::GetInstance().PrintMainMenu();
		cout << "▶ 번호를 입력해주세요 : ";
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			cout << "숫자만 입력 해주세요 !\n";
			continue;
		}
		if (num < 0 && num > 5)
			continue;

		if (dayType_ == DayType::NIGHT && num == 1)
		{
			std::cout << "밤에는 던전에 입장 할 수 없습니다.\n";
			system("pause");
			continue;
		}
		
		switch (num) {
		case 0: {
			isInputZero_ = true;
			SetNextScene(Scene::END);
			return;
		}
		case 1: {
			SetNextScene(Scene::DUNGEON);
			return;
		}
		case 2: {
			SetNextScene(Scene::STORE);
			return;
		}
		case 3: {
			SetNextScene(Scene::HOTEL);
			return;
		}
		case 4: {
			if (player_ != nullptr) {
				player_->PrintStatus();
			}
			else {
				cout << "플레이어 정보를 찾을 수 없습니다.\n";
			}
			cout << "\n▶ 메뉴로 돌아가려면 Enter 키를 누르세요";
			cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			PrintPlayerInfoAsciiArt(60, -1);
			string dummy;
			getline(cin, dummy);
			break;
		}
		case 5: {
			if (player_ != nullptr) {
				
				player_->GetInventory()->InventoryMenu(*player_);
			}
			break;
		}
		}
	}

	
}

void GameManager::EnterDungeon() {
	bool change = dungeon_->StartDungeonLoop(player_);
	if (change) {
		ChangeDayType();
	}
}

void GameManager::EnterHotel() {
	LogManager::GetInstance().PrintHotelMenu();
	system("pause"); // 여관 날짜 확인용도
	if (dayType_ == DayType::NIGHT)
	{
		ChangeDayType();
	}
	else
	{
		SubDays();
	}

	if (EndDay())
	{
		SetNextScene(Scene::END);
		return;
	}
	LogManager::GetInstance().PrintPassDay();
	player_->Heal(player_->GetMaxHp());
	player_->HealMp(player_->GetMaxMp());
	SetNextScene(Scene::MAIN);
	system("pause");
}

void GameManager::EnterStore() {
	int index;
	while (true) {
		system("cls");
		LogManager::GetInstance().PrintStoreMenu();
		cout << "▶ 번호를 입력해주세요 : ";
		cin >> index;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			cout << "숫자만 입력 해주세요 !\n";
			system("pause");
			continue;
		}
		if (index < 0 || index > 2)
			continue;

		if (index == 0) {
			SetNextScene(Scene::MAIN);
			return;
		}

		stores_[index - 1]->StoreMenu(*player_, *player_->GetInventory());
	}
}

void GameManager::SetNextScene(Scene newScene) {
	nextScene_ = newScene;
}

void GameManager::ChangeScene() {
	if (curScene_ == nextScene_)
		return;

	curScene_ = nextScene_;
	switch (curScene_)
	{
	case Scene::START:
		StartMenu();
		break;
	case Scene::MAIN:
		ShowMainMenu();
		break;
	case Scene::DUNGEON:
		EnterDungeon();
		break;
	case Scene::HOTEL:
		EnterHotel();
		break;
	case Scene::STORE:
		EnterStore();
		break;
	case Scene::END:
	{
		if (day_ <= 0)
		{
			LogManager::GetInstance().PrintDayOver();
		}
		else if (isInputZero_)
		{
		
		}
		else
		{
			LogManager::GetInstance().PrintGameClear();
		}
		dungeon_->PrintKilledMonsterList();
		system("pause");
		break;
	}
	}
	system("cls");
}

GameManager& GameManager::GetInstance() {
	static GameManager instance;

	return instance;
}

Player* GameManager::GetPlayer() {
	return player_;
}

const Player* GameManager::GetPlayer() const {
	return player_;
}

void GameManager::InitializePlayer(string name) {
	player_ = new Player(name);
}

void GameManager::GameLoop() {
	while (curScene_ != Scene::END)
	{
		Update();
	}
}
