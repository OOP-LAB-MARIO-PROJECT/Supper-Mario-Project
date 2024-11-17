#pragma once
#ifndef __MOVEUPTILE_H__
#define __MOVEUPTILE_H__

#include "BreakableTile.h"
#include "Player.h"
#endif

class Player;

class MoveUpTile : public BreakableTile {
private:
	Player* player;
	int frameCount = 0;
	sf::Vector2f oldPos = { 0, 0 };
	bool isAnimation = false;
public:
	MoveUpTile(sf::Vector2f _pos, sf::Vector2f _size, bool isTrans = false, Player* player = NULL);
	void update(float deltaTime);
	void moveUp(float deltaTime);
};

