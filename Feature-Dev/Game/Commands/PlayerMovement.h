#pragma once
#include "Command.h"
#include "../../Entities/Player.h"

class MoveLeft : public Command {
private:

public:
	Player* player;
	float deltaTime;
	MoveLeft(Player* _player) : player(_player), deltaTime(0) {};
	
	void setDeltaTime(float _deltaTime);
	virtual void execute() override;
};


class MoveRight : public Command {
private:
	Player* player;
	float deltaTime;

public:
	MoveRight(Player* _player) : player(_player), deltaTime(0) {};

	void setDeltaTime(float _deltaTime);
	virtual void execute() override;
};

class Jump : public Command {
private:
	Player* player;
	float deltaTime;

public:
	Jump(Player* _player) : player(_player), deltaTime(0) {};

	void setDeltaTime(float _deltaTime);
	virtual void execute() override;
};