//#include <SFML/Graphics.hpp>
//#include "Game/GameController.h"
//#include "Entities/Actor.h"
//#include "Entities/Player.h"
//#include "MainMenu.h"
//#include "NavigationManager.h"
//#include <iostream>
//
//int main()
//{
// //   // create the window
// //   sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
// //   GameController& game = GameController::getInstance();
// //   
// //   //// init game
//
//
// //   Player player(sf::Vector2f(50, 50), sf::Vector2f(0, 10), sf::Vector2f(50, 50));
// //   game.setPlayer(&player);
//
//
//
//
// //   window.setFramerateLimit(60);
// //   
//	//MainMenu mainMenu(game);
// //  
//
//
//
// ////   ////////// game start
// ////   game.startGame();
//
// //   sf::Clock clock;
// //   clock.restart();
//
// //  //  run the program as long as the window is open
// //   while (window.isOpen())
// //   {
//
// //       float deltaTime = clock.restart().asSeconds();
// //       window.clear(sf::Color::Black);
//
// //       // check all the window's events that were triggered since the last iteration of the loop
// //       sf::Event event;
// //       while (window.pollEvent(event))
// //       {
// //           if (event.type == sf::Event::Closed)
// //               window.close();
// //           //else if (event.type == sf::Event::KeyPressed)
// //           if (event.type == sf::Event::KeyPressed) {
// //               std::cout << event.type << " ----------\n";
// //               game.update(event, deltaTime);
// //           }
// //       }
//
// //       // clear the window with black color
// //       game.update(event, deltaTime);
// //       game.render(window);
// //       window.display();
// //   }
// //   /*return EXIT_SUCCESS*/
//
//    return 0;
//}
#include <SFML/Graphics.hpp>
#include "Game/GameController.h"
#include "Entities/Actor.h"
#include "Entities/Player.h"
#include "MainMenu.h"
#include "NavigationManager.h"
#include <iostream>

int main()
{
    // Create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    GameController& game = GameController::getInstance();

    // Initialize game
    Player player(sf::Vector2f(50, 50), sf::Vector2f(0, 10), sf::Vector2f(50, 50));
    game.setPlayer(&player);

    window.setFramerateLimit(60);

    MainMenu mainMenu(game);

    // Game start
    //game.startGame();

    //sf::Clock clock;
    //clock.restart();

    //// Run the program as long as the window is open
    //while (window.isOpen())
    //{
    //    float deltaTime = clock.restart().asSeconds();
    //    window.clear(sf::Color::Black);

    //    // Check all the window's events that were triggered since the last iteration of the loop
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //        else if (event.type == sf::Event::KeyPressed)
    //            game.update(event, deltaTime);
    //    }

    //    // Update and render the game
    //    game.update(event, deltaTime);
    //    game.render(window);
    //    window.display();
    //}

    return 0;
}
