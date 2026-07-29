#include "GameManager.h"
#include "LogManager.h"

GameManager::GameManager()
{
	
}

GameManager::~GameManager()
{
}

void GameManager::Update()
{

}


void GameManager::ShowStartMenu()
{
	LogManager::GetInstance().PrintStartMenu();
	while (true)
	{
		int input;
		std::cout << "번호를 입력해주세요 : ";
		cin >> input;
		if (input == 1 || input == 2)
			break;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "번호만 입력해주세요 !\n";
			continue;
		}
	}
}

void GameManager::ShowMainMenu()
{
	
}

void GameManager::EneterDungeon()
{
}

void GameManager::EneterWorkshop()
{
}

GameManager& GameManager::GetInstance()
{
	static GameManager instance;

	return instance;
}

void GameManager::InitializePlayer()
{

}

void GameManager::GameLoop()
{
	InitializePlayer();
	while (true)
	{
		Update();
	}
}
