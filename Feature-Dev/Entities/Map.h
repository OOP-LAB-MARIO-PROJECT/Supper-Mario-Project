#pragma once

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
#include "Enemies/SimpleTestingEnemy.h"
//#include "Enemy/Enemy.h"



class Player;

class Map {
private:

	int m_row = 0;
	int m_col = 0;
	int m_block_size = 1;

	std::vector<std::vector<short>> tilesMap;
	std::vector<Tile> map;
	
	std::vector<std::unique_ptr<Collectable>> props;
	std::vector<std::unique_ptr<BreakableTile>> breakableTiles;
	EntityManager myEntities;

	sf::Vector2f playerPos;
	sf::Vector2f playerSize;
	sf::Vector2f playerVel;

public:

	Map() {};
	~Map() {};

	void addTile(const Tile& tile);
	void renderMap(sf::RenderWindow& window);

	std::vector <sf::RectangleShape> getTiles();
	std::vector <sf::RectangleShape> getNearTiles(sf::Vector2f pos);
	
	void loadMap(const std::string& filename, Player* player);
	void resetPlayer(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f vel);
	void update(float deltaTime, sf::Vector2f ppos, sf::Vector2f psize, sf::Vector2f pvel);
	

	// infomation for the actor to get
	sf::Vector2f getPlayerPos() const;
	sf::Vector2f getPlayerSize() const;
	sf::Vector2f getPlayerVel() const;
	bool isTileAt(sf::Vector2f pos) const;

};

