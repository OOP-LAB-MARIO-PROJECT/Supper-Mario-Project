#pragma once
#include "Actor.h"

class Player : public Actor
{
private:
	// texture incomming

public:
	int health = 0;
	float speed = 10;
	int facing = 1;

	bool isOnGround = 0;
	Player(sf::Vector2f _pos, sf::Vector2f _vel, sf::Vector2f _size);
	void setHealth(int _health);
	void setSpeed(float _speed);

	int getHealth() const;
	float getSpeed() const;
};

