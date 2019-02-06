#pragma once
#include "cocos2d.h"
#include <functional>
#include "proj.win32\GamePhysics.h"
#include "KeyboardInput.h"

namespace cocos2d {
	class Vec2;
	class Director;
	class DrawNode;
	class Sprite;
	class Node;
	class Scene;
	class Label;
	class EventListenerKeyboard;
}

namespace OOP {
	class Player 
	{
	public:
		Player();
		~Player();

		float getVelocityX();
		float getVelocityY();
		void setVelocityX(float newVelocity);
		void setVelocityY(float newVelocity);
		void updateVelocities(float positionY);

		cocos2d::EventListenerKeyboard *getListener(); //Returns the listener that holds the event


		cocos2d::Sprite *getMainCharacter(); //Returns the listener that holds the event

	private:
		cocos2d::Sprite *m_MainCharacter;
		float velocityX = 0;
		float velocityY = 0;
		Physics toCalculate;
		KeyboardListener keyBoard;
	};
}

