#pragma once

class LogManager
{
private:

private:
	LogManager();
	~LogManager();
	LogManager(const LogManager&) = delete;
	LogManager& operator=(const LogManager&) = delete;

	void PrintInitializeCharacter();
	void PrintStartMenu();
	void PrintMainMenu();
	void PrintWorkshopMenu();
	void PrintDungeonMenu();

public:
	static LogManager& GetInstance();
};

