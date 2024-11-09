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
	virtual void deExecute() override;

};


class MoveRight : public Command {
private:
	Player* player;
	float deltaTime;

public:
	MoveRight(Player* _player) : player(_player), deltaTime(0) {};

	void setDeltaTime(float _deltaTime);
	virtual void execute() override;
	virtual void deExecute() override;

};


class MoveUp : public Command {
private:
	Player* player;
	float deltaTime;

public:
	MoveUp(Player* _player) : player(_player), deltaTime(0) {};

	void setDeltaTime(float _deltaTime);
	virtual void execute() override;
	virtual void deExecute() override;

};


class MoveDown : public Command {
private:
	Player* player;
	float deltaTime;

public:
	MoveDown(Player* _player) : player(_player), deltaTime(0) {};

	void setDeltaTime(float _deltaTime);
	virtual void execute() override;
	virtual void deExecute() override;
};

class Jump : public Command {
private:
	Player* player;
	float deltaTime;

public:
	Jump(Player* _player) : player(_player), deltaTime(0) {};

	void setDeltaTime(float _deltaTime);
	virtual void execute() override;
	virtual void deExecute() override {};
};