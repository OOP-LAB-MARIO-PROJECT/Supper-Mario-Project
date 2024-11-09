#pragma once

#include "Tile.h"
#include "Collectable.h"
#include "Coin.h"
#include <vector>
#include <set>
#include <fstream>
#include <iostream>
#include <memory>

class Map {
private:
	std::vector<Tile> map;
	std::vector<std::unique_ptr<Collectable>> props ;
	sf::Vector2f playerPos;
	sf::Vector2f playerSize;

public:

	Map() {};
	~Map() {};

	void addTile(const Tile& tile);
	void renderMap(sf::RenderWindow& window);
	std::vector <sf::RectangleShape> getTiles();

	std::vector <sf::RectangleShape> getNearTiles(sf::Vector2f pos);
	void loadMap(const std::string& filename);
	void resetPlayer(sf::Vector2f pos, sf::Vector2f size);

	void update(float deltaTime, sf::Vector2f ppos, sf::Vector2f psize);

};

