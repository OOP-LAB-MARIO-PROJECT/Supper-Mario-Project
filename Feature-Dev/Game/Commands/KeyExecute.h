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

	Command* getInput(const sf::Event& event) {
		if (event.type != sf::Event::KeyPressed) return nullptr;
		int code = event.key.code;
		if (!mp.count(code)) return nullptr;
		return mp[code];
	}

	// add a command with a keyboard code
	void addCommand(int code, Command* command) {
		mp[code] = command;
	}

	void handleInput(const sf::Event& event) {
		std::cout << "not suiiiiii\n";
		Command* input = getInput(event);
		if (input == nullptr) return;

		std::cout << "suiiiiii\n";
		input->execute();
	}
};

