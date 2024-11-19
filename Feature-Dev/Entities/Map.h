#pragma once

#ifndef _MAP_H_
#define _MAP_H_

#include "Tile.h"
#include "Collectable.h"
#include "Coin.h"
#include "BreakableTile.h"
#include "MoveUpTile.h"
#include "../Utils/EntityManager.h"
#include <vector>
#include <set>
#include <fstream>
#include <iostream>
#include <memory>
#include "Player.h"
#include "Groompa.h"



#endif

class Player;

class Map {
private:
	std::vector<Tile> map;
	
	std::vector<std::unique_ptr<Collectable>> props;
	std::vector<std::unique_ptr<BreakableTile>> breakableTiles;
	EntityManager myEntities;

	sf::Vector2f playerPos;
	sf::Vector2f playerSize;

public:

	Map() {};
	~Map() {};

	void addTile(const Tile& tile);
	void renderMap(sf::RenderWindow& window);
	std::vector <sf::RectangleShape> getTiles();

	std::vector <sf::RectangleShape> getNearTiles(sf::Vector2f pos);
	void loadMap(const std::string& filename, Player* player);
	void resetPlayer(sf::Vector2f pos, sf::Vector2f size);

	void update(float deltaTime, sf::Vector2f ppos, sf::Vector2f psize);

};

