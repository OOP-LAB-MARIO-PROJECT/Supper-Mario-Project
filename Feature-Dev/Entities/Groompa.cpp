#include "Groompa.h"
#include <limits>


Groompa::Groompa(sf::Vector2f _pos, sf::Vector2f _size, Map* _map) : Actor(_pos, _size) {
	setVel({ 100, 0 });
	facing = 1;
	map = _map;
	getHitbox().setFillColor(sf::Color::Blue);
};

void Groompa::update(float deltaTime) { // basic logic

	//std::cout << "groompa is udating";
	
	// basic behavior -> touch wall will change direction
	if (facing == 1) setVel({ 100, getVel().y });
	if (facing == -1) setVel({ -100, getVel().y });

	sf::Vector2f vx = getVel();
	int isCollide = resolveCollideGround(map->getNearTiles(getPos()), deltaTime);

	if (getPos().y > 800) isDead = true, setVel(sf::Vector2f(getVel().x, 0));
	//if (isCollide) std::cout << "collidiing!!!!!!!1\n";
	isOnGround = isCollide & (1 << 2);

	if (isOnGround)
		setFric({ 10, 0 });
	else
		setFric({ 0, 0 });

	setPos(getPos() + getVel() * deltaTime);

	if (isCollide & 5) // touch top or bottom
		setVel({ getVel().x, 0 });
	//std::cout << isCollide << '\n';
	if (isCollide & 8) facing = 1, setVel({ 100, getVel().y});
	if (isCollide & 2) facing = -1, setVel({ -100, getVel().y });	
	performPhysics(deltaTime);
}
