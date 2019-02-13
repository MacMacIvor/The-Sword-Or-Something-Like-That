#pragma once
#include <functional>
#include "cocos2d.h"
#include "proj.win32\PlatformGenerator.h"
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
		void newVelocityY(float velocityY, bool upArrow, bool *onGround, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform);
		float getVelocityY();
		void checkOnGround(bool *onGround, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform);
	private:
		const float GRAVITY = 9.81;
		const float TIME_INTERVAL = 0.05;
		float new_VelocityY = -9000;
		float jumpBoost = 5;
		bool wasHoldingUp = false;
		const int MIN_JUMPBOOST = 0;
	};
}