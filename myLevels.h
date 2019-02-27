#pragma once
#include "cocos2d.h"
#include <vector>

namespace cocos2d {
	class Vec2;
	class Director;
	class DrawNode;
	class Sprite;
	class Scene;
	class Node;
	class Label;
}


namespace OOP {
	class myLevels : public cocos2d::Scene
	{
	public:
		myLevels();
		~myLevels();
		void initLevel(cocos2d::Scene *help);
		void setLevel(int newLevel);
		cocos2d::Sprite* getLevel(int currentLevel);
		int getLevel();

		bool checkMaxX(int dir, cocos2d::Scene *help);

		bool checkMaxY(int dir, cocos2d::Scene *help);

		void moveBackGroundX(float X, cocos2d::Scene *help);
		
		float getMovedAmountX();

		void moveBackGroundY(float Y, cocos2d::Scene *help);

		float getMovedAmountY();

		void resetLevel(cocos2d::Scene *help);


		int levelOneHitBox[16][9]
			=
		{
			{1,0,0,0,0,0,0,0,0},
			{1,0,0,1,1,0,0,0,0},
			{1,0,0,1,1,0,0,0,0},
			{1,0,0,1,0,1,1,1,1},
			{1,0,1,0,0,0,0,0,0},
			{1,0,1,0,0,0,0,0,0},
			{0,0,1,1,1,1,1,1,1},
			{0,0,0,0,0,0,0,0,1},
			{1,0,0,0,1,1,1,0,1},
			{0,1,1,1,0,0,1,0,1},
			{0,0,0,0,0,0,1,0,1},
			{0,0,0,0,0,0,1,0,1},
			{0,0,0,0,0,0,1,0,1},
			{1,1,1,1,1,1,1,0,1},
			{0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,2,1} //50, 58
		};


	private:
		std::vector <cocos2d::Sprite*> m_Levels;
		

		cocos2d::Sprite* testing;



		int currentPosition = 0;
		int currentLevel = 0;
		float movedAmountX;
		float movedAmountY;

		
	};
}