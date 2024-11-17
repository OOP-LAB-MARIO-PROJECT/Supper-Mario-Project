#pragma once
#include "Tile.h"
#include "Entity.h"
#include "../Utils/Collision.h"
//#include "Player.h"
#include "memory"
class BreakableTile : public Entity , public Collision{
private:
	sf::RectangleShape hitbox;
	sf::Vector2f pos;
	sf::Vector2f size;
	bool isTransparent = false;

public:

	BreakableTile(sf::Vector2f _pos, sf::Vector2f _size, bool isTrans = false);
	~BreakableTile() {};
	void render(sf::RenderWindow& window) const override;
	void update(float deltaTime) override;
	
	sf::RectangleShape& getHitbox();
	sf::Vector2f getPos() const;
	sf::Vector2f getSize() const;
	void setPos(sf::Vector2f npos);
	void setSize(sf::Vector2f nsize);

	rect getRect() const;

};

