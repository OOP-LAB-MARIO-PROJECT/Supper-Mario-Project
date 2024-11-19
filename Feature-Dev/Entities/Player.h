#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Actor.h"
#include "Map.h"
#endif

class Map;

class Player : public Actor
{
private:
	// texture incomming
	int health = 0;
	int facing = 1;
	int moving = 0;
	Map* map = NULL;
	bool reachMaxHeight = false;
	bool isJumping = false;

public:

	Player(sf::Vector2f _pos, sf::Vector2f _size);
	void setHealth(int _health);
	void update(float deltatime);
	void setMap(Map* mp) { map = mp; };

	void jump(float dt);
	void notJump();

};

