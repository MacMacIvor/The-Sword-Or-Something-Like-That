#include "PlatformGenerator.h"

OOP::PlatformGenerator::PlatformGenerator()
//cocos2d::Scene * HelloWorld
{
	cocos2d::Sprite* m_filler = (cocos2d::Sprite::create("testforms.png"));
	m_Platform.push_back(m_filler);
}

cocos2d::Sprite * OOP::PlatformGenerator::getPlatform(int reference)
{
	return m_Platform[reference];
}

void OOP::PlatformGenerator::generateNew(int index)
{
	cocos2d::Sprite* m_filter[90];
	m_filter[index] = (cocos2d::Sprite::create("testforms.png"));
	m_Platform.push_back(m_filter[index]);
}

int OOP::PlatformGenerator::getSize()
{
	return m_Platform.size();
}

int OOP::PlatformGenerator::getClosest(cocos2d::Sprite * character)
{
	int tempClosest = 0;
	for (int i = 0; i < m_Platform.size(); i++) {
		if ((character->getPositionX() + (m_Platform[i]->getBoundingBox().size.width / 2) > m_Platform[i]->getBoundingBox().getMinX()
			&& (character->getPositionX() - (m_Platform[i]->getBoundingBox().size.width / 2)) < m_Platform[i]->getBoundingBox().getMaxX())) {
			if (character->getBoundingBox().getMinY() >= m_Platform[i]->getBoundingBox().getMaxY()){
				if ((m_Platform[tempClosest]->getBoundingBox().getMaxY()) < (m_Platform[i]->getBoundingBox().getMaxY())) {
					tempClosest = i;
				}
			}
		}
	}
	return tempClosest;
}



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