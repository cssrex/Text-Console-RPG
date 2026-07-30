#include "GameManager.h"
#include "LogManager.h"
#include "Dungeon.h"
#include "Global.h"
#include "Player.h"

GameManager::GameManager() {
	player_ = nullptr;
	curScene_ = Scene::NONE;
	nextScene_ = Scene::START;
	days_ = 0;
}

GameManager::~GameManager() {
}

void GameManager::Update() {
	ChangeScene();
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
		break;
	}
	case 5: {
		// 인벤토리
		break;
	}
	}
}

void GameManager::EnterDungeon() {
	Dungeon::GetInstance().StartDungeonLoop(player_);
}

void GameManager::EnterHotel() {
}

void GameManager::EnterStore() {
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
