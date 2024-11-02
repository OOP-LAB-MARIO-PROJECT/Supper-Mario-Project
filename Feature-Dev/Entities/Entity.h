#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual ~Entity() = default;
	virtual void render(sf::RenderWindow& window) const = 0;
	virtual void update(float deltaTime) = 0;
};

