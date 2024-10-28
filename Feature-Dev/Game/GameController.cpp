#include "GameController.h"
#include "../Entities/Entity.h"

void GameController::startGame() {
}

void GameController::update() {
	
}

void GameController::render(sf::RenderWindow& window) {
	std::cout << "rendering\n";
	player->render(window);
	std::cout << "rendered\n";
}


void GameController::addEntity(std::shared_ptr<Entity> entity) {
//    entities.push_back(entity);
}

void GameController::setPlayer(Actor* _player) {
	player = _player;
}

