#include "Map.h"

void Map::addTile(const Tile& tile) {
	map.push_back(tile);
};

void Map::renderMap(sf::RenderWindow& window) {
	for (const Tile& t : map)
		t.render(window);
};

std::vector <sf::RectangleShape> Map::getTiles() {
	std::vector <sf::RectangleShape> ans;
	for (Tile t : map) ans.push_back(t.getHitbox());
	return ans;
}

void Map::loadMap(const std::string& filename) {
	
	std::fstream fin(filename);
	
	if (fin.is_open())
		std::cout << "file opened\n";
	else
		std::cout << "file is not opened\n";
	
	int n, m;
	fin >> n >> m;

	sf::Vector2f pos(0, 0);
	std::cout << n << ' ' << m << '\n';

	const int size = 34;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int t;
			fin >> t;

			if (t) {
				pos = { (float)j * size, (float)i * size};
				map.push_back(Tile(pos, { size, size }, false));
			}
		}
	}

	fin.close();
}

std::vector <sf::RectangleShape> Map::getNearTiles(sf::Vector2f pos) {
	std::vector <sf::RectangleShape> tiles;
	for (Tile t : map) {
		sf::Vector2f p = t.getHitbox().getPosition();
		if (std::max(abs(pos.x - p.x), abs(pos.y - p.y)) <= 50)
			tiles.push_back(t.getHitbox());
	}
	return tiles;

}