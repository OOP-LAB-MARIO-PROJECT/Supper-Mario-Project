#include "NavigationManager.h"
NavigationManager& NavigationManager::getInstance()
{
	static NavigationManager instance;
	return instance;
}

NavigationManager::Screen NavigationManager::getCurrentScreen() const
{
	return currentScreen;
}
void NavigationManager::navigate(Screen screen, GameController& game, MainMenu& menu)
{
	currentScreen = screen;
	switch (currentScreen) 
	{
	case Screen::MainMenu:
		game.startGame();
		break;
	default:
		break;
	}
}
