#include "GamePhysics.h"

void const OOP::Physics::newVelocityY(float velocityY, bool upArrow, bool leftArrow, bool rightArrow, bool zKey, bool shiftKey, int * againstWall, bool *onGround, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform)
{
	if (wallJumpBonus > 0) {
		wallJumpBonus -= 1;
	}
	else if (wallJumpBonus < 0) {
		wallJumpBonus += 1;
	}

	if (*onGround == false) {
		if (upArrow == true && wasHoldingUp == true && velocityY > 4) {
			new_VelocityY = velocityY - 0.5 * GRAVITY * TIME_INTERVAL;
		}
		else if (wasHoldingUp == false && velocityY > 0) {
			new_VelocityY = velocityY - 3 * GRAVITY * TIME_INTERVAL;
		}



		else {
			//if against wall holding shift
			//if against left wall with left key pressed
			//if against right wall with right key pressed

			
			if (*againstWall == 1 && rightArrow == true && velocityY <= 0) {
				if (wasHoldingZ == false && zKey == true) {
					new_VelocityY = 6;
					wallJumpBonus = 8;
					*againstWall = 0;
				}
				else {
					new_VelocityY = velocityY - GRAVITY / 4 * TIME_INTERVAL;
				}
			}
			else if (*againstWall == 2 && leftArrow == true && velocityY <= 0) {
				if (wasHoldingZ == false && zKey == true) {
					new_VelocityY = 6;
					wallJumpBonus = -8;
					*againstWall = 0;
				}
				else {
					new_VelocityY = velocityY - GRAVITY / 4 * TIME_INTERVAL;
				}
			}
			else {
				new_VelocityY = velocityY - GRAVITY * TIME_INTERVAL;
			}

			if ((*againstWall == 1 || *againstWall == 2) && shiftKey == true) {
				new_VelocityY = 0;
			}
			

		}



		if (upArrow == false) {
			wasHoldingUp = false;
		}
		if (zKey == true) {
			wasHoldingZ = true;
		}
		else {
			wasHoldingZ = false;
		}



		if (new_VelocityY < 0) {
			if (m_MainCharacter->getBoundingBox().getMinY() > platform->getBoundingBox().getMaxY()) {
				if ((m_MainCharacter->getPositionX() > platform->getBoundingBox().getMinX()
					&& (m_MainCharacter->getPositionX()) <= platform->getBoundingBox().getMaxX()) ||
					(m_MainCharacter->getBoundingBox().getMaxX() > platform->getBoundingBox().getMinX() &&
						m_MainCharacter->getBoundingBox().getMaxX() < platform->getBoundingBox().getMaxX()) ||
						(m_MainCharacter->getBoundingBox().getMinX() > platform->getBoundingBox().getMinX() &&
							m_MainCharacter->getBoundingBox().getMinX() < platform->getBoundingBox().getMaxX())) {
					if ((m_MainCharacter->getBoundingBox().getMinY() + new_VelocityY) < platform->getBoundingBox().getMaxY()) {
						new_VelocityY = -(m_MainCharacter->getBoundingBox().getMinY() - platform->getBoundingBox().getMaxY());
					}
				}
			}
		}
		else if (new_VelocityY > 0) {
			if (m_MainCharacter->getBoundingBox().getMaxY() < platform->getBoundingBox().getMinY()) {
				if ((m_MainCharacter->getPositionX() > platform->getBoundingBox().getMinX()
					&& (m_MainCharacter->getPositionX()) <= platform->getBoundingBox().getMaxX()) ||
					(m_MainCharacter->getBoundingBox().getMaxX() > platform->getBoundingBox().getMinX() &&
						m_MainCharacter->getBoundingBox().getMaxX() < platform->getBoundingBox().getMaxX()) ||
						(m_MainCharacter->getBoundingBox().getMinX() > platform->getBoundingBox().getMinX() &&
							m_MainCharacter->getBoundingBox().getMinX() < platform->getBoundingBox().getMaxX())) {
					if ((m_MainCharacter->getBoundingBox().getMaxY() + new_VelocityY) > platform->getBoundingBox().getMinY()) {
						new_VelocityY = (platform->getBoundingBox().getMinY() - m_MainCharacter->getBoundingBox().getMaxY());
					}
				}
			}
			if (m_MainCharacter->getBoundingBox().getMaxY() == platform->getBoundingBox().getMinY()) {

				new_VelocityY = 0;
			}
		}
	}
	





	if (*onGround == true) {
		new_VelocityY = 0;
	}
	if(*onGround == true && upArrow == true) {
		new_VelocityY = 8;
		*onGround = false;
		wasHoldingUp = true;
	}
}

void const OOP::Physics::newVelocityX(float velocityX, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform)
{
	new_VelocityX = 0;
	if (wallJumpBonus != 0) {
		new_VelocityX = wallJumpBonus;
	}
	else {
		new_VelocityX = velocityX;
	}

	if (new_VelocityX > 0) {

		//if ((m_MainCharacter->getBoundingBox().getMaxY() >= platform->getBoundingBox().getMinY() &&
			//m_MainCharacter->getBoundingBox().getMinY() < platform->getBoundingBox().getMaxY()) || (
				//m_MainCharacter->getBoundingBox().getMidY() < platform->getBoundingBox().getMaxY() &&
				//m_MainCharacter->getBoundingBox().getMidY() >= platform->getBoundingBox().getMinY()) ) {
		if ((m_MainCharacter->getBoundingBox().getMinY() < platform->getBoundingBox().getMinY() && m_MainCharacter->getBoundingBox().getMaxY() < platform->getBoundingBox().getMinY()))
		{
			;
		}
		else {
			if (m_MainCharacter->getBoundingBox().getMinX() >= platform->getBoundingBox().getMaxX()) {
				if (m_MainCharacter->getBoundingBox().getMinX() - velocityX < platform->getBoundingBox().getMaxX()) {
					new_VelocityX = -(platform->getBoundingBox().getMaxX() - m_MainCharacter->getBoundingBox().getMinX());
				}
			}
			//}
		}
	}
	else if (new_VelocityX < 0) {

		//if ((m_MainCharacter->getBoundingBox().getMaxY() >= platform->getBoundingBox().getMinY() &&
			//m_MainCharacter->getBoundingBox().getMinY() < platform->getBoundingBox().getMaxY()) || (
				//m_MainCharacter->getBoundingBox().getMidY() < platform->getBoundingBox().getMaxY() &&
				//m_MainCharacter->getBoundingBox().getMidY() >= platform->getBoundingBox().getMinY()) ){

			if (m_MainCharacter->getBoundingBox().getMaxX() <= platform->getBoundingBox().getMinX()) {
				if (m_MainCharacter->getBoundingBox().getMaxX() - velocityX > platform->getBoundingBox().getMinX()) {
					new_VelocityX = -(platform->getBoundingBox().getMinX() - m_MainCharacter->getBoundingBox().getMaxX());
				}
			}
		//}
	}
}

float const OOP::Physics::getVelocityY() const 
{
	return new_VelocityY;
}

float const OOP::Physics::getVelocityX() const 
{
	return new_VelocityX;
}

void const OOP::Physics::checkOnGround(bool *onGround, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform, int typeOfHitBoxY, int * health)
{
	if (m_MainCharacter->getPositionY() == 25) {
		;//*onGround = true;
	}
	//		bottom player > top plat
	//		center of player in box + box width
	//		left of player > left of box
	//		right of player > right of box
	else if (m_MainCharacter->getBoundingBox().getMinY() == platform->getBoundingBox().getMaxY()) {
		if ((m_MainCharacter->getPositionX() + (platform->getBoundingBox().size.width / 2)) > platform->getBoundingBox().getMinX()
			&& (m_MainCharacter->getPositionX() - (platform->getBoundingBox().size.width / 2)) < platform->getBoundingBox().getMaxX()) {
			*onGround = true;
			if (typeOfHitBoxY == 2) {
				*health -= 10;
			}
		}
		else {
			*onGround = false;
		}
	}
	else {
		*onGround = false;
	}
	
}

void const OOP::Physics::checkAgainstWall(int * againstWall, cocos2d::Sprite * m_MainCharacter, cocos2d::Sprite * platform, int typeOfHitBoxX, int * health)
{
	//if left = right vise versa
	//if player sprite in platform sprite
	//p max < 
	//if (m_MainCharacter->getBoundingBox().getMaxX() == );
	if ((m_MainCharacter->getBoundingBox().getMaxY() >= platform->getBoundingBox().getMinY() &&
		m_MainCharacter->getBoundingBox().getMinY() < platform->getBoundingBox().getMaxY()) || (
			m_MainCharacter->getBoundingBox().getMidY() < platform->getBoundingBox().getMaxY() &&
			m_MainCharacter->getBoundingBox().getMidY() >= platform->getBoundingBox().getMinY())) {

		if (m_MainCharacter->getBoundingBox().getMaxX() == platform->getBoundingBox().getMinX()) { //Right side
			*againstWall = 1;
			if (typeOfHitBoxX == 2) {
				*health -= 10;
			}
		}
		else if (m_MainCharacter->getBoundingBox().getMinX() == platform->getBoundingBox().getMaxX()) { //Left side
			*againstWall = 2;
			if (typeOfHitBoxX == 2) {
				*health -= 10;
			}
		}
		else {
			*againstWall = 0;
		}
	}
	else {
		*againstWall = 0;
	}


}
