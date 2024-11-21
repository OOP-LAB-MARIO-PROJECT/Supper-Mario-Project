#pragma once
#include "../Game/GameController.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp> 
#include "Camera.h"
#include "../Entities/Map.h"
#include <string>
#include "TextureManager.h"

using namespace std;

class GameManager {
private:
    TextureManager* myTextureManager = NULL;
	GameController* game = NULL;
	sf::RenderWindow* window;
	Camera* camera = NULL;

	vector <string> mapPath;
	Map* gameMap = NULL;
	int currentMap = 0;
	
    Player* player = NULL;


public:
	~GameManager();
    void init(sf::RenderWindow& window);
	void play(float dt);
};

