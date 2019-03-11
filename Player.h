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

		float const getVelocityX() const;
		float const getVelocityY() const;
		void const setVelocityX(float newVelocity);
		void const setVelocityY(float newVelocity);
		void const updateVelocities(cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platformY, cocos2d::Sprite * platformX, int typeOfHitBoxX, int typeOfHitBoxY);
		void const updateHealthSprite() const;
		void const saveScene(cocos2d::Scene * helloThere);
		void const initHealth() const;
		void const resetPlayer();
		int const getHealth() const;
		void damage(cocos2d::Sprite * m_MainCharacter, bool left, bool right);

		int getInvincible() { return invincible; };

		cocos2d::EventListenerKeyboard *getListener(); //Returns the listener that holds the event


		cocos2d::Sprite *getMainCharacter(); //Returns the listener that holds the event
		cocos2d::Sprite *getTheLastAmountOfPatienceIHaveWithCocos(); //Returns the listener that holds the event

		void initAnimations();
		void runAnimation(cocos2d::CCAction*);

		void attack();
		bool isattack();


	private:
		cocos2d::Scene* m_scene;
		cocos2d::Sprite *m_MainCharacter;
		cocos2d::Sprite *IHATECOCOSIDONTKNOWWHYTHISISSOFINICKYTOGETTOWORK;
		std::vector <cocos2d::Sprite *> m_Health;
		std::vector <std::string> animation;
		int aniCount = 0;
		float velocityX = 0;
		float velocityY = 0;
		Physics toCalculate;
		KeyboardListener keyBoard;
		bool onGround = false;
		int againstWall = 0;
		const int MAX_HEALTH = 3;
		int health = 3;
		int invincible = 0;
		int attCooldown = 0;
		cocos2d::CCAction *action;


		//animation things
		cocos2d::CCSpriteFrameCache* frameCache;
		cocos2d::Vector<cocos2d::CCSpriteFrame *> testframes;
		cocos2d::CCAnimation* testAnim;
	};
}

#endif //!H_PLAYER