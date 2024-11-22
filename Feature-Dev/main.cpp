#include <SFML/Graphics.hpp>
#include "Game/GameController.h"
#include "Entities/Actor.h"
#include "Entities/Map.h"
#include "Entities/Player.h"
#include "Utils/Camera.h"
#include "Utils/SoundManager.h"
#include <iostream>
#include "Utils/NavigationManager.h"
#include "Button.h"
#include "Utils/GameManager.h"
#include "../Feature-Dev/Utils/MainMenu.h"
int main()
{
    // create the window

    ///// Do not touch
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);
    ///// End do not touch

    // Tạo đối tượng SoundManager
    SoundManager soundManager;

    // Thêm các âm thanh cần thiết
    if (!soundManager.addSound("background_music", "Assets/sounds/background.wav")) {
        std::cerr << "Failed to load background music.\n";
    }
    if (!soundManager.addSound("jump_sound", "Assets/sounds/jump.wav")) {
        std::cerr << "Failed to load jump sound.\n";
    }

    // Phát nhạc nền (lặp lại)
    soundManager.playSound("background_music", true);
	//set default screen
	NavigationManager::getInstance().navigate(NavigationManager::Screen::MainMenu); // Default screen
    //// init game
	GameManager gameManager;
	gameManager.init(window);

    sf::Clock clock;
    clock.restart();
	//Create main menu
    MainMenu mainMenu;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
		switch (NavigationManager::getInstance().getCurrentScreen())
		{
		    case NavigationManager::Screen::MainMenu:
			    mainMenu.loopEvents();
			    mainMenu.drawMenu();
			    break;
		    case NavigationManager::Screen::Start:
				mainMenu.getWindow()->close();
                soundManager.playSound("jump_sound");
				gameManager.play(deltaTime);
                break;
			case NavigationManager::Screen::Exit:
				window.close();
				break;
		}
    }
    ///// End do not touch

    return 0;
}