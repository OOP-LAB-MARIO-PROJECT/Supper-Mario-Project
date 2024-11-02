#pragma once
#include <SFML/Graphics.hpp>

class Command
{
	int cnt = 0;
public:
	virtual ~Command() {};
	virtual void execute() = 0;
	virtual void deExecute() = 0;
};