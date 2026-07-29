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

void GameManager::Render()
{
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
		Render();
	}
}
