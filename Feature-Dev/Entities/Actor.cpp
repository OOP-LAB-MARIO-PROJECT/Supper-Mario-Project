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