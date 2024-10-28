#include "Player.h"

void Player::setHealth(int _health) {
	health = _health;
};
void Player::setSpeed(float _speed) {
	speed = _speed;
};

int Player::getHealth() const {
	return health;
}

float Player::getSpeed() const {
	return speed;
}

Player::Player(sf::Vector2f _pos, sf::Vector2f _vel, sf::Vector2f _size) :
	Actor(_pos, _vel, _size) {};

