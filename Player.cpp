#include "Player.h"

OOP::Player::Player()
	:m_MainCharacter(cocos2d::Sprite::create("Capture1.PNG")), velocityX(0), velocityY(0)
{
	
}

OOP::Player::~Player()
{
}

float OOP::Player::getVelocityX()
{
	return velocityX;
}

float OOP::Player::getVelocityY()
{
	return velocityY;
}

void OOP::Player::setVelocityX(float newVelocity)
{
	velocityX = newVelocity;
}

void OOP::Player::setVelocityY(float newVelocity)
{
	velocityY = newVelocity;
}

void OOP::Player::updateVelocities(cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform)
{
	if (keyBoard.getRightArrow() == true) {
		velocityX = -10;
	}
	else if (keyBoard.getLeftArrow() == true) {
		velocityX = 10;
	}
	else {
		velocityX = 0;
	}

	toCalculate.checkOnGround(&onGround, m_MainCharacter, platform);
	toCalculate.newVelocityY(velocityY, keyBoard.getUpArrow(), &onGround, m_MainCharacter, platform);
	velocityY = toCalculate.getVelocityY();
}

cocos2d::EventListenerKeyboard * OOP::Player::getListener()
{
	return keyBoard.getListener();
}

cocos2d::Sprite * OOP::Player::getMainCharacter()
{
	return m_MainCharacter;
}


