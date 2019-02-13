#ifndef H_PLATFORM
#define H_PLATFORM

#include <functional>
#include "cocos2d.h"
#include <vector>

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

	class PlatformGenerator {
	public:
		PlatformGenerator();
		cocos2d::Sprite *getPlatform(int reference);
		void generateNew(int index);
		int getSize();
		int getClosest(cocos2d::Sprite* character);
	private:
		//cocos2d::Sprite *;
		std::vector <cocos2d::Sprite *> m_Platform;
		std::vector <float> positionX, positionY;

	};

}

#endif //H_PLATFORM