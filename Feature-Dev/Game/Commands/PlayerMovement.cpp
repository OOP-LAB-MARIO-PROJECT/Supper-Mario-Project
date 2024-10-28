#include "PlayerMovement.h"
#include <iostream>

void MoveLeft::setDeltaTime(float _deltaTime) {
	deltaTime = _deltaTime;
}

void MoveLeft::execute() {
	std::cout << "old pos " << player->getPos().x << ' ' << player->getPos().y << '\n';
	player->setPos(player->getPos() + player->getSpeed() * sf::Vector2f(-1, 0));
	std::cout << "new pos " << player->getPos().x << ' ' << player->getPos().y << '\n';
}


void MoveRight::setDeltaTime(float _deltaTime) {
	deltaTime = _deltaTime;
}

void MoveRight::execute() {
	std::cout << "old pos " << player->getPos().x << ' ' << player->getPos().y << '\n';
	player->setPos(player->getPos() + player->getSpeed() * sf::Vector2f(1, 0));

	std::cout << "new pos " << player->getPos().x << ' ' << player->getPos().y << '\n';
}