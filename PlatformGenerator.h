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
		cocos2d::Vec2 const generateNew(cocos2d::Scene *help, OOP::myLevels* level);
		//int const getClosestY(float pointX, float pointY, float velocityY);
		//int const getClosestX(cocos2d::Sprite* character, float velocityX);

		cocos2d::Vec2 getMonsterMaxMovement(float positionX, float positionY);
		//float getMonsterMinY(float positionX, float positionY);

		void const moveHitBoxesX(float X);
		void const moveHitBoxesY(float Y);

		int const getTypeHitBoxX() const;
		int const getTypeHitBoxY() const;

		cocos2d::Vec2 const resetHitBox(cocos2d::Scene *help, OOP::myLevels* level);

		int vectorSize = 0;
		int getPlayerTypeOfHitBox(int index);
	private:
		int numberForMonsters = 0;


		std::vector <cocos2d::Sprite *> m_Platform;
		std::vector <int> types;
		int typeHitBoxX, monsterTypeHitBoxX;
		int typeHitBoxY, monsterTypeHitBoxY;

		

		int number = 0;
		int index;
	};
}

#endif //H_PLATFORM