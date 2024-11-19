#include "Enemy.h"
#include "../Map.h"

Enemy::Enemy(sf::Vector2f _pos, sf::Vector2f _size, Map* _map) : Actor(_pos, _size) {
	setVel({ 100, 0 });
	facing = 1;
	map = _map;
	getHitbox().setFillColor(sf::Color::Blue);
};


sf::Vector2f Enemy::getPlayerPos() const {
	return map->getPlayerPos();
}

sf::Vector2f Enemy::getPlayerSize() const {
	return map->getPlayerSize();
}

sf::Vector2f Enemy::getPlayerVel() const {
	return map->getPlayerVel();
}

bool Enemy::isTileAt(sf::Vector2f pos) const {
	return map->isTileAt(pos);
}

std::vector <sf::RectangleShape> Enemy::getNearTiles(sf::Vector2f pos) const {
	return map->getNearTiles(pos);
}