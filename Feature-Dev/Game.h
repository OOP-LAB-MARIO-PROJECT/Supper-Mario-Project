#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
using namespace sf;
using namespace std;
namespace Navigator
{
	struct GameData
	{
		StateMachine machine;
		RenderWindow window;
	};
	typedef std::shared_ptr<GameData> GameDataRef; //used to access to the game data
	class Game
	{
	public: 
		Game(int width, int height, string title);
	private:
		const float dt = 1.0f / 60.0f; //delta time timeframe
		Clock _clock; //for handling framerate
		GameDataRef _data = make_shared<GameData>(); //pointer to the game data
		void run();
	};

}
