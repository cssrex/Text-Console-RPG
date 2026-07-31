#include "GameManager.h"
#include "LogManager.h"
#include "Dungeon.h"
#include "Global.h"
#include "Player.h"
#include "Store.h"

GameManager::GameManager() {
	stores_.push_back(new PotionStore());
	stores_.push_back(new Blacksmith());
	dungeon_ = new Dungeon();
	player_ = nullptr;
	curScene_ = Scene::NONE;
	nextScene_ = Scene::START;
	dDays_ = 28;
	dayType_ = DayType::MORNING;
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

DayType GameManager::GetDayType()
{
	return dayType_;
}

int GameManager::GetDdays()
{
	return dDays_;
}

bool GameManager::EndDay()
{
	return dDays_ == 0;
}

void GameManager::SubDays()
{
	dDays_--;
}

void GameManager::StartMenu() {
	LogManager::GetInstance().PrintStartMenu();
	string name;
	cin >> name;
	InitializePlayer(name);
	SetNextScene(Scene::MAIN);
}

void GameManager::ShowMainMenu() {
	LogManager::GetInstance().PrintMainMenu();
	int num;
	while (true) {
		cout << "▶ 번호를 입력해주세요 : ";
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			cout << "숫자만 입력 해주세요 !\n";
			continue;
		}
		if (num >= 0 && num < 6)
			break;
	}

	if (dayType_ == DayType::NIGHT && num == 1)
	{
		std::cout << "밤에는 던전에 입장 할 수 없습니다.\n";
		system("pause");
		return;
	}

	switch (num) {
	case 0: {
		SetNextScene(Scene::END);
		break;
	}
	case 1: {
		SetNextScene(Scene::DUNGEON);
		break;
	}
	case 2: {
		SetNextScene(Scene::STORE);
		break;
	}
	case 3: {
		SetNextScene(Scene::HOTEL);
		break;
	}
	case 4: {
		player_->PrintStatus();
		system("pause");
		break;
	}
	case 5: {
		// 인벤토리
		break;
	}
	}
}

void GameManager::EnterDungeon() {
	ChangeDayType();
	LogManager::GetInstance().PrintDungeonMenu();
	dungeon_->StartDungeonLoop(player_);
}

void GameManager::EnterHotel() {
	if (dayType_ == DayType::NIGHT)
	{
		ChangeDayType();
	}

	if (EndDay())
	{
		SetNextScene(Scene::END);
		return;
	}

	LogManager::GetInstance().PrintHotel();

	player_->SetHp(player_->GetHp());
}

void GameManager::EnterStore() {
	LogManager::GetInstance().PrintStoreMenu();
	int index;
	while (true) {
		cout << "▶ 번호를 입력해주세요 : ";
		cin >> index;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			cout << "숫자만 입력 해주세요 !\n";
			continue;
		}
		if (index >= 0 && index < 6)
			break;
	}

	stores_[index - 1]->StoreMenu(*player_, *player_->GetInventory());
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
		break;
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

void GameManager::InitializePlayer(string name) {
	player_ = new Player(name);
}

void GameManager::GameLoop() {
	while (curScene_ != Scene::END)
	{
		Update();
	}
}
