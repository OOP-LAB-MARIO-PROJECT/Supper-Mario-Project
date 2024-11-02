#pragma once
#include "Entity.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Utils/Physics.h"
#include "../Utils/Collision.h"
#include <vector>
// every enetities


class Actor : public Entity, public Collision, public Physics {
private: 

	sf::RectangleShape rect;
	sf::Vector2f pos;
	sf::Vector2f size;
protected:
	bool isOnGround = false;
	int facing = 0;

public:

	Actor(sf::Vector2f _pos, sf::Vector2f _size);
	Actor() {};

	void render(sf::RenderWindow& window) const override;
	void setPos(sf::Vector2f pos);
	void setSize(sf::Vector2f size);
	bool resolveCollideGround(std::vector <sf::RectangleShape> vi, float deltaTime);

	sf::RectangleShape& getHitbox();
	sf::Vector2f getPos() const;
	

	void moveLeft(float dt);
	void moveRight(float dt);
	void jump(float dt);
};

