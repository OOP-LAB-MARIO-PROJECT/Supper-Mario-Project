#include "GameController.h"
#include "../Entities/Entity.h"
#include "Commands/PlayerMovement.h"

void GameController::startGame() {

	std::cout << player << '\n';

	myCommand.setMoveLeft(new MoveLeft(player));
	myCommand.setMoveRight(new MoveRight(player));

	keyHandler.addCommand(sf::Keyboard::A, myCommand.getMvLeft());
	keyHandler.addCommand(sf::Keyboard::D, myCommand.getMvRight());
}

void GameController::update(sf::Event& event, float deltaTime) {
	myCommand.setDeltaTime(deltaTime);
	keyHandler.handleInput(event);
}

void GameController::render(sf::RenderWindow& window) {
	std::cout << "rendering\n";
	player->render(window);
	std::cout << "rendered\n";
}


void GameController::addEntity(std::shared_ptr<Entity> entity) {
//    entities.push_back(entity);
}

void GameController::setPlayer(Player* _player) {
	player = _player;
}

