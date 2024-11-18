#pragma once
#include "../Game/GameController.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Camera.h"
#include "../Entities/Map.h"
#include <string>
using namespace std;

class GameManager
{
private:
	GameController* game = NULL;
	vector <string> mapPath;
	int currentMap = 0;
	Camera* camera = NULL;
	Map* gameMap = NULL;
	sf::RenderWindow* window;
	Player* player = NULL;
public:
	~GameManager() {
//		delete game;
		delete camera;
		delete gameMap;
		delete player;

	}

	void init(sf::RenderWindow& window) {
		game = &GameController::getInstance();
        player = new Player(sf::Vector2f(50, 50), sf::Vector2f(32, 32));

        gameMap = new Map();
        gameMap->loadMap("Assets/map.txt", player);

        player->setMap(gameMap);
        game->setPlayer(player);
        game->setMap(gameMap);
        camera = new Camera(window);
        game->startGame();
		this->window = &window;
	}

	void play(float dt) {
        window->clear(sf::Color::Black);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        camera->followPlayer(player->getPos().x, player->getPos().y, player->getHitbox().getSize().x, player->getHitbox().getSize().y);

        camera->setCameraView(*window);

        // clear the window with black color
        game->update(event, dt);
        game->render(*window);
        window->display();

	}
};

