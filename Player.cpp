#include "Player.h"



OOP::Player::Player()
	:m_MainCharacter(cocos2d::Sprite::create("Capture1.PNG")), IHATECOCOSIDONTKNOWWHYTHISISSOFINICKYTOGETTOWORK(cocos2d::Sprite::create("Dead.png")), velocityX(0), velocityY(0)
{
	m_Health.push_back(cocos2d::Sprite::create("Health.png"));
	m_Health.push_back(cocos2d::Sprite::create("Health.png"));
	m_Health.push_back(cocos2d::Sprite::create("Health.png"));
	
	animation.push_back("a1");
	animation.push_back("a2");
	animation.push_back("a3");
	animation.push_back("a4");

}

OOP::Player::~Player()
{
}

float const OOP::Player::getVelocityX() const
{
	return velocityX;
}

float const OOP::Player::getVelocityY() const
{
	return velocityY;
}

void const OOP::Player::setVelocityX(float newVelocity)
{
	velocityX = newVelocity;
}

void const OOP::Player::setVelocityY(float newVelocity)
{
	velocityY = newVelocity;
}

void const OOP::Player::updateVelocities(cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platformY, cocos2d::Sprite * platformX, int typeOfHitBoxX, int typeOfHitBoxY)
{
		if (keyBoard.getRightArrow() == true) {
			aniCount++;
			if (aniCount > 3) 
				{ aniCount = 0; }
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

void const OOP::Player::updateHealthSprite() const
{
	if (health > 0) {
		for (unsigned int i = 0; i < MAX_HEALTH; i++) {
			if (i < health) {
				m_Health[i]->setPosition(m_Health[0]->getBoundingBox().size.width / 2 + m_Health[0]->getBoundingBox().size.width * i, m_scene->getBoundingBox().getMaxY() - m_Health[i]->getBoundingBox().size.height / 2);
			}
			else {
				m_Health[i]->setPosition(m_Health[0]->getBoundingBox().size.width / 2 + m_Health[0]->getBoundingBox().size.width * i, m_scene->getBoundingBox().getMaxY() + m_Health[i]->getBoundingBox().size.height);
			}
		}
	}
	else {
		m_Health[0]->setPosition(m_Health[0]->getBoundingBox().size.width / 2 + m_Health[0]->getBoundingBox().size.width * 0, m_scene->getBoundingBox().getMaxY() + m_Health[0]->getBoundingBox().size.height / 2);
		m_Health[1]->setPosition(m_Health[0]->getBoundingBox().size.width / 2 + m_Health[0]->getBoundingBox().size.width * 0, m_scene->getBoundingBox().getMaxY() + m_Health[0]->getBoundingBox().size.height / 2);
		m_Health[2]->setPosition(m_Health[0]->getBoundingBox().size.width / 2 + m_Health[0]->getBoundingBox().size.width * 0, m_scene->getBoundingBox().getMaxY() + m_Health[0]->getBoundingBox().size.height / 2);

	}
}

void const OOP::Player::saveScene(cocos2d::Scene * helloThere) 
{
	m_scene = helloThere;
}

void const OOP::Player::initHealth() const
{
	m_scene->addChild(m_Health[0], 2);
	m_scene->addChild(m_Health[1], 2);
	m_scene->addChild(m_Health[2], 2);
}

void const OOP::Player::resetPlayer()
{
	velocityX = 0;
	velocityY = 0;
	health = MAX_HEALTH;
	invincible = 0;
	m_MainCharacter->setPosition(100, 100);
}

int const OOP::Player::getHealth() const
{
	return health;
}

void OOP::Player::damage(cocos2d::Sprite * m_MainCharacter, bool left, bool right)
{
	if (invincible != 0) {
		invincible--;
	}
	else if (left == true) {
		health--;
		invincible = 100;
		velocityX = 40;
	}
	else if (right == true) {
		health--;
		invincible = 100;
		velocityX = -40;
	}
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


void OOP::Player::runAnimation(cocos2d::CCAction* animation)
{
	this->getMainCharacter()->runAction(animation);
}
