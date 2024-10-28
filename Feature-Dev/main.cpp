#include <SFML/Graphics.hpp>
#include "Game/GameController.h"
#include "Entities/Actor.h"
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    GameController& game = GameController::getInstance();
    game.startGame();

    Actor player(sf::Vector2f(50, 50), sf::Vector2f(0, 10), sf::Vector2f(50, 50));
    game.setPlayer(&player);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        game.update();
        game.render(window);
        window.display();
    }

    return 0;
}