#include "Collectable.h"

void Collectable::render(sf::RenderWindow& window) const {
	window.draw(rect);
}

void Collectable::update(float deltaTime) {}
//
//Collision::rect Collectable::getPlayer() const {
//	return { playerInfo->getHitbox().getPosition(), playerInfo->getHitbox().getSize() };
//}
//
//
//sf::Vector2f Collectable::getSize() const {
//	return size;
//}
//
//sf::Vector2f Collectable::getPos() const {
//	return pos;
//}

bool Collectable::isCollideWithPlayer(sf::Vector2f pos, sf::Vector2f size) {
	return rectVsRect({ pos, size }, { this->pos, this->size });
}
