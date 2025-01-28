
#include "main.h"
#include <SFML/Graphics.hpp> 
#include "GameManager.h"
#include "iostream"

int main()
{
	srand(time(NULL));
	// Create the game manager and run the game
	GameManager* pGameManager = GameManager::GetInstance();
	pGameManager->Run();
}
