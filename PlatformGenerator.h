#ifndef H_PLATFORM
#define H_PLATFORM

#include <functional>
#include "cocos2d.h"
#include <vector>
#include "myLevels.h"

namespace cocos2d {
	class Vec2;
	class Director;
	class DrawNode;
	class Sprite;
	class Node;
	class Scene;
	class Label;
	class Scene;
}

namespace OOP {

	class PlatformGenerator : public cocos2d::Scene, public OOP::myLevels {
	public:
		PlatformGenerator();
		cocos2d::Sprite *getPlatform(int reference);
		void generateNew(cocos2d::Scene *help, OOP::myLevels* level);
		int getClosestY(cocos2d::Sprite* character, float velocityY);
		int getClosestX(cocos2d::Sprite* character, float velocityX);

		void moveHitBoxesX(float X);
		void moveHitBoxesY(float Y);

		int getTypeHitBoxX();
		int getTypeHitBoxY();

		void resetHitBox(cocos2d::Scene *help, OOP::myLevels* level);


	private:
		std::vector <cocos2d::Sprite *> m_Platform;
		std::vector <int> types;
		int typeHitBoxX;
		int typeHitBoxY;

		int number = 0;
		int index;
	};
}

#endif //H_PLATFORM