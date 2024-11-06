#include <SFML/Graphics.hpp>
#include "Game/GameController.h"
#include "Entities/Actor.h"
#include "Entities/Map.h"
#include "Entities/Player.h"
#include <iostream>

int main()
{
    // create the window

    ///// Do not touch
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "My window");
    GameController& game = GameController::getInstance();
    ///// End do not touch


    //// init game


    Player player(sf::Vector2f(50, 50), sf::Vector2f(32, 32));

    Map gameMap;
    gameMap.loadMap("Assets/map.txt");

    player.setMap(&gameMap);
    game.setPlayer(&player);
    game.setMap(&gameMap);
    window.setFramerateLimit(60);



    ///// Do not touch

    ////////// game start
    game.startGame();

    sf::Clock clock;
    clock.restart();
    // run the program as long as the window is open
    while (window.isOpen())
    {

        float deltaTime = clock.restart().asSeconds();
        window.clear(sf::Color::Black);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        game.update(event, deltaTime);
        game.render(window);
        window.display();
    }
    ///// End do not touch

    return 0;
}