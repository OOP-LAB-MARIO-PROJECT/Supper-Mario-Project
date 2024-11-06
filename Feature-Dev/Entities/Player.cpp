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
	int isCollide = resolveCollideGround(map->getNearTiles(getPos()), deltaTime);
	if (getPos().y > 800) setVel(sf::Vector2f(getVel().x, 0));
	//if (isCollide) std::cout << "collidiing!!!!!!!1\n";
	isOnGround = isCollide & (1 << 2);
	
	if (isOnGround)
		setFric({ 10, 0 }), isJumping = false;
	else
		setFric({ 0, 0 });

	setPos(getPos() + getVel() * deltaTime);
	performPhysics(deltaTime);
}


void Player::jump(float dt) {
	if (isOnGround && !isJumping) {
		setVel({ getVel().x, -80 });
		isOnGround = false;
		reachMaxHeight = false;
		isJumping = true;
	}
	else if (isJumping) {
		if (reachMaxHeight) return;
		sf::Vector2f newVel = getVel();
		newVel += sf::Vector2f(0, -500) * dt;
		if (newVel.y < -160.f)
			newVel.y = -160.f, reachMaxHeight = true;
		setVel(newVel);
	}
}