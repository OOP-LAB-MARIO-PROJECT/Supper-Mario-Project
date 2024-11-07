//#include "Game.h"
//namespace Navigator
//{
//	Game::Game(int width, int height, string title)
//	{
//		_data->window.create(VideoMode(width, height), title, Style::Close | Style::Titlebar);
//		this->run();
//	}
//
//	void Game::run()
//	{
//		float newTime, frameTime, interpolation;
//		float currentTime = _clock.getElapsedTime().asSeconds(); //the amount of time since the clock has started
//		float accumulator = 0.0f;
//
//		while (_data->window.isOpen())
//		{
//			_data->machine.processStateChanges(); //process any state changes
//			newTime = _clock.getElapsedTime().asSeconds(); 
//			frameTime = newTime - currentTime; //the amount of time since the last frame
//			if (frameTime > 0.25f)
//			{
//				frameTime = 0.25f; //restricting it so it wont go too high
//				accumulator += frameTime; //update the total time
//			}
//			while (accumulator >= dt)
//			{
//				_data->machine.getActiveState()->handleInput(); //handle input
//				_data->machine.getActiveState()->update(dt); //update the game
//				accumulator -= dt; //decrement the accumulator
//			}
//
//			interpolation = accumulator / dt; //interpolation
//			_data->machine.getActiveState()->draw(interpolation); //draw the game
//		}
//	}
//}