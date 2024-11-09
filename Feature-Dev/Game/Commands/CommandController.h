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

	void setDeltaTime(float deltaTime);

	void setJump(Jump* jm);
	Jump* getJump() const;

	void jump();

	void setMoveLeft(MoveLeft* ml);
	void setMoveRight(MoveRight* ml);
	void setMoveUp(MoveUp* ml);
	void setMoveDown(MoveDown* ml);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	MoveLeft* getMvLeft() const;
	MoveRight* getMvRight() const;
	MoveUp* getMvUp() const;
	MoveDown* getMvDown() const;

};

