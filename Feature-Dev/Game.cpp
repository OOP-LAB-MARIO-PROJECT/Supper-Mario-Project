#include "Game.h"
namespace Navigator
{
	Game::Game(int width, int height, string title)
	{
		_data->window.create(VideoMode(width, height), title, Style::Close | Style::Titlebar);
		_data->machine.addState(StateRef(new SplashState(this->_data)));
		this->run();
	}

	void Game::run()
	{
		float newTime, frameTime, interpolation;	
		float currentTime = _clock.getElapsedTime().asSeconds();
	}
}