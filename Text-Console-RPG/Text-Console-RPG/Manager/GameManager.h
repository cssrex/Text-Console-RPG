#pragma once
#include <string>
#include <vector>
#include "Enums.h"

class LogManager;
class Player;
class Dungeon;
class Store;

class GameManager {
private:
	std::vector<Store*> stores_;
	Dungeon*			dungeon_;
	Player*				player_;
	Scene				curScene_;
	Scene				nextScene_;
	int					day_;
	DayType				dayType_;
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
	int GetDay();
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

