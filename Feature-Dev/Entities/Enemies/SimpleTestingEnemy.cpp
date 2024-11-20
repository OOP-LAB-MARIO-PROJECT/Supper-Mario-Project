#include "SimpleTestingEnemy.h"
SimpleTestingEnemy::SimpleTestingEnemy(sf::Vector2f _pos, sf::Vector2f _size, Map* _map)  : Enemy(_pos, _size, _map) 
{
	currentFace = 1;
	getHitbox().setFillColor(sf::Color::Cyan);
	setVel({ 100, 0 });
}

void SimpleTestingEnemy::update(float deltatime) {

	if (isDead()) return;
	behavior(deltatime);

	if (!isKilled) {
		sf::Vector2f vx = getVel();
		int isCollide = resolveCollideGround(getNearTiles(getPos()), deltatime);

		if (getPos().y > 800) kill(), setVel(sf::Vector2f(getVel().x, 0));
		isOnGround = isCollide & (1 << 2);

		if (isOnGround)
			setFric({ 10, 0 });
		else
			setFric({ 0, 0 });

		if (isCollide & 8) currentFace = 1; // , setVel({ 100, getVel().y });
		if (isCollide & 2) currentFace = -1; // , setVel({ -100, getVel().y });
	}
	else {
		if (getPos().y > 800) kill(), setVel(sf::Vector2f(getVel().x, 0));
	}
	
	// set behavior

	setPos(getPos() + getVel() * deltatime);
	performPhysics(deltatime);
}

void SimpleTestingEnemy::behavior(float deltatime)  {
	if (isKilled) {



		return;
	}

	if (currentFace) setVel({ speed * currentFace, getVel().y });
	//if (currentFace) setVel({ speed * currentFace, getVel().y });


	sf::Vector2f playerPos = getPlayerPos();
	sf::Vector2f playerSize = getPlayerSize();

	sf::Vector2f pos = getPos();
	Collision::rect myRect{pos, getSize()};
	Collision::rect playerRect{ playerPos, playerSize, getPlayerVel()};



	dir mydir = dirDynamicRectVsRect(playerRect, deltatime, myRect);
	std::cout << mydir << '\n';
	if (mydir == TOP) {
		myKillMethod();
	}

	//sf::Vector2f playerVel = ();
	if (phase == 1) return;

	if (currentFace == 1) {
		if (
			!isTileAt(getPos() + sf::Vector2f(25, 25))
			)
			currentFace = -1;
	}

	if (currentFace == -1) {
		if (!isTileAt(getPos() + sf::Vector2f(-10, 25))
			)
			currentFace = 1;
	}	
}

void SimpleTestingEnemy::myKillMethod() {
	if (phase == 0) {
		phase = 1;
		speed = 200;
		return;
	}

	isKilled = true;
	setVel({ getVel().x, -250 });
}
