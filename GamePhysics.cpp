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
	if (m_MainCharacter->getBoundingBox().getMinY() <= platform->getBoundingBox().getMaxY() && m_MainCharacter->getBoundingBox().getMinY() >= platform->getBoundingBox().getMinY()) {
		m_MainCharacter->setPositionY(platform->getBoundingBox().getMaxY());
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

void const OOP::Physics::saveInfoBecauseIHateCocos(OOP::PlatformGenerator *a_PlatformManager, double * velocityY, double * velocityX, int * againstWall, bool * a_onGround, cocos2d::Sprite * a_MainCharacter, int * health)
{
	playerVelocityX = velocityX;
	playerVelocityY = velocityY;
	m_PlatformManager = a_PlatformManager;
	onGround = a_onGround;
	playerAgainstWall = againstWall;
	m_MainCharacter = a_MainCharacter;
	playerHealth = health;
}

void const OOP::Physics::playerPhysics(bool upArrow, bool leftArrow, bool rightArrow, bool zKey, bool shiftKey)
{

	//Possibilities
	//Against wall falling
	//Falling normally
	//Falling slower (until reaches max height)
	//Moving Left
	//Moving Right
	//Wall Jump
	//Hold Wall
	//Movement in X direction
	if (*playerAgainstWall == 0) {
		if (rightArrow == true) {
			if (*playerVelocityX == 0) {
				*playerVelocityX = -1;
			}
			else if (*playerVelocityX >= -10 && *playerVelocityX < 0) {
				*playerVelocityX *= 1.5;
			}
			else if (*playerVelocityX > 0) {
				*playerVelocityX /= 1.5;
				if (*playerVelocityX <= 1) {
					*playerVelocityX = 0;
				}
			}
		}
		else if (leftArrow == true) {
			if (*playerVelocityX == 0) {
				*playerVelocityX = 1;
			}
			else if (*playerVelocityX <= 10 && *playerVelocityX > 0) {
				*playerVelocityX *= 1.5;
			}
			else if (*playerVelocityX < 0) {
				*playerVelocityX /= 1.5;
				if (*playerVelocityX >= -1) {
					*playerVelocityX = 0;
				}
			}
		}
		else {
			if (*playerVelocityX >= 1 || *playerVelocityX <= -1) {
				*playerVelocityX /= 1.25;
			}
			else {
				*playerVelocityX = 0;
			}
		}
	}
	else if (*playerAgainstWall == 1) {
		if (leftArrow == true) {
			if (*playerVelocityX == 0) {
				*playerVelocityX = 1;
			}
			else if (*playerVelocityX <= 10 && *playerVelocityX > 0) {
				*playerVelocityX *= 1.5;
			}
			else if (*playerVelocityX < 0) {
				*playerVelocityX /= 1.5;
				if (*playerVelocityX >= -1) {
					*playerVelocityX = 0;
				}
			}
		}
		else {
			if (*playerVelocityX >= 1 || *playerVelocityX <= -1) {
				*playerVelocityX /= 1.25;
			}
			else {
				*playerVelocityX = 0;
			}
		}
	}
	else {
		if (rightArrow == true) {
			if (*playerVelocityX == 0) {
				*playerVelocityX = -1;
			}
			else if (*playerVelocityX >= -10 && *playerVelocityX < 0) {
				*playerVelocityX *= 1.5;
			}
			else if (*playerVelocityX > 0) {
				*playerVelocityX /= 1.5;
				if (*playerVelocityX <= 1) {
					*playerVelocityX = 0;
				}
			}
		}
		else {
			if (*playerVelocityX >= 1 || *playerVelocityX <= -1) {
				*playerVelocityX /= 1.25;
			}
			else {
				*playerVelocityX = 0;
			}
		}
	}
	//Movement in Y direction and wall Jump in hererererererere
	if (*onGround == false && *playerAgainstWall == 0) {
		if (upArrow == true && *playerVelocityY > 0) {
			*playerVelocityY -= 0.5 * GRAVITY * TIME_INTERVAL;
		}
		else if (upArrow == false && *playerVelocityY > 0) {
			*playerVelocityY -= 2 * GRAVITY * TIME_INTERVAL;
		}
		else {
			*playerVelocityY -= GRAVITY * TIME_INTERVAL;
		}
	}
	else if (*onGround == false && *playerAgainstWall == 1) {
		if (upArrow == true && *playerVelocityY > 0) {
			*playerVelocityY -= 0.5 * GRAVITY * TIME_INTERVAL;
		}
		else if (upArrow == false && *playerVelocityY > 0) {
			*playerVelocityY -= 2 * GRAVITY * TIME_INTERVAL;
		}
		else if (shiftKey == true) {
			if (zKey == true) {
				*playerVelocityX = 20;
				*playerVelocityY = 8;
			}
			else {
				*playerVelocityY = 0;
			}
		}
		else if (rightArrow == true) {
			if (zKey == true) {
				*playerVelocityX = 20;
				*playerVelocityY = 8;
			}
			else {
				*playerVelocityY -= 0.15 * GRAVITY * TIME_INTERVAL;
			}
		}
		else {
			*playerVelocityY -= GRAVITY * TIME_INTERVAL;
		}
	}
	else if (*onGround == false && *playerAgainstWall == 2) {
		if (upArrow == true && *playerVelocityY > 0) {
			*playerVelocityY -= 0.5 * GRAVITY * TIME_INTERVAL;
		}
		else if (upArrow == false && *playerVelocityY > 0) {
			*playerVelocityY -= 2 * GRAVITY * TIME_INTERVAL;
		}
		else if (shiftKey == true) {
			if (zKey == true) {
				*playerVelocityX = -20;
				*playerVelocityY = 8;
			}
			else {
				*playerVelocityY = 0;
			}
		}
		else if (leftArrow == true) {
			if (zKey == true) {
				*playerVelocityX = -20;
				*playerVelocityY = 8;
			}
			else {
				*playerVelocityY -= 0.15 * GRAVITY * TIME_INTERVAL;
			}
		}
		else {
			*playerVelocityY -= GRAVITY * TIME_INTERVAL;
		}
	}
	else {
		if (upArrow == true) {
			*playerVelocityY = 10;
		}
	}

	//position.x -= m_mainCharacter.getVelocityX();
	//position.y += m_mainCharacter.getVelocityY();

	m_MainCharacter->setPosition(m_MainCharacter->getPositionX() - *playerVelocityX, m_MainCharacter->getPositionY() + *playerVelocityY);
	
	bool alreadyMovedX = false;
	bool alreadyMovedY = false;
	double Goal1 = 999;
	double Goal2 = 999;
	double Goal3 = 999;
	double Goal4 = 999;
	for (unsigned int i = 0; i < m_PlatformManager->vectorSize; i++) { 
		//Needs to check:
		//Bottom -top
		//Top -bottom
		//Left -right
		//Right -left
		//Bottom -top
		//Right -left

		

		if (m_MainCharacter->getBoundingBox().getMinY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
			m_MainCharacter->getBoundingBox().getMinY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY() && ((
				m_MainCharacter->getBoundingBox().getMinX() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() &&
				m_MainCharacter->getBoundingBox().getMinX() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX()) || (
					m_MainCharacter->getBoundingBox().getMaxX() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() &&
					m_MainCharacter->getBoundingBox().getMaxX() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX()))) {
			if (*playerVelocityY < 0) {
				if (m_PlatformManager->getPlayerTypeOfHitBox(i) == 2) {
					*playerHealth = 0;
				}
				//m_MainCharacter->setPositionY(m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() + m_MainCharacter->getBoundingBox().size.height / 2);
				Goal1 = m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() - m_MainCharacter->getBoundingBox().getMinY();
				//*playerVelocityY = 0;
				//*onGround = true;
				alreadyMovedY = true;
			}
		}
		//Top -bottom
		else if (m_MainCharacter->getBoundingBox().getMaxY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
			m_MainCharacter->getBoundingBox().getMaxY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY() && ((
				m_MainCharacter->getBoundingBox().getMinX() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() &&
				m_MainCharacter->getBoundingBox().getMinX() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX()) || (
					m_MainCharacter->getBoundingBox().getMaxX() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() &&
					m_MainCharacter->getBoundingBox().getMaxX() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX()))) {
			if (*playerVelocityY > 0) {
				if (m_PlatformManager->getPlayerTypeOfHitBox(i) == 2) {
					*playerHealth = 0;
				}
				alreadyMovedY = true;
				//m_MainCharacter->setPositionY(m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY() - m_MainCharacter->getBoundingBox().size.height / 2);
				Goal2 = m_MainCharacter->getBoundingBox().getMaxY() - m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY();
			}
		}
		//Checks on the ground
		else {
			if (m_MainCharacter->getBoundingBox().getMinY() == m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() && ((
				m_MainCharacter->getBoundingBox().getMinX() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() &&
				m_MainCharacter->getBoundingBox().getMinX() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX()) || (
					m_MainCharacter->getBoundingBox().getMaxX() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() &&
					m_MainCharacter->getBoundingBox().getMaxX() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX()))) {
				alreadyMovedY = true;
				*onGround = true;
			}
			else if (alreadyMovedY == false) {
				*onGround = false;
			}
		}




		if ((m_MainCharacter->getBoundingBox().getMaxX() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() &&
			m_MainCharacter->getBoundingBox().getMaxX() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX()) &&
			((m_MainCharacter->getBoundingBox().getMinY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
				m_MainCharacter->getBoundingBox().getMinY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY())
				||
				(m_MainCharacter->getBoundingBox().getMaxY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
					m_MainCharacter->getBoundingBox().getMaxY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY())
				||
				(m_MainCharacter->getBoundingBox().getMidY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
					m_MainCharacter->getBoundingBox().getMidY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY()))
			) {
			if (*playerVelocityX < 0) {
				//m_MainCharacter->setPositionX(m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX() - m_MainCharacter->getBoundingBox().size.width / 2);
				Goal3 = m_MainCharacter->getBoundingBox().getMaxX() - m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX();
				alreadyMovedX = true;
				//*playerAgainstWall = 1;
				//*playerVelocityX = 0;
			}
		}
		//Left -right
		else if ((m_MainCharacter->getBoundingBox().getMinX() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() &&
			m_MainCharacter->getBoundingBox().getMinX() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX()) &&
			((m_MainCharacter->getBoundingBox().getMinY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
				m_MainCharacter->getBoundingBox().getMinY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY())
				||
				(m_MainCharacter->getBoundingBox().getMaxY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
					m_MainCharacter->getBoundingBox().getMaxY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY())
				||
				(m_MainCharacter->getBoundingBox().getMidY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
					m_MainCharacter->getBoundingBox().getMidY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY()))
			) {
			if (*playerVelocityX > 0) {
				//m_MainCharacter->setPositionX(m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() + m_MainCharacter->getBoundingBox().size.width / 2);
				//*playerAgainstWall = 2;
				//*playerVelocityX = 0;
				alreadyMovedX = true;
				Goal4 = m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() - m_MainCharacter->getBoundingBox().getMinX();
			}
			
		}
		//If not inside a box
		else if (alreadyMovedX == false) {
			//Left of player
			if (m_MainCharacter->getBoundingBox().getMinX() == m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() && ((
				m_MainCharacter->getBoundingBox().getMinY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
				m_MainCharacter->getBoundingBox().getMinY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY()) || (
					m_MainCharacter->getBoundingBox().getMaxY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
					m_MainCharacter->getBoundingBox().getMaxY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY()) || (
						m_MainCharacter->getBoundingBox().getMidY() <= m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
						m_MainCharacter->getBoundingBox().getMidY() >= m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY()))) {
				alreadyMovedX = true;
				*playerAgainstWall = 2;
			}
			//Right
			else if (m_MainCharacter->getBoundingBox().getMaxX() == m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX() && ((
				m_MainCharacter->getBoundingBox().getMinY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
				m_MainCharacter->getBoundingBox().getMinY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY()) || (
					m_MainCharacter->getBoundingBox().getMaxY() < m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
					m_MainCharacter->getBoundingBox().getMaxY() > m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY()) || (
						m_MainCharacter->getBoundingBox().getMidY() <= m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxY() &&
						m_MainCharacter->getBoundingBox().getMidY() >= m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY()))) {
				alreadyMovedX = true;
				*playerAgainstWall = 1;
			}
			else {
				*playerAgainstWall = 0;
			}
		}
	}
	if (Goal1 <= Goal2 && Goal1 <= Goal3 && Goal1 <= Goal4 && Goal1 != 999) {
		*playerVelocityY = 0;
		*onGround = true;
		m_MainCharacter->setPositionY((m_MainCharacter->getPositionY() + Goal1));
	}
	else if (Goal2 <= Goal1 && Goal2<= Goal3 && Goal2 <= Goal4 && Goal2 != 999) {
		//m_MainCharacter->setPositionY(m_PlatformManager->getPlatform(i)->getBoundingBox().getMinY() - m_MainCharacter->getBoundingBox().size.height / 2);
		m_MainCharacter->setPositionY((m_MainCharacter->getPositionY() - Goal1));
	}
	else if (Goal3 <= Goal1 && Goal3 <= Goal2 && Goal3 <= Goal4 && Goal3 != 999) {
		//m_MainCharacter->setPositionX(m_PlatformManager->getPlatform(i)->getBoundingBox().getMinX() - m_MainCharacter->getBoundingBox().size.width / 2);
		m_MainCharacter->setPositionX(m_MainCharacter->getPositionX() - Goal3);
		*playerAgainstWall = 1;
		*playerVelocityX = 0;
	}
	else if (Goal4 <= Goal1 && Goal4 <= Goal2 && Goal4 <= Goal3 && Goal4 != 999) {
		//m_MainCharacter->setPositionX(m_PlatformManager->getPlatform(i)->getBoundingBox().getMaxX() + m_MainCharacter->getBoundingBox().size.width / 2);
		m_MainCharacter->setPositionX(m_MainCharacter->getPositionX() + Goal4);
		*playerAgainstWall = 2;
		*playerVelocityX = 0;
	}
}

