#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>


#include "../Entities/Actor.h"
#include "../Entities/PLayer.h"
#include "Commands/KeyExecute.h"
#include "Commands/CommandController.h"
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

	Player * player = NULL;
	
public:
	static GameController& getInstance() {
		static GameController instance;
		return instance;
	}

	void startGame();
	void update(sf::Event& event, float deltaTime);
	void render(sf::RenderWindow& window);

	void addEntity(std::shared_ptr<Entity> entity);
	void setPlayer(Player* player);
};
