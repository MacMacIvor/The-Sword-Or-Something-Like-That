#ifndef H_MYLEVELS
#define H_LEVELS

#include "myLevels.h"

OOP::myLevels::myLevels()
{

	m_Levels.push_back(cocos2d::Sprite::create("TutorialFinalTiles2.jpg"));
	m_Levels.push_back(cocos2d::Sprite::create("CaveTemplateFinal.png"));
	m_Levels.push_back(cocos2d::Sprite::create("CaveTemplate2Final.png"));
	m_Levels.push_back(cocos2d::Sprite::create("CaveTemplate3Image.png"));
	m_Levels.push_back(cocos2d::Sprite::create("Mountain Template 1 Final Image.png"));
	m_Levels.push_back(cocos2d::Sprite::create("Mountain Template 2 Final.png"));
	m_Levels.push_back(cocos2d::Sprite::create("Mountain Template 3 Final Image.png"));

	//testing = cocos2d::Sprite::create("Level 1.PNG");
}

OOP::myLevels::~myLevels()
{
}


void const OOP::myLevels::initLevel(cocos2d::Scene *help) const
{
	m_Levels[currentLevel]->setPosition((m_Levels[currentLevel]->getBoundingBox().size.width / 2), m_Levels[currentLevel]->getBoundingBox().size.height / 2);
	help->addChild(m_Levels[currentLevel], 0);
	//levelOneHitBox[1][1] = 8;// = alevelOneHitBox;
}

void const OOP::myLevels::setLevel(int newLevel)
{
	m_Levels[currentLevel]->release();
	currentLevel = newLevel;
}

cocos2d::Sprite * const OOP::myLevels::getLevel() const
{
	return m_Levels[currentLevel];
}

int const OOP::myLevels::getLevelNum() const
{
	return currentLevel;
}

bool const OOP::myLevels::checkMaxX(int dir, cocos2d::Scene *help)
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

bool const OOP::myLevels::checkMaxY(int dir, cocos2d::Scene * help)
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

void const OOP::myLevels::moveBackGroundX(float X, cocos2d::Scene *help)
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
		movedAmountX = (help->getBoundingBox().getMinX() - m_Levels[currentLevel]->getBoundingBox().getMinX());
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

float const OOP::myLevels::getMovedAmountX() const
{
	return movedAmountX;
}

void const OOP::myLevels::moveBackGroundY(float Y, cocos2d::Scene * help)
{
	movedAmountY = Y;

	if (m_Levels[currentLevel]->getBoundingBox().getMaxY() + Y > help->getBoundingBox().getMaxY() && Y > 0)

	{
		movedAmountY = (help->getBoundingBox().getMaxY() - m_Levels[currentLevel]->getBoundingBox().getMaxY());
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionY() + (help->getBoundingBox().getMaxY() - m_Levels[currentLevel]->getBoundingBox().getMaxY()),
			m_Levels[currentLevel]->getPositionY()
		);
	}
	else if (m_Levels[currentLevel]->getBoundingBox().getMinY() + Y < help->getBoundingBox().getMinY() && Y < 0)

	{
		movedAmountY = (help->getBoundingBox().getMinY() - m_Levels[currentLevel]->getBoundingBox().getMinY());
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionY() + (help->getBoundingBox().getMinY() - m_Levels[currentLevel]->getBoundingBox().getMinY()),
			m_Levels[currentLevel]->getPositionY()
		);
	}
	else {
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionY(),
			m_Levels[currentLevel]->getPositionY() + Y
		);
	}
}

float const OOP::myLevels::getMovedAmountY() const 
{
	return movedAmountY;
}

void const OOP::myLevels::resetLevel(cocos2d::Scene * help)
{
	if (currentLevel > savePrevLevel) {
		m_Levels[savePrevLevel]->removeFromParentAndCleanup(true);
		switch (currentLevel) {
		case 2:
			m_Levels[currentLevel] = cocos2d::Sprite::create("CaveTemplate2Final.png");
			break;
		case 3:
			m_Levels[currentLevel] = cocos2d::Sprite::create("CaveTemplate3Image.png");
			break;
		case 4:
			m_Levels[currentLevel] = cocos2d::Sprite::create("Mountain Template 1 Final Image.png");
			break;
		case 5:
			m_Levels[currentLevel] = cocos2d::Sprite::create("Mountain Template 2 Final.png");
			break;
		case 6:
			m_Levels[currentLevel] = cocos2d::Sprite::create("Mountain Template 3 Final Image.png");
			break;
		case 7:
			m_Levels[currentLevel] = cocos2d::Sprite::create("CaveTemplate2Final.png");
			break;
		}
		help->addChild(m_Levels[currentLevel], 0);
		savePrevLevel++;
	}
	m_Levels[currentLevel]->setPosition((m_Levels[currentLevel]->getBoundingBox().size.width / 2), m_Levels[currentLevel]->getBoundingBox().size.height / 2);
}

double const OOP::myLevels::playerMoveBackgroundX(double X, cocos2d::Scene *helloWorld)
{
	if (X == 0)
	{
		return 0;
	}
	helloWorld->getBoundingBox().getMaxX();
	m_Levels[currentLevel]->getBoundingBox().getMaxX();
	if (m_Levels[currentLevel]->getBoundingBox().getMaxX() + X < helloWorld->getBoundingBox().getMaxX() && X < 0)
	{
		double movedAmount = (helloWorld->getBoundingBox().getMaxX() - m_Levels[currentLevel]->getBoundingBox().getMaxX());
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionX() + movedAmount,
			m_Levels[currentLevel]->getPositionY()
		);
		return movedAmount;
	}
	else if (m_Levels[currentLevel]->getBoundingBox().getMinX() + X > helloWorld->getBoundingBox().getMinX() && X > 0)

	{
		double movedAmount = (helloWorld->getBoundingBox().getMinX() - m_Levels[currentLevel]->getBoundingBox().getMinX());
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionX() + movedAmount,
			m_Levels[currentLevel]->getPositionY()
		);
		return movedAmount;
	}
	else {
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionX() + X,
			m_Levels[currentLevel]->getPositionY()
		);
		return X;
	}
}

double const OOP::myLevels::playerMoveBackgroundY(double Y, cocos2d::Scene *helloWorld)
{
	if (Y == 0)
	{
		return 0;
	}
	helloWorld->getBoundingBox().getMaxY();
	m_Levels[currentLevel]->getBoundingBox().getMaxY();
	if (m_Levels[currentLevel]->getBoundingBox().getMaxY() - Y < helloWorld->getBoundingBox().getMaxY() && Y > 0)
	{
		double movedAmount = (helloWorld->getBoundingBox().getMaxY() - m_Levels[currentLevel]->getBoundingBox().getMaxY());
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionX(),
			m_Levels[currentLevel]->getPositionY() + movedAmount
		);
		return movedAmount;
	}
	else if (m_Levels[currentLevel]->getBoundingBox().getMinY() - Y > helloWorld->getBoundingBox().getMinY() && Y < 0)

	{
		double movedAmount = (helloWorld->getBoundingBox().getMinY() - m_Levels[currentLevel]->getBoundingBox().getMinY());
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionX(),
			m_Levels[currentLevel]->getPositionY() + movedAmount
		);
		return movedAmount;
	}
	else {
		m_Levels[currentLevel]->setPosition(
			m_Levels[currentLevel]->getPositionX(),
			m_Levels[currentLevel]->getPositionY() - Y
		);
		return -Y;
	}
}

#endif // !H_MYLEVELS
