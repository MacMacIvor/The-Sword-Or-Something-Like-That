#ifndef H_PLAYER
#define H_PLAYER
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

		float getVelocityX() const;
		float getVelocityY() const;
		void setVelocityX(float newVelocity);
		void setVelocityY(float newVelocity);
		void updateVelocities(cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platformY, cocos2d::Sprite * platformX, int typeOfHitBoxX, int typeOfHitBoxY);
		


		void resetPlayer();
		int getHealth();

		cocos2d::EventListenerKeyboard *getListener(); //Returns the listener that holds the event


		cocos2d::Sprite *getMainCharacter(); //Returns the listener that holds the event
		cocos2d::Sprite *getTheLastAmountOfPatienceIHaveWithCocos(); //Returns the listener that holds the event

	private:
		cocos2d::Sprite *m_MainCharacter;
		cocos2d::Sprite *IHATECOCOSIDONTKNOWWHYTHISISSOFINICKYTOGETTOWORK;
		float velocityX = 0;
		float velocityY = 0;
		Physics toCalculate;
		KeyboardListener keyBoard;
		bool onGround = false;
		int againstWall = 0;
		int health = 3;


	};
}

#endif //!H_PLAYER