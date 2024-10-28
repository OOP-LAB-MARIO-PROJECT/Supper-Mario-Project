#pragma once
#include "PlayerMovement.h"

class CommandController
{
public:

	MoveLeft* moveLeftPtr = nullptr;
	MoveRight* moveRightPtr = nullptr;

	void setDeltaTime(float deltaTime) {
		if (moveLeftPtr)
			moveLeftPtr->setDeltaTime(deltaTime);
		
		if (moveRightPtr)
			moveRightPtr->setDeltaTime(deltaTime);
	}

	void setMoveLeft(MoveLeft* ml) {
		moveLeftPtr = ml;
	}
	
	void setMoveRight(MoveRight* ml) {
		moveRightPtr = ml;
	}

	void moveLeft() {
		moveLeftPtr->execute();
	}

	void moveRight() {
		moveRightPtr->execute();
	}

	MoveLeft* getMvLeft() const {
		return moveLeftPtr;
	}

	MoveRight* getMvRight() const {
		return moveRightPtr;
	}
};

