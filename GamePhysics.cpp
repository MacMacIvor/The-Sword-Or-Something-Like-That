#include "GamePhysics.h"

void OOP::Physics::newVelocityY(float velocityY, float positionY, bool upArrow)
{
	if (positionY > 25) {
		new_VelocityY = velocityY - GRAVITY * TIME_INTERVAL;
	}
	if (positionY == 25) {
		new_VelocityY = 0;
	}
	if (positionY == 25 && upArrow == true) {
		new_VelocityY = 10;
	}
}

float OOP::Physics::getVelocityY()
{
	return new_VelocityY;
}
