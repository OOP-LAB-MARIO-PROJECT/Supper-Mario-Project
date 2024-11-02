#pragma once
#include "PlayerMovement.h"

class CommandController
{
public:

	MoveLeft* moveLeftPtr = nullptr;
	MoveRight* moveRightPtr = nullptr;
	MoveUp* moveUpPtr = nullptr;
	MoveDown* moveDownPtr = nullptr;
	
	Jump* jumpP = nullptr;

	void setDeltaTime(float deltaTime) {
		if (moveLeftPtr)
			moveLeftPtr->setDeltaTime(deltaTime);
		
		if (moveRightPtr)
			moveRightPtr->setDeltaTime(deltaTime);
		
		if (moveUpPtr)
			moveUpPtr->setDeltaTime(deltaTime);

		if (moveDownPtr)
			moveDownPtr->setDeltaTime(deltaTime);
		
		if (jumpP)
			jumpP->setDeltaTime(deltaTime);
	}

	void setJump(Jump* jm) {
		jumpP = jm;
	}

	Jump* getJump() const {
		return jumpP;
	}

	void jump() {
		std::cout << "Jump" << '\n';
		jumpP->execute();
	}

	void setMoveLeft(MoveLeft* ml) {
		moveLeftPtr = ml;
	}
	
	void setMoveRight(MoveRight* ml) {
		moveRightPtr = ml;
	}

	void setMoveUp(MoveUp* ml) {
		moveUpPtr = ml;
	}

	void setMoveDown(MoveDown* ml) {
		moveDownPtr = ml;
	}

	void moveLeft() {
		moveLeftPtr->execute();
	}

	void moveRight() {
		moveRightPtr->execute();
	}

	void moveUp() {
		moveUpPtr->execute();
	}

	void moveDown() {
		moveDownPtr->execute();
	}

	MoveLeft* getMvLeft() const {
		return moveLeftPtr;
	}

	MoveRight* getMvRight() const {
		return moveRightPtr;
	}

	MoveUp* getMvUp() const {
		return moveUpPtr;
	}

	MoveDown* getMvDown() const {
		return moveDownPtr;
	}

};

