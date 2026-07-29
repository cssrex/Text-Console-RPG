#include "Global.h"
#include "GameManager.h"
#include "LogManager.h"

int main()
{
	GameManager::GetInstance().GameLoop();
	
	return 0;
}