#include "BreakableTile.h"
#include <iostream>
BreakableTile::BreakableTile(sf::Vector2f _pos, sf::Vector2f _size, bool isTrans) : pos(_pos), size(_size), isTransparent(isTrans){
	hitbox.setPosition(pos);
	hitbox.setSize(size);
	hitbox.setFillColor(sf::Color::White);
}


void BreakableTile::render(sf::RenderWindow& window) const {
	window.draw(hitbox);
}
/*
void BreakableTile::update(float deltaTime, Player* player) {
	rect rd = { player->getPos(), player->getSize(), player->getVel() };
	rect rs = { pos, size };
	dir collisionDir = dirDynamicRectVsRect(rd, deltaTime, rs);
	if (collisionDir == NO_COLLIDE) return;
	if (collisionDir == TOP) std::cout << "TOP\n";
	if (collisionDir == BOTTOM) std::cout << "BOTTOM\n";
	if (collisionDir == LEFT) std::cout << "LEFT\n";
	if (collisionDir == RIGHT) std::cout << "RIGHT\n";
}*/

void BreakableTile::update(float deltaTime) {};

sf::RectangleShape& BreakableTile::getHitbox() {
	return hitbox;
}


sf::Vector2f BreakableTile::getPos() const {
	return pos;
}
sf::Vector2f BreakableTile::getSize() const {
	return size;
}

void BreakableTile::setPos(sf::Vector2f npos) {
	pos = npos;
	hitbox.setPosition(pos);
}
void BreakableTile::setSize(sf::Vector2f nsize) {
	size = nsize;
	hitbox.setPosition(size);
}

Collision::rect BreakableTile::getRect() const {
	return rect{ pos, size };
}
