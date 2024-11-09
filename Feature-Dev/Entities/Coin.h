#pragma once
#include "Collectable.h"
class Coin : public Collectable {
private:
	int point = 1;
public:
	Coin(sf::Vector2f pos, sf::Vector2f size) : Collectable(pos, size) {
	};
	~Coin() {};

	void update(float dt) override;

};

