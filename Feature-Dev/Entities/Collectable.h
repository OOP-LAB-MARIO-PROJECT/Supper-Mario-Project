#pragma once
#include "Entity.h"
#include "../Utils/Collision.h"
#include "SFML/Graphics.hpp"
//#include "SFML/Audio.hpp"

class Collectable : public Entity, public Collision
{
private:

	sf::RectangleShape rect;
	sf::Vector2f pos;
	sf::Vector2f size;

public:
	Collectable(sf::Vector2f pos, sf::Vector2f size) : pos(pos), size(size) {
		rect.setPosition(pos);
		rect.setSize(size);
		rect.setFillColor(sf::Color::Yellow);
	
	};
	~Collectable() {};

	void render(sf::RenderWindow& window) const;
	virtual void update(float deltaTime) = 0;
	virtual void applyEffect() = 0;
	//sf::RectangleShape getPlayer() const {};
	bool isCollideWithPlayer(sf::Vector2f pos, sf::Vector2f size);
};

