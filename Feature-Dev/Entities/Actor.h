#pragma once
#include "Entity.h"
#include <iostream>
#include <SFML/Graphics.hpp>

// every enetities


class Actor : public Entity {
private: 

	sf::RectangleShape rect;
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f size;
public:

	Actor(sf::Vector2f _pos, sf::Vector2f _vel, sf::Vector2f _size);
	Actor() {};

	void update() override {
		std::cout << "Player updated!" << std::endl;
	}

	void render(sf::RenderWindow& window) const override;

	void setPos(sf::Vector2f _pos);
	void setVel(sf::Vector2f _vel);
	void setSize(sf::Vector2f _size);
	sf::Vector2f getPos() const;

};

