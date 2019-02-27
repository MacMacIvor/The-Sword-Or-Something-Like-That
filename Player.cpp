#include "Player.h"

OOP::Player::Player()
	:m_MainCharacter(cocos2d::Sprite::create("Capture1.PNG")), IHATECOCOSIDONTKNOWWHYTHISISSOFINICKYTOGETTOWORK(cocos2d::Sprite::create("Dead.png")), velocityX(0), velocityY(0)
{
}

OOP::Player::~Player()
{
}

float OOP::Player::getVelocityX() const
{
	return velocityX;
}

float OOP::Player::getVelocityY() const
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

void OOP::Player::updateVelocities(cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platformY, cocos2d::Sprite * platformX, int typeOfHitBoxX, int typeOfHitBoxY)
{
		if (keyBoard.getRightArrow() == true) {
			if (velocityX == 0) {
				velocityX = -1;
			}
			else if (velocityX >= -10 && velocityX < 0) {
				velocityX *= 1.5;
			}
			else if (velocityX > 0) {
				velocityX /= 1.5;
				if (velocityX <= 1) {
					velocityX = 0;
				}
			}

		}
		else if (keyBoard.getLeftArrow() == true) {
			if (velocityX == 0) {
				velocityX = 1;
			}
			else if (velocityX <= 10 && velocityX > 0) {
				velocityX *= 1.5;
			}
			else if (velocityX < 0) {
				velocityX /= 1.5;
				if (velocityX >= -1) {
					velocityX = 0;
				}
			}
		}
		else {
			velocityX = 0;
		}

		toCalculate.checkOnGround(&onGround, m_MainCharacter, platformY, typeOfHitBoxY, &health);
		toCalculate.checkAgainstWall(&againstWall, m_MainCharacter, platformX, typeOfHitBoxX, &health);

		toCalculate.newVelocityY(velocityY, keyBoard.getUpArrow(), keyBoard.getLeftArrow(), keyBoard.getRightArrow(), keyBoard.getZKey(), keyBoard.getShiftKey(), &againstWall, &onGround, m_MainCharacter, platformY);
		velocityY = toCalculate.getVelocityY();

		toCalculate.newVelocityX(velocityX, m_MainCharacter, platformX);
		velocityX = toCalculate.getVelocityX();
}

void OOP::Player::resetPlayer()
{
	velocityX = 0;
	velocityY = 0;
	health = 3;
	m_MainCharacter->setPosition(100, 100);

}

int OOP::Player::getHealth()
{
	return health;
}

cocos2d::EventListenerKeyboard * OOP::Player::getListener()
{
	return keyBoard.getListener();
}

cocos2d::Sprite * OOP::Player::getMainCharacter()
{
	return m_MainCharacter;
}

cocos2d::Sprite * OOP::Player::getTheLastAmountOfPatienceIHaveWithCocos()
{
	return IHATECOCOSIDONTKNOWWHYTHISISSOFINICKYTOGETTOWORK;
}


