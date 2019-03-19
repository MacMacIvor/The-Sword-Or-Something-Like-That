#ifndef H_PLAYER
#define H_PLAYER

#ifndef H_INCLUDE
#define H_INCLUDE
#include "cocos2d.h"
#include <functional>
#include "KeyboardInput.h"
#include "proj.win32\GamePhysics.h"
#endif



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

		bool const getLeftArrow() const { return keyBoard.getLeftArrow(); }
		bool const getRightArrow() const { return keyBoard.getRightArrow(); }
		bool const getUpArrow() const { return keyBoard.getUpArrow(); }
		bool const getShiftKey() const { return keyBoard.getShiftKey(); }
		bool const getZKey() const { return keyBoard.getZKey(); }
		bool const getXKey() const { return keyBoard.getXKey(); }
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


		void const updatePlayer();
		void const saveInfoBecauseIHateCocos(OOP::PlatformGenerator *a_PlatformManager, double *velocityY, double *velocityX, int *againstWall, bool *onGround, cocos2d::Sprite * a_MainCharacter, int * health);



		int getInvincible() { return invincible; };

		cocos2d::EventListenerKeyboard *getListener(); //Returns the listener that holds the event


		cocos2d::Sprite *getMainCharacter(); //Returns the listener that holds the event
		cocos2d::Sprite *getTheLastAmountOfPatienceIHaveWithCocos(); //Returns the listener that holds the event

		void initAnimations();
		void runAnimation(cocos2d::Vector<cocos2d::CCSpriteFrame *>);

		void attack();
		bool isattack();
		bool getDir();

		
		double const getPlayerVelocityX() const { return playerVelocityX; }
		double const getPlayerVelocityY() const { return playerVelocityY; }
		
		bool playerOnGround = false;
		int playerAgainstWall = 0;
		int health = 3;
		int invincible = 0;
		double playerVelocityY = 0;
		double playerVelocityX = 0;
		

	private:
		cocos2d::Scene* m_scene;
		cocos2d::Sprite *m_MainCharacter;
		cocos2d::Sprite *IHATECOCOSIDONTKNOWWHYTHISISSOFINICKYTOGETTOWORK;
		std::vector <cocos2d::Sprite *> m_Health;
		std::vector <std::string> animation;
		int aniCount = -1;
		float velocityX = 0;
		float velocityY = 0;
		//OOP::Physics toCalculate;
		OOP::Physics toCalculate;
		KeyboardListener keyBoard;
		bool onGround = false;
		int againstWall = 0;
		const int MAX_HEALTH = 3;
		int attCooldown = 0;
		cocos2d::CCAction *action;
		bool direction = false;//true==left     false==right


		//animation things
		cocos2d::CCSpriteFrameCache* frameCache;
		cocos2d::Vector<cocos2d::CCSpriteFrame *> testframes;
		cocos2d::CCAnimation* testAnim;


		//animations
		cocos2d::Vector<cocos2d::CCSpriteFrame *> A_idle;
	};
}

#endif //!H_PLAYER