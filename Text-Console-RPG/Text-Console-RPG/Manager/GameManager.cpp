#include "GameManager.h"
#include "LogManager.h"
#include "Global.h"
#include "Player.h"

GameManager::GameManager()
{
	curScene_ = Scene::START;
	nextScene_ = curScene_;
}

GameManager::~GameManager()
{
}

void GameManager::Update()
{
	ChangeScene();
}

void GameManager::StartMenu()
{
	LogManager::GetInstance().PrintStartMenu();
	string name;
	cin >> name;
	InitializePlayer(name);
}

void GameManager::ShowMainMenu()
{
	
}

void GameManager::EnterDungeon()
{
}

void GameManager::EnterStore()
{
}

void GameManager::SetNextScene(Scene newScene)
{
	nextScene_ = newScene;
}

void GameManager::ChangeScene()
{
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
	case Scene::WORKSHOP:
		EnterStore();
		break;
	case Scene::END:
		break;
	}
}

GameManager& GameManager::GetInstance()
{
	static GameManager instance;

	return instance;
}

Player* GameManager::GetPlayer()
{
	return player_;
}

void GameManager::InitializePlayer(const string& name)
{
	player_ = new Player(name);
}

void GameManager::GameLoop()
{
	while (curScene_ != Scene::END)
	{
		Update();
	}
}
