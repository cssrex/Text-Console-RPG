#include "LogManager.h"

LogManager::LogManager()
{
}

LogManager::~LogManager()
{
}

void LogManager::PrintInitializeCharacter()
{
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