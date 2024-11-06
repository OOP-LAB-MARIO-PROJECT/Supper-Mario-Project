#include "GameController.h"
#include "../Entities/Entity.h"
#include "Commands/PlayerMovement.h"

void GameController::startGame() {

	//std::cout << player << '\n';

	myCommand.setMoveLeft(new MoveLeft(player));
	myCommand.setMoveRight(new MoveRight(player));
	myCommand.setMoveUp(new MoveUp(player));
	myCommand.setMoveDown(new MoveDown(player));
	myCommand.setJump(new Jump(player));

	keyHandler.addCommand(sf::Keyboard::A, myCommand.getMvLeft());
	keyHandler.addCommand(sf::Keyboard::D, myCommand.getMvRight());
	keyHandler.addCommand(sf::Keyboard::S, myCommand.getMvDown());
	keyHandler.addCommand(sf::Keyboard::W, myCommand.getMvUp());
	keyHandler.addCommand(sf::Keyboard::H, myCommand.getJump());

	// load map from class map

}

void GameController::update(sf::Event& event, float deltaTime) {
	myCommand.setDeltaTime(deltaTime);
	keyHandler.handleInput();
	player->update(deltaTime);
}

void GameController::render(sf::RenderWindow& window) {
	//std::cout << "rendering\n";
	player->render(window);
	myMap->renderMap(window);
	//std::cout << "rendered\n";
}


void GameController::addEntity(std::shared_ptr<Entity> entity) {
//    entities.push_back(entity);
}

void GameController::setPlayer(Player* _player) {
	player = _player;
}

void GameController::setMap(Map* map) {
	myMap = map;
}

