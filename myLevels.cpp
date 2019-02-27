#ifndef H_MYLEVELS
#define H_LEVELS

#include "myLevels.h"

OOP::myLevels::myLevels()
	:testing(cocos2d::Sprite::create("Level 1.jpg"))
{
	m_Levels.push_back(cocos2d::Sprite::create("Level 1.jpg"));
	//testing = cocos2d::Sprite::create("Level 1.PNG");
}

OOP::myLevels::~myLevels()
{
}

void OOP::myLevels::initLevel(cocos2d::Scene *help)
{
	m_Levels[currentLevel]->setPosition((m_Levels[currentLevel]->getBoundingBox().size.width / 2), m_Levels[currentLevel]->getBoundingBox().size.height / 2);
	help->addChild(m_Levels[currentLevel], 0);
}

void OOP::myLevels::setLevel(int newLevel)
{
	m_Levels[currentLevel]->release();
	currentLevel = newLevel;
}

cocos2d::Sprite * OOP::myLevels::getLevel(int currentLevel)
{
	return m_Levels[currentLevel];
}

int OOP::myLevels::getLevel()
{
	return currentLevel;
}

bool OOP::myLevels::checkMaxX(int dir, cocos2d::Scene *help)
{
	
	if (dir > 0) {
		if (m_Levels[currentLevel]->getBoundingBox().getMinX() == help->getBoundingBox().getMinX()) {
			return true;
		}
	}
	else if (dir < 0) {
		if (m_Levels[currentLevel]->getBoundingBox().getMaxX() == help->getBoundingBox().getMaxX()) {
			return true;
		}
	}
	else if (dir == 0) {
		if (m_Levels[currentLevel]->getBoundingBox().getMinX() == help->getBoundingBox().getMinX() || m_Levels[currentLevel]->getBoundingBox().getMaxX() == help->getBoundingBox().getMaxX()) {
			return true;
		}
	}
	return false;
}

bool OOP::myLevels::checkMaxY(int dir, cocos2d::Scene * help)
{
	if (dir < 0) {
		if (m_Levels[currentLevel]->getBoundingBox().getMinY() == help->getBoundingBox().getMinY()) {
			return true;
		}
	}
	else if (dir > 0) {
		if (m_Levels[currentLevel]->getBoundingBox().getMaxY() == help->getBoundingBox().getMaxY()) {
			return true;
		}
	}
	else if (dir == 0) {
		if (m_Levels[currentLevel]->getBoundingBox().getMinY() == help->getBoundingBox().getMinY() || m_Levels[currentLevel]->getBoundingBox().getMaxY() == help->getBoundingBox().getMaxY()) {
			return true;
		}
	}
	return false;
}

void OOP::myLevels::moveBackGroundX(float X, cocos2d::Scene *help)
{
	movedAmountX = X;
	
	if (m_Levels[currentLevel]->getBoundingBox().getMaxX() + X < help->getBoundingBox().getMaxX() && X < 0) 
	
	{
		movedAmountX = (help->getBoundingBox().getMaxX() - m_Levels[currentLevel]->getBoundingBox().getMaxX());
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionX() + (help->getBoundingBox().getMaxX() - m_Levels[currentLevel]->getBoundingBox().getMaxX()),
			m_Levels[currentLevel]->getPositionY()
		);
	}
	else if (m_Levels[currentLevel]->getBoundingBox().getMinX() + X > help->getBoundingBox().getMinX() && X > 0) 
	
	{
		movedAmountX = X - (help->getBoundingBox().getMinX() - m_Levels[currentLevel]->getBoundingBox().getMinX());
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionX() + (help->getBoundingBox().getMinX() - m_Levels[currentLevel]->getBoundingBox().getMinX()),
			m_Levels[currentLevel]->getPositionY()
		);
	}
	else {
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionX() + X,
			m_Levels[currentLevel]->getPositionY()
		);
	}
}

float OOP::myLevels::getMovedAmountX()
{
	return movedAmountX;
}

void OOP::myLevels::moveBackGroundY(float Y, cocos2d::Scene * help)
{
	movedAmountY = Y;
		if (m_Levels[currentLevel]->getBoundingBox().getMaxY() - Y < help->getBoundingBox().getMaxY() && Y < 0) {
			movedAmountY = (help->getBoundingBox().getMaxY() - m_Levels[currentLevel]->getBoundingBox().getMaxY());
			m_Levels[currentLevel]->setPosition(
				m_Levels[currentLevel]->getPositionX(),
				m_Levels[currentLevel]->getPositionY() + (help->getBoundingBox().getMaxY() - m_Levels[currentLevel]->getBoundingBox().getMaxY())
			);
		}
		else if (m_Levels[currentLevel]->getBoundingBox().getMinY() - Y > help->getBoundingBox().getMinY() && Y > 0) {
			movedAmountY = help->getBoundingBox().getMinY() - m_Levels[currentLevel]->getBoundingBox().getMinY();
			m_Levels[currentLevel]->setPosition(
				m_Levels[currentLevel]->getPositionX(),
				m_Levels[currentLevel]->getPositionY() + (help->getBoundingBox().getMinY() - m_Levels[currentLevel]->getBoundingBox().getMinY())
			);
		}
		else {
			m_Levels[currentLevel]->setPosition(
				m_Levels[currentLevel]->getPositionX(),
				m_Levels[currentLevel]->getPositionY() - Y
			);
		}
}

float OOP::myLevels::getMovedAmountY()
{
	return -movedAmountY;
}

void OOP::myLevels::resetLevel(cocos2d::Scene * help)
{
	m_Levels[currentLevel]->setPosition((m_Levels[currentLevel]->getBoundingBox().size.width / 2), m_Levels[currentLevel]->getBoundingBox().size.height / 2);
}

#endif // !H_MYLEVELS
