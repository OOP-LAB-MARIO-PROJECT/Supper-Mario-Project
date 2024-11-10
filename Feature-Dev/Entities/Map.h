#pragma once

#include "Tile.h"
#include <vector>
#include <fstream>
#include <iostream>

class Map {
private:
	std::vector<Tile> map;
public:

	Map() {};
	~Map() {};

	void addTile(const Tile& tile);
	void renderMap(sf::RenderWindow& window);
	std::vector <sf::RectangleShape> getTiles();

	std::vector <sf::RectangleShape> getNearTiles(sf::Vector2f pos);
	void loadMap(const std::string& filename);

};

