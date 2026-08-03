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
	bool				isInputZero_;
private:
	GameManager();
	~GameManager();
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

private:
	void Update();

public:
	DayType GetDayType() const;
	int GetDay() const;

private :
	void ChangeDayType();
	void SubDays();
	bool EndDay();

public:
	void SetNextScene(Scene newScene);

private:
	void StartMenu();
	void ShowMainMenu();
	void EnterDungeon();
	void EnterHotel();
	void EnterStore();
	void ChangeScene();

public:
	static GameManager& GetInstance();
	const Player* GetPlayer() const;
	Player* GetPlayer();

public:
	void InitializePlayer(std::string name);
	void GameLoop();
};

