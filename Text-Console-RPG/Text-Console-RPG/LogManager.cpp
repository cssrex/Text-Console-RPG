#include "LogManager.h"
#include "Global_Headers.h"

LogManager::LogManager()
{
	
}

LogManager::~LogManager()
{

}

void LogManager::PrintInitializeCharacter()
{

}

void LogManager::PrintStartMenu()
{
	cout << R"(+======================================================================================================================+
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
|                              _______ ______  __  __ _______     _____  _____   _____                                 |
|                             |__   __|  ____| \ \/ /|__   __|   |  __ \|  __ \ / ____|                                |
|                                | |  | |__     \  /    | |      | |__) | |__) | |  __                                 |
|                                | |  |  __|    /  \    | |      |  _  /|  ___/| | |_ |                                |
|                                | |  | |____  / /\ \   | |      | | \ \| |    | |__| |                                |
|                                |_|  |______|/_/  \_\  |_|      |_|  \_\_|     \_____|                                |
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
+======================================================================================================================+)";
	cout << "1. GAME START\n";
	cout << "2. EXIT\n";
}

void LogManager::PrintMainMenu()
{

}

void LogManager::PrintWorkshopMenu()
{

}

void LogManager::PrintDungeonMenu()
{

}

LogManager& LogManager::GetInstance()
{
	static LogManager instance;

	return instance;
}