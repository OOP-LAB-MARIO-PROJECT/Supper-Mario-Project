#pragma once
#include "Entity.h"



class Tile : public Entity{
private:
	sf::RectangleShape hitbox;
	sf::Vector2f pos;
	sf::Vector2f size;
	bool isTransparent = true;

public:
	
	Tile(sf::Vector2f _pos, sf::Vector2f _size, bool isTrans = true);
	~Tile() {};
	void render(sf::RenderWindow& window) const override;
	void update(float deltaTime);
	sf::RectangleShape& getHitbox();

};

