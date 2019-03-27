#ifndef CPP_PLATFORM
#define CPP_PLATFORM

#include "PlatformGenerator.h"
#include <string>

OOP::PlatformGenerator::PlatformGenerator()
	:index(0) {}

cocos2d::Sprite * OOP::PlatformGenerator::getPlatform(int reference)
{
	return m_Platform[reference];
}

void const OOP::PlatformGenerator::generateNew(cocos2d::Scene *help, OOP::myLevels* level)
{
	number = 0;
	for (int i = 0; i < (sizeof levelOneHitBox / sizeof levelOneHitBox[level->getLevelNum()]); i++) { //rows
		for (int j = 0; j < (sizeof levelOneHitBox[level->getLevelNum()] / sizeof(int)); j++) { //collums
			if (levelOneHitBox[i][j] != -1) {
				if (levelOneHitBox[i][j] == 25)
				{
					if (number == 60 || number == 36) {
						types.push_back(1);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));
					}
					else {
						types.push_back(1);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

					}
					m_Platform[number]->setPosition(
						level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
						level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
					);

					help->addChild(m_Platform[number], 1);
					number++;
				}
				else if (levelOneHitBox[i][j] == 0 || levelOneHitBox[i][j] == 1 || levelOneHitBox[i][j] == 2) {
					;
				}
				else {
					types.push_back(2);
					m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));
					m_Platform[number]->setPosition(
						level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
						level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
					);

					help->addChild(m_Platform[number], 1);
					number++;
				}
				
			}
		}
	}

		//m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));
		//if (number > 5) {
			//m_Platform[number]->setPosition(1000 - (200 * (11 - number)), 75 * (number));
		//}
		//else {
			//m_Platform[number]->setPosition(200 * number, 75 * number);
		//}
		//help->addChild(m_Platform[number]);
		//number++;
	vectorSize = m_Platform.size();


}

int const OOP::PlatformGenerator::getClosestY(float pointX, float pointY, float velocityY)
{
	int tempClosest = 0;
	typeHitBoxY = types[0];

	

	if (velocityY <= 0) {
		for (int i = 0; i < m_Platform.size(); i++) {
			if ((pointX > m_Platform[i]->getBoundingBox().getMinX()
				&& (pointX) <= m_Platform[i]->getBoundingBox().getMaxX()) ||
				(pointX > m_Platform[i]->getBoundingBox().getMinX() &&
					pointX < m_Platform[i]->getBoundingBox().getMaxX()) ||
					(pointX > m_Platform[i]->getBoundingBox().getMinX() &&
						pointX < m_Platform[i]->getBoundingBox().getMaxX())) {
				if (pointY >= m_Platform[i]->getBoundingBox().getMaxY()) {
					if (((m_Platform[tempClosest]->getBoundingBox().getMaxY()) <= (m_Platform[i]->getBoundingBox().getMaxY())) || ((pointY - m_Platform[tempClosest]->getBoundingBox().getMaxY()) < 0)) {
						float distance = pointX - m_Platform[tempClosest]->getBoundingBox().getMidX();
						if (distance < 0) {
							distance *= -1;
						}
						float distance2 = (pointX - m_Platform[i]->getBoundingBox().getMidX());
						if (distance2 < 0) {
							distance2 *= -1;
						}
						if (distance2 <= distance) {
							tempClosest = i;
						}
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < m_Platform.size(); i++) {
			if ((pointX > m_Platform[i]->getBoundingBox().getMinX()
				&& (pointX) <= m_Platform[i]->getBoundingBox().getMaxX()) ||
				(pointX > m_Platform[i]->getBoundingBox().getMinX() &&
					pointX < m_Platform[i]->getBoundingBox().getMaxX()) ||
					(pointX > m_Platform[i]->getBoundingBox().getMinX() &&
						pointX < m_Platform[i]->getBoundingBox().getMaxX())) {
				if (pointY <= m_Platform[i]->getBoundingBox().getMinY()) {
					if (((m_Platform[tempClosest]->getBoundingBox().getMinY() - pointY) > (m_Platform[i]->getBoundingBox().getMinY() - pointY)) || (((m_Platform[tempClosest]->getBoundingBox().getMinY() - pointY) < 0))) {
						tempClosest = i;
						typeHitBoxY = types[i];
					}
				}
			}
		}
	}
	return tempClosest;
}

int const OOP::PlatformGenerator::getClosestX(cocos2d::Sprite * character, float velocityX)
{
	int tempClosest = 0;
	typeHitBoxX = types[0];

	//if left = right vise versa
	//if player sprite in platform sprite
	//p max < 
	//if (m_MainCharacter->getBoundingBox().getMaxX() == );

	if (velocityX > 0) { //Moving left
		for (int i = 0; i < m_Platform.size(); i++) {
			//if (
				//(character->getPositionY() < m_Platform[i]->getBoundingBox().getMaxY() &&
					//character->getPositionY() >= m_Platform[i]->getBoundingBox().getMinY()
					//)
					//) {
			if ((character->getBoundingBox().getMaxY() >= m_Platform[i]->getBoundingBox().getMinY() &&
				character->getBoundingBox().getMinY() < m_Platform[i]->getBoundingBox().getMaxY()) || (
					character->getBoundingBox().getMidY() < m_Platform[i]->getBoundingBox().getMaxY() &&
					character->getBoundingBox().getMidY() >= m_Platform[i]->getBoundingBox().getMinY()) ) {

				if (character->getBoundingBox().getMinX() >= m_Platform[i]->getBoundingBox().getMaxX()) {
					if (((character->getBoundingBox().getMinX() - m_Platform[tempClosest]->getBoundingBox().getMaxX()) >=
						(character->getBoundingBox().getMinX() - m_Platform[i]->getBoundingBox().getMaxX())) ||
						(character->getBoundingBox().getMinX() - m_Platform[tempClosest]->getBoundingBox().getMaxX() < 0)) {
						tempClosest = i;
					}
				}
			}
		}
	}
	else if (velocityX < 0) { //Moving right
		for (int i = 0; i < m_Platform.size(); i++) {
			if ((character->getBoundingBox().getMaxY() >= m_Platform[i]->getBoundingBox().getMinY() &&
				character->getBoundingBox().getMinY() < m_Platform[i]->getBoundingBox().getMaxY()) || (
				character->getBoundingBox().getMidY() < m_Platform[i]->getBoundingBox().getMaxY() &&
					character->getBoundingBox().getMidY() >= m_Platform[i]->getBoundingBox().getMinY()) ) {

				if (character->getBoundingBox().getMaxX() <= m_Platform[i]->getBoundingBox().getMinX()) {
					if ((m_Platform[tempClosest]->getBoundingBox().getMinX() - character->getBoundingBox().getMaxX()) >
						(m_Platform[i]->getBoundingBox().getMinX() - character->getBoundingBox().getMaxX()) ||
						m_Platform[tempClosest]->getBoundingBox().getMinX() - character->getBoundingBox().getMaxX() < 0) {
						tempClosest = i;
					}
				}


			}

		}
	}
	else {
		for (int i = 0; i < m_Platform.size(); i++) {
			if (character->getBoundingBox().getMaxY() >= m_Platform[i]->getBoundingBox().getMinY() &&
				character->getBoundingBox().getMinY() <= m_Platform[i]->getBoundingBox().getMaxY()) {
				if (character->getBoundingBox().getMaxX() == m_Platform[i]->getBoundingBox().getMinX() ||
					character->getBoundingBox().getMinX() == m_Platform[i]->getBoundingBox().getMaxX()) {
					tempClosest = i;
				}
			}
		}
	}
	return tempClosest;
}

void const OOP::PlatformGenerator::moveHitBoxesX(float X)
{
	for (int i = 0; i < m_Platform.size(); i++) {
		m_Platform[i]->setPosition(
			m_Platform[i]->getPositionX() + X,
			m_Platform[i]->getPositionY()
			);
	}
}

void const OOP::PlatformGenerator::moveHitBoxesY(float Y)
{
	for (int i = 0; i < m_Platform.size(); i++) {
		m_Platform[i]->setPosition(
			m_Platform[i]->getPositionX(),
			m_Platform[i]->getPositionY() + Y
		);
	}
}

int const OOP::PlatformGenerator::getTypeHitBoxX() const
{
	return typeHitBoxX;
}

int const OOP::PlatformGenerator::getTypeHitBoxY() const
{
	return typeHitBoxY;
}

void const OOP::PlatformGenerator::resetHitBox(cocos2d::Scene *help, OOP::myLevels* level)
{
	for (int i = m_Platform.size() - 1; i >= 0; i--) {
		m_Platform[i]->removeFromParentAndCleanup(true);
	}
	for (int i = m_Platform.size() - 1; i >= 0; i--) {
		m_Platform.erase((m_Platform.begin() + (i)));
	}
	int hello = m_Platform.size();
	int testing = 0;

	OOP::PlatformGenerator::generateNew(help, level);
}

#endif







/*
float OOP::PlatformGenerator::getPositionX(cocos2d::Sprite * platform)
{
	std::vector<cocos2d::Sprite *>::iterator necessaryStep = std::find(m_Platform.begin(), m_Platform.end(), platform);
	int position = std::distance(m_Platform.begin(), necessaryStep);
	return positionX[position];
}
float OOP::PlatformGenerator::getPositionY(cocos2d::Sprite * platform)
{
	std::vector<cocos2d::Sprite *>::iterator necessaryStep = std::find(m_Platform.begin(), m_Platform.end(), platform);
	int position = std::distance(m_Platform.begin(), necessaryStep);
	return positionY[position];
}
*/