#include "Actor.h"

void Actor::render(sf::RenderWindow& window) const {
	std::cout << "Rendering player!" << std::endl;
	window.draw(rect);
}


Actor::Actor(sf::Vector2f _pos, sf::Vector2f _vel, sf::Vector2f _size) :
	pos(_pos), vel(_vel), size(_size) 
{
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(pos);
	rect.setSize(size);
};


void Actor::setPos(sf::Vector2f _pos) {
	pos = _pos;
	rect.setPosition(pos);
}

void Actor::setVel(sf::Vector2f _vel) {
	vel = _vel;
}

void Actor::setSize(sf::Vector2f _size) {
	size = _size;
}

sf::Vector2f Actor::getPos() const {
	return pos;
}