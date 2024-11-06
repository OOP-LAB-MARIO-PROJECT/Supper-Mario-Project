#include "Actor.h"

void Actor::render(sf::RenderWindow& window) const {
	//std::cout << "Rendering player!" << std::endl;
	window.draw(rect);
}

Actor::Actor(sf::Vector2f _pos, sf::Vector2f _size) :
	pos(_pos), size(_size), Physics({ 0, 0 }, { 0, 90 })
{
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(pos);
	rect.setSize(size);
	std::cout << "made the player green\n";
};


void Actor::setPos(sf::Vector2f _pos) {
	pos = _pos;
	rect.setPosition(pos);
}

void Actor::setSize(sf::Vector2f _size) {
	size = _size;
	rect.setScale(size);
}

sf::Vector2f Actor::getPos() const {
	return pos;
}

sf::RectangleShape& Actor::getHitbox() {
	return rect;
}

void Actor::moveLeft(float dt) {

	facing = -1;
	setVel({ -70, getVel().y});
}

void Actor::moveRight(float dt) {

	facing = 1;
	setVel({ 70, getVel().y });
}

void Actor::jump(float dt) {
	if (isOnGround) {
		setVel({ getVel().x, -200 });
		isOnGround = false;
	}
}


bool Actor::resolveCollideGround(std::vector <sf::RectangleShape> vi, float deltaTime) {
	
	
	sf::Vector2f pos = getPos();
	sf::Vector2f vel = getVel();
	//std::cout << getVel().x << ' ' << getVel().y << '\n';
	sf::Vector2f expected = rectVsTerain(rect, vi, getVel(), deltaTime, pos);
	if (expected == getVel()) return false;
	/*std::cout << "pos " << getPos().x << ' ' << getPos().y << ' ' << pos.x << ' ' << pos.y << '\n';
	std::cout << "vel " << getVel().x << ' ' << getVel().y << ' ' << expected.x << ' ' << expected.y << '\n';*/

	setVel(expected);
	setPos(pos);
	return true;
}
