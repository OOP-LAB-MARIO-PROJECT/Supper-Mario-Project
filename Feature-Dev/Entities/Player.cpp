#include "Player.h"
#include <limits>
void Player::setHealth(int _health) {
	health = _health;
};

Player::Player(sf::Vector2f _pos, sf::Vector2f _size) :
	Actor(_pos, _size) {
	setRenderSprite(true);
	setRenderHitbox(false);
	setTexture("mario", "right-small-mario-1");
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
		setFric({ 15, 0 }), isJumping = false;
	else
		setFric({ 0, 0 });

	setPos(getPos() + getVel() * deltaTime);
	setSpritePos(getPos() - sf::Vector2f{ 2, 2 });

	if (isCollide & 5) // touch top or bottom
		setVel({ getVel().x, 0 }), isJumping = false;

	performPhysics(deltaTime);
}


void Player::jump(float dt) {
	if (isOnGround && !isJumping) {
		setVel({ getVel().x, -170 });
		isOnGround = false;
		reachMaxHeight = false;
		isJumping = true;
	}
	else if (isJumping) {
		if (reachMaxHeight) return;
		sf::Vector2f newVel = getVel();
		newVel += sf::Vector2f(0, -40000) * dt;
		if (newVel.y < -178.f)
			newVel.y = -178.f, reachMaxHeight = true;
		setVel(newVel);
	}
}

void Player::notJump() {
	if (!isJumping) return;
	isJumping = false;
	//reachMaxHeight = true;
	setVel({ getVel().x, getVel().y / 3});
	
}