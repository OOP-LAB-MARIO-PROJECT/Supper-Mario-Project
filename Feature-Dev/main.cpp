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

    sf::RectangleShape tmp(sf::Vector2f(50, 50));
    tmp.setFillColor(sf::Color::Red);
    tmp.setPosition(sf::Vector2f(0, 0));
    window.draw(tmp);

    std::cout << tmp.getOrigin().x << ' ' << tmp.getOrigin().y << '\n';

    Player player(sf::Vector2f(50, 50), sf::Vector2f(50, 50));

    Map gameMap;
    for (int i = 0; i < 20; i++)
        gameMap.addTile(Tile(sf::Vector2f(50 * i, 600), sf::Vector2f(50, 50), 0));

    for (int i = 0; i < 5; i++)
        gameMap.addTile(Tile(sf::Vector2f(400, -50 * i + 600), sf::Vector2f(50, 50), 0));

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
            //else if (event.type == sf::Event::KeyPressed)
            if (event.type == sf::Event::KeyPressed) {
                game.update(event, deltaTime);
            }
        }

        // clear the window with black color
        game.update(event, deltaTime);
        game.render(window);
        window.draw(tmp);

        window.display();
    }
    ///// End do not touch

    return 0;
}