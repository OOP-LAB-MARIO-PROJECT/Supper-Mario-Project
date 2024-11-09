#include <SFML/Graphics.hpp>
#include "Game/GameController.h"
#include "Entities/Actor.h"
#include "Entities/Map.h"
#include "Entities/Player.h"
#include "Utils/Camera.h"
#include <iostream>

int main()
{
    // create the window

    ///// Do not touch
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
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
    
    Camera camera(window);


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

        camera.followPlayer(player.getPos().x, player.getPos().y, player.getHitbox().getSize().x, player.getHitbox().getSize().y);

        camera.setCameraView(window);

        // clear the window with black color
        game.update(event, deltaTime);
        game.render(window);
        window.display();
    }
    ///// End do not touch

    return 0;
}