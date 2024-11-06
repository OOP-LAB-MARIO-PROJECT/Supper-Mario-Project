#include "Player.h"
#include <limits>
void Player::setHealth(int _health) {
	health = _health;
};

Player::Player(sf::Vector2f _pos, sf::Vector2f _size) :
	Actor(_pos, _size) {

};

void Player::update(float deltaTime) {


	if (facing == 0)
		setVel({ 0, getVel().y });


	sf::Vector2f vx = getVel();
	bool isCollide = resolveCollideGround(map->getTiles(), deltaTime);
	if (getPos().y > 800) setVel(sf::Vector2f(getVel().x, 0));
	//if (isCollide) std::cout << "collidiing!!!!!!!1\n";
	isOnGround = isCollide;
	setPos(getPos() + getVel() * deltaTime);
	performPhysics(deltaTime);
}