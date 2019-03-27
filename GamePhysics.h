


#ifndef H_PHYSICS
#define H_PHYSICS

#ifndef H_INCLUDE
#define H_INCLUDE
#include "cocos2d.h"
#include <functional>
#include "KeyboardInput.h"
#include "proj.win32\GamePhysics.h"
#endif
#include "proj.win32\PlatformGenerator.h"

namespace cocos2d {
	class Vec2;
	class Director;
	class DrawNode;
	class Sprite;
	class Node;
	class Scene;
	class Label;
	class Rect;
}

namespace OOP {

	class Physics {
	public:
		void const newVelocityY(float velocityY, bool upArrow, bool leftArrow, bool rightArrow, bool zKey, bool shiftKey, int * againstWall, bool *onGround, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform);
		void const newVelocityX(float velocityX, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform);
		float const getVelocityY() const;
		float const getVelocityX() const;
		void const checkOnGround(bool *onGround, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform, int typeOfHitBoxY, int * health);
		void const checkAgainstWall(int *againstWall, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform, int typeOfHitBoxX, int * health);

		void const saveInfoBecauseIHateCocos(OOP::PlatformGenerator *a_PlatformManager, double *velocityY, double *velocityX, int *againstWall, bool *onGround, cocos2d::Sprite * a_MainCharacter, int * health);
		void const playerPhysics(bool upArrow, bool LeftArrow, bool rightArrow, bool zKey, bool shiftKey);
	private:
		const float GRAVITY = 9.81;
		const float TIME_INTERVAL = 0.05;
		float new_VelocityY = -9000;
		float new_VelocityX = 0;
		bool wasHoldingUp = false;
		bool wasHoldingZ = false;
		float wallJumpBonus = 0;

		int *playerHealth;
		double* playerVelocityY,* playerVelocityX;
		int* playerAgainstWall = 0;
		bool* onGround = false;
		cocos2d::Sprite* m_MainCharacter;
		OOP::PlatformGenerator* m_PlatformManager;
		

	};
}

#endif //!H_PHYSICS