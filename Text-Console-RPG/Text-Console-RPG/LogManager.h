#pragma once
#include <iostream>
using namespace std;

class LogManager
{
private:

private:
	LogManager();
	~LogManager();
	LogManager(const LogManager&) = delete;
	LogManager& operator=(const LogManager&) = delete;

public:
	void PrintInitializeCharacter();
	void PrintStartMenu();
	void PrintMainMenu();
	void PrintWorkshopMenu();
	void PrintDungeonMenu();

public:
	static LogManager& GetInstance();
};

