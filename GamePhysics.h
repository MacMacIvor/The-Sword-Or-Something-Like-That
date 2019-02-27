#ifndef H_PHYSICS
#define H_PHYSICS

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
		void newVelocityY(float velocityY, bool upArrow, bool leftArrow, bool rightArrow, bool zKey, bool shiftKey, int * againstWall, bool *onGround, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform);
		void newVelocityX(float velocityX, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform);
		float getVelocityY();
		float getVelocityX();
		void checkOnGround(bool *onGround, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform, int typeOfHitBoxY, int * health);
		void checkAgainstWall(int *againstWall, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform, int typeOfHitBoxX, int * health);
	private:
		const float GRAVITY = 9.81;
		const float TIME_INTERVAL = 0.05;
		float new_VelocityY = -9000;
		float new_VelocityX = 0;
		bool wasHoldingUp = false;
		bool wasHoldingZ = false;
		float wallJumpBonus = 0;

	};
}

#endif //!H_PHYSICS