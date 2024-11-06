#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <algorithm>
#include <iostream>

class Collision {
#define vt sf::Vector2f
public:

	struct rect {
		vt pos;
		vt size;
		vt vel = { 0, 0 };

		std::array<Collision::rect*, 4> contact  ;

		vt getPosition() const { return pos; };
		vt getSize() const { return size; };
		vt getVel() const { return vel; };

	};

	bool pointVsRect(const vt& p, const rect& r);
	bool rectVsRect(const rect& r1, const rect& r2);

	bool rayVsRect(const vt& rayOrigin, const vt& rayDir,
		const rect& target,
		vt& contactNormal,
		vt& contactPoint,
		float& tHitNear);

	bool dynamicRectVsRect(const rect& rDynamic, const float fTimeStep, const rect& rStatic,
		vt& contactPoint, vt& contactNormal, float& contactTime
	);

	bool resolveDynamicRectVsRect(rect& r_dynamic, const float fTimeStep, rect& r_static, vt& pushback);

	/*
	* take an origin rectangle 'o', then resolve it with a vector of rectangles v
	* remember to put in deltatime
	*/

	vt rectVsTerain(sf::RectangleShape dynamicRect, std::vector <sf::RectangleShape> ground, vt vel, float deltaTime, vt& pos);

#undef vt
};