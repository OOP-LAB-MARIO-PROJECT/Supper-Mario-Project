#include "GameManager.h"


void GameManager::init(sf::RenderWindow& window) {
    // load texture first
    myTextureManager = &TextureManager::getInstance();
    myTextureManager->loadNewTexture("Assets/Texture/Texture_Pack/mario.tsx", "Assets/Texture/Texture_Pack/mario.png");


    game = &GameController::getInstance();
    player = new Player(sf::Vector2f(50, 50), sf::Vector2f(14, 14));

    gameMap = new Map();
    gameMap->loadMap("Assets/map.txt", player);

    player->setMap(gameMap);
    game->setPlayer(player);
    game->setMap(gameMap);
    camera = new Camera(window);
    game->startGame();
    this->window = &window;
}


void GameManager::play(float dt) {
    window->clear(sf::Color::Black);

    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
    camera->followPlayer(player->getPos().x, player->getPos().y, player->getHitbox().getSize().x, player->getHitbox().getSize().y);

    camera->setCameraView(*window);

    // clear the window with black color
    game->update(event, dt);
    game->render(*window);
    window->display();
}

GameManager::~GameManager() {
    //		delete game;
    delete camera;
    delete gameMap;
    delete player;

}