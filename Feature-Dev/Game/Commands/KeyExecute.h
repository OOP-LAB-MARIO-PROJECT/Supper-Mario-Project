#pragma once
#include "Command.h"
#include <map>
#include <iostream>

class KeyExecute
{
	std::map <int, Command*> mp;
public:
	KeyExecute() {};
	~KeyExecute() {
		for (const std::pair <int, Command*>& pc : mp)
			if (pc.second != nullptr)
				delete pc.second;
	};

	// add a command with a keyboard code
	void addCommand(int code, Command* command) {
		mp[code] = command;
	}

	void handleInput() {
		for (const std::pair <int, Command*>& key : mp)
			if (sf::Keyboard::isKeyPressed((sf::Keyboard::Scancode)key.first)) {
				if (mp.count(key.first)) key.second->execute();
			}
			else {
				if (mp.count(key.first)) key.second->deExecute();
			}
	}
};

