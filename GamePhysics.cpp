#include "GamePhysics.h"

void OOP::Physics::newVelocityY(float velocityY, bool upArrow, bool *onGround, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform)
{
	if (*onGround == false) {
		if (upArrow == true && wasHoldingUp != true && jumpBoost >= MIN_JUMPBOOST) {
			if (jumpBoost >= MIN_JUMPBOOST) {
				jumpBoost /= 2;
				new_VelocityY = jumpBoost + velocityY - GRAVITY * TIME_INTERVAL;
			}
		}
		else {
			new_VelocityY = velocityY - GRAVITY * TIME_INTERVAL;
		}
		if (upArrow == false) {
			wasHoldingUp = false;
		}
		
		if (new_VelocityY < 0) {
			if (m_MainCharacter->getBoundingBox().getMinY() > platform->getBoundingBox().getMaxY() &&
				(m_MainCharacter->getPositionX() + (platform->getBoundingBox().size.width / 2)) > platform->getBoundingBox().getMinX()
				&& (m_MainCharacter->getPositionX() - (platform->getBoundingBox().size.width / 2)) < platform->getBoundingBox().getMaxX()) {
				if ((m_MainCharacter->getBoundingBox().getMinY() + new_VelocityY) < platform->getBoundingBox().getMaxY()) {
					new_VelocityY = -(m_MainCharacter->getBoundingBox().getMinY() - platform->getBoundingBox().getMaxY());
				}
			}
		}
	}

	if (*onGround == true) {
		new_VelocityY = 0;
		jumpBoost = 0;
	}
	if(*onGround == true && upArrow == true) {
		new_VelocityY = 10 + jumpBoost;
		*onGround = false;
		wasHoldingUp = true;
	}
}

float OOP::Physics::getVelocityY()
{
	return new_VelocityY;
}

void OOP::Physics::checkOnGround(bool *onGround, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform)
{
	if (m_MainCharacter->getPositionY() == 25) {
		*onGround = true;
	}
	//		bottom player > top plat
	//		center of player in box + box width
	//		left of player > left of box
	//		right of player > right of box
	else if (m_MainCharacter->getBoundingBox().getMinY() == platform->getBoundingBox().getMaxY()) {
		if ((m_MainCharacter->getPositionX() + (platform->getBoundingBox().size.width / 2)) > platform->getBoundingBox().getMinX()
			&& (m_MainCharacter->getPositionX() - (platform->getBoundingBox().size.width / 2)) < platform->getBoundingBox().getMaxX()) {
			*onGround = true;
		}
		else {
			*onGround = false;
		}
	}
	else {
		*onGround = false;
	}
	
}
