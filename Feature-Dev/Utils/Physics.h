#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <set>


class Force {
#define vt sf::Vector2f
private:
	vt f;
	float life;

public:
	Force(vt f, float life) : life(life), f({ f.x, f.y }) {};
	Force() :f({ 0, 0 }), life(0) {};

	void timePass(float t) { life -= t; }
	bool isDead() const { return life < 0; }

	vt getForce(float deltaTime	) const {
		if (life < 0) return vt{ 0, 0 };
		if (deltaTime < life)
			return f;
		return f / deltaTime * life;
	}

#undef vf
};

class Physics {
#define vt sf::Vector2f

private:

	vt vel = { 0,0 };
	vt g = { 0, 0};
	vt fric = { 10, 0 };

public:


	Physics(vt vel, vt g) : vel(vel), g(g) {};
	Physics() {};
	Physics getPhysic() {
		return *this;
	}

	void setGravity(vt f);
	void setVel(vt f);
	
	vt getVel() const;
	void performPhysics(float deltaTime);

#undef vt
	
};
