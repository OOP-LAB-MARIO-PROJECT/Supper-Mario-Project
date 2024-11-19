#pragma once

#ifndef _GROOMPA_H_
#define _GROOMPA_H_

#include "Actor.h"
#include "Map.h"
#endif

class Map;

class Groompa : public Actor
{
private:
	// texture incomming
	int health = 0;
	int facing = 1;
	int moving = 0;
	Map* map = NULL;
	bool isDead = false;

public:

	Groompa(sf::Vector2f _pos, sf::Vector2f _size, Map* _map);
	//void behavior();
	void update(float deltatime);
	void setMap(Map* mp) { map = mp; };
};

