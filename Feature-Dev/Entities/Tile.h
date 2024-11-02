#pragma once
#include "Entity.h"



class Tile : public Entity{
private:
	sf::RectangleShape hitbox;
	sf::Vector2f pos;
	sf::Vector2f size;
	bool isTransparent = true;

public:
	
	Tile(sf::Vector2f _pos, sf::Vector2f _size, bool isTrans = true) {
		pos = _pos;
		size = _size;
		isTransparent = isTrans;

		hitbox.setPosition(pos);
		hitbox.setSize(size);
		hitbox.setFillColor(sf::Color::Magenta);
		hitbox.setOutlineColor(sf::Color::Blue);
		hitbox.setOutlineThickness(2);
	};

	~Tile() {};

	void render(sf::RenderWindow& window) const override {
		window.draw(hitbox);
	}

	void update(float deltaTime) {};

	sf::RectangleShape& getHitbox() {
		return hitbox;
	}

};

