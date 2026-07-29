#pragma once
#include "Global_Headers.h"

class LogManager;

class GameManager
{
private:


private:
	GameManager();
	~GameManager();
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

private:
	void Update();

private:
	void ShowStartMenu();
	void ShowMainMenu();
	void EneterDungeon();
	void EneterWorkshop();

public:
	static GameManager& GetInstance();

public:
	void InitializePlayer();
	void GameLoop();
};

