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
		void const generateNew(cocos2d::Scene *help, OOP::myLevels* level);
		int const getClosestY(cocos2d::Sprite* character, float velocityY);
		int const getClosestX(cocos2d::Sprite* character, float velocityX);


		void const moveHitBoxesX(float X);
		void const moveHitBoxesY(float Y);

		int const getTypeHitBoxX() const;
		int const getTypeHitBoxY() const;

		void const resetHitBox(cocos2d::Scene *help, OOP::myLevels* level);

		int vectorSize = 0;
		int getPlayerTypeOfHitBox(int index) { return types[index]; }
	private:
		std::vector <cocos2d::Sprite *> m_Platform;
		std::vector <int> types;
		int typeHitBoxX, monsterTypeHitBoxX;
		int typeHitBoxY, monsterTypeHitBoxY;


		int number = 0;
		int index;
	};
}

#endif //H_PLATFORM