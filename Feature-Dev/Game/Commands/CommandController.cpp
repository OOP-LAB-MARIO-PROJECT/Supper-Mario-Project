#include "CommandController.h"


void CommandController::setDeltaTime(float deltaTime) {
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

void CommandController::setJump(Jump* jm) {
	jumpP = jm;
}

Jump* CommandController::getJump() const {
	return jumpP;
}

void CommandController::jump() {
	std::cout << "Jump" << '\n';
	jumpP->execute();
}

void CommandController::setMoveLeft(MoveLeft* ml) {
	moveLeftPtr = ml;
}

void CommandController::setMoveRight(MoveRight* ml) {
	moveRightPtr = ml;
}

void CommandController::setMoveUp(MoveUp* ml) {
	moveUpPtr = ml;
}

void CommandController::setMoveDown(MoveDown* ml) {
	moveDownPtr = ml;
}

void CommandController::moveLeft() {
	moveLeftPtr->execute();
}

void CommandController::moveRight() {
	moveRightPtr->execute();
}

void CommandController::moveUp() {
	moveUpPtr->execute();
}

void CommandController::moveDown() {
	moveDownPtr->execute();
}

MoveLeft* CommandController::getMvLeft() const {
	return moveLeftPtr;
}

MoveRight* CommandController::getMvRight() const {
	return moveRightPtr;
}

MoveUp* CommandController::getMvUp() const {
	return moveUpPtr;
}

MoveDown* CommandController::getMvDown() const {
	return moveDownPtr;
}
