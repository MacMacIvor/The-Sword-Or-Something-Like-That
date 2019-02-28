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
		void const initLevel(cocos2d::Scene *help) const;
		void const setLevel(int newLevel);
		cocos2d::Sprite* const getLevel(int currentLevel) const;
		int const getLevel() const;

		bool const checkMaxX(int dir, cocos2d::Scene *help);

		bool const checkMaxY(int dir, cocos2d::Scene *help);

		void const moveBackGroundX(float X, cocos2d::Scene *help);
		
		float const getMovedAmountX() const;

		void const moveBackGroundY(float Y, cocos2d::Scene *help);

		float const getMovedAmountY() const;

		void const resetLevel(cocos2d::Scene *help) const;


		const int levelOneHitBox[16][9]
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