#pragma once
#include "../Actor.h"
#include <iostream>
/*
	
	// set the map that the enemy are on
	Enemy(sf::Vector2f _pos, sf::Vector2f _size, Map* _map);
	
	// update in respect of time
	void update(float deltatime) = 0;

	// perform the behavior of an enemy
	virtual void behavior() = 0;
*/

class Map;
class Actor;

class Enemy : public Actor
{
	int health = 0;
	int facing = 1;
	Map* map = NULL;

public:

	Enemy(sf::Vector2f _pos, sf::Vector2f _size, Map* _map);

	virtual void update(float deltatime) = 0;
	virtual void behavior(float detatime) = 0;

	void setMap(Map* mp) { map = mp; };


	int getHealth() const {
		return health;
	};
	
	void inflictDamange(int x) { health -= x; };

	// get info of map

	sf::Vector2f getPlayerPos() const;
	sf::Vector2f getPlayerSize() const;
	sf::Vector2f getPlayerVel() const;
	bool isTileAt(sf::Vector2f pos) const;
	std::vector <sf::RectangleShape> getNearTiles(sf::Vector2f pos) const;
};

/*
//
class SimpleTestingEnemy : public Enemy {
	int currentFace = 1;
public:

	SimpleTestingEnemy(sf::Vector2f _pos, sf::Vector2f _size, Map* _map);
	void update(float deltatime) override;
	void behavior() override;
};
*/