#include "MoveUpTile.h"


void MoveUpTile::update(float deltaTime) {
	
	if (isAnimation) moveUp(deltaTime);
	rect rd = { player->getPos(), player->getSize(), player->getVel() };

	rect rs = getRect();
	dir collisionDir = dirDynamicRectVsRect(rd, deltaTime, rs);
	if (collisionDir == NO_COLLIDE) return;
	if (collisionDir == TOP) std::cout << "TOP\n";
	if (collisionDir == BOTTOM) {
		std::cout << "BOTTOM\n";
		if (!isAnimation)
			isAnimation = true;
	}
	if (collisionDir == LEFT) std::cout << "LEFT\n";
	if (collisionDir == RIGHT) std::cout << "RIGHT\n";


}


MoveUpTile::MoveUpTile(sf::Vector2f _pos, sf::Vector2f _size, bool isTrans, Player* player) : BreakableTile(_pos, _size, isTrans), player(player) {
	getHitbox().setFillColor(sf::Color::Red);
}


void MoveUpTile::moveUp(float deltaTime) {
	if (!isAnimation) return;

	if (frameCount == 0) {
		oldPos = getPos();
	}

	frameCount++;

	if (frameCount < 5) {
		setPos(getPos() + sf::Vector2f({ 0, -5 }));
	}
	else if (frameCount < 10) {
		setPos(getPos() + sf::Vector2f({ 0, 5 }));
	}

	if (frameCount >= 10) {
		frameCount = 0;
		setPos(oldPos);
		isAnimation = false;
	}

}
