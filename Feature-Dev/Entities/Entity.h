#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
	bool _isDead = false;
public:
	void kill() { _isDead = true; };
	bool isDead() const { return _isDead; }
	virtual ~Entity() = default;
	virtual void render(sf::RenderWindow& window) const = 0;
	virtual void update(float deltaTime) = 0;
};

