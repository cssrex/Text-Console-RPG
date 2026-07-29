#pragma once
#include "Enums.h"

class LogManager;
class Player;

class GameManager
{
private:
	Player* player_;
	Scene	curScene_;
	Scene   nextScene_;

private:
	GameManager();
	~GameManager();
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

public:
	void Update();

public:
	void StartMenu();
	void ShowMainMenu();
	void EnterDungeon();
	void EnterStore();
	void SetNextScene(Scene newScene);
	void ChangeScene();

public:
	static GameManager& GetInstance();
	Player* GetPlayer();
public:
	void InitializePlayer(const string& name);
	void GameLoop();
};

