#pragma once
#include <string>
#include "Enums.h"

class LogManager;
class Player;

class GameManager {
private:
	Player*		player_;
	Scene		curScene_;
	Scene		nextScene_;
	int			dDays_;
	DayType		dayType_;
private:
	GameManager();
	~GameManager();
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

public:
	void Update();

public:
	void ChangeDayType();
	DayType GetDayType();
	int GetDdays();
	bool EndDay();
private :
	void SubDays();

public:
	void StartMenu();
	void ShowMainMenu();
	void EnterDungeon();
	void EnterHotel();
	void EnterStore();
	void SetNextScene(Scene newScene);
	void ChangeScene();

public:
	static GameManager& GetInstance();
	Player* GetPlayer();
public:
	void InitializePlayer(std::string name);
	void GameLoop();
};

