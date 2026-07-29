#pragma once

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
	void Render();

private:
	void ShowMainMenu();
	void EneterDungeon();
	void EneterWorkshop();

public:
	static GameManager& GetInstance();

public:
	void InitializePlayer();
	void GameLoop();
};

