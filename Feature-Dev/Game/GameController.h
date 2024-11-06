#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>


#include "../Entities/Actor.h"
#include "../Entities/PLayer.h"
#include "../Entities/Tile.h"
#include "../Entities/Map.h"

#include "Commands/KeyExecute.h"
#include "Commands/CommandController.h"

#include "../Utils/Collision.h"
#include "../Utils/EntityManager.h"

/*
	Main game logic, singleton instance
*/
class GameController {
private:
	GameController() = default; // Private constructor
	GameController(const GameController&) = delete;
	GameController& operator=(const GameController&) = delete;
	
	KeyExecute keyHandler;
	CommandController myCommand;
	EntityManager myEntityManager;


	Player* player = NULL;
	Map* myMap = NULL;

public:


	static GameController& getInstance() {
		static GameController instance;
		return instance;
	}

	~GameController() {};

	void startGame();
	void update(sf::Event& event, float deltaTime);
	void render(sf::RenderWindow& window);
	void setPlayer(Player* player);
	void setMap(Map* map);
};
