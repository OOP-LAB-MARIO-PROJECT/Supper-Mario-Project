#include "Tile.h"

Tile::Tile(sf::Vector2f _pos, sf::Vector2f _size, bool isTrans) {
	pos = _pos;
	size = _size;
	isTransparent = isTrans;

	hitbox.setPosition(pos);
	hitbox.setSize(size);
	hitbox.setFillColor(sf::Color::Magenta);
	hitbox.setOutlineColor(sf::Color::Blue);
	hitbox.setOutlineThickness(2);
};


sf::RectangleShape& Tile::getHitbox() {
	return hitbox;
}

void Tile::update(float deltaTime) {};

void Tile::render(sf::RenderWindow& window) const {
	window.draw(hitbox);
}
