#pragma once
#include "Actor.h"
#include "Map.h"
class Player : public Actor
{
private:
	// texture incomming
	int health = 0;
	int facing = 1;
	int moving = 0;
	Map* map = NULL;

public:

	Player(sf::Vector2f _pos, sf::Vector2f _size);
	void setHealth(int _health);
	void update(float deltatime);
	void setMap(Map* mp) { map = mp; };

};

