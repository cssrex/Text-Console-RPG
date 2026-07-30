#include "Global.h"
#include "GameManager.h"
#include "LogManager.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);

	GameManager::GetInstance().GameLoop();
	
	return 0;
}