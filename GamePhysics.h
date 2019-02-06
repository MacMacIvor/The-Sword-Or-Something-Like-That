#pragma once
#include <functional>
#include "cocos2d.h"

namespace cocos2d {
	class Vec2;
	class Director;
	class DrawNode;
	class Sprite;
	class Node;
	class Scene;
	class Label;
}

namespace OOP {
	class Physics {
	public:
		void newVelocityY(float velocityY, float positionY, bool upArrow);
		float getVelocityY();
	private:
		const float GRAVITY = 9.81;
		const float TIME_INTERVAL = 0.05;
		float new_VelocityY;
	};
}