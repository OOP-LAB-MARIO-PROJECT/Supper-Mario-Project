#pragma once

#include "Tile.h"
#include <vector>

class Map {
private:
	std::vector<Tile> map;
public:

	Map() {};
	~Map() {};

	void addTile(const Tile& tile) {
		map.push_back(tile);
	};

	void renderMap(sf::RenderWindow& window) {
		for (const Tile& t : map)
			t.render(window);
	};

	std::vector <sf::RectangleShape> getTiles() {
		std::vector <sf::RectangleShape> ans;
		for (Tile t : map) ans.push_back(t.getHitbox());
		return ans;
	}
};

