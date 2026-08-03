#include "Global.h"
#include "GameManager.h"
#include "LogManager.h"
#include "GameSound.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	GameManager::GetInstance().GameLoop();
	
	return 0;
}