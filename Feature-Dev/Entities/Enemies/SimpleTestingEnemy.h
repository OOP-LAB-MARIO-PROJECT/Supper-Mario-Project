

#pragma once

#include <iostream>
#include "Enemy.h"
// simple enemy example, not going if under its foot does not have platform

class Enemy;
class SimpleTestingEnemy : public Enemy {
	int currentFace = 1;
	bool isKilled = false;
public:
	// fixed function
	SimpleTestingEnemy(sf::Vector2f _pos, sf::Vector2f _size, Map* _map);
	void myKillMethod();
	void update(float deltatime);
	void behavior(float detaTime);

	// user define function
	//...
};

