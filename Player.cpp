#include "Player.h"

OOP::Player::Player()
	:m_MainCharacter(cocos2d::Sprite::create("Capture1.PNG")), IHATECOCOSIDONTKNOWWHYTHISISSOFINICKYTOGETTOWORK(cocos2d::Sprite::create("Dead.png")), velocityX(0), velocityY(0)
{
	m_Health.push_back(cocos2d::Sprite::create("Health.png"));
	m_Health.push_back(cocos2d::Sprite::create("Health.png"));
	m_Health.push_back(cocos2d::Sprite::create("Health.png"));

	initAnimations();
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
			if (aniCount != 1) {
				direction = false;
				runAnimation(testframes);
				aniCount = 1;
			}
		}
		else if (keyBoard.getLeftArrow() == true) {
			if (aniCount != 2) {
				direction = true;
				runAnimation(testframes);
				aniCount = 2;
			}
		}
		else {
			if (aniCount != 0)
			{
				runAnimation(A_idle);
				aniCount = 0;
			}
		}
		
		toCalculate.checkOnGround(&onGround, m_MainCharacter, platformY, typeOfHitBoxY, &health);
		toCalculate.checkAgainstWall(&againstWall, m_MainCharacter, platformX, typeOfHitBoxX, &health);

		toCalculate.newVelocityY(velocityY, keyBoard.getUpArrow(), keyBoard.getLeftArrow(), keyBoard.getRightArrow(), keyBoard.getZKey(), keyBoard.getShiftKey(), &againstWall, &onGround, m_MainCharacter, platformY);
		velocityY = toCalculate.getVelocityY();

		toCalculate.newVelocityX(velocityX, m_MainCharacter, platformX);
		velocityX = toCalculate.getVelocityX();

		attack();
		if (attCooldown)
		{
			attCooldown++;
		}
		if (attCooldown >= 30)
		{
			attCooldown = 0;
		}

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
	m_MainCharacter->setPosition(100, 400);
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

void const OOP::Player::updatePlayer()
{
	if (keyBoard.getRightArrow() == true) {
		if (aniCount != 1) {
			direction = false;
			runAnimation(testframes);
			aniCount = 1;
		}
	}
	else if (keyBoard.getLeftArrow() == true) {
		if (aniCount != 2) {
			direction = true;
			runAnimation(testframes);
			aniCount = 2;
		}
	}
	else {
		if (aniCount != 0)
		{
			runAnimation(A_idle);
			aniCount = 0;
		}
	}

	toCalculate.playerPhysics(keyBoard.getUpArrow(), keyBoard.getLeftArrow(), keyBoard.getRightArrow(), keyBoard.getZKey(), keyBoard.getShiftKey());

	attack();
	if (attCooldown)
	{
		attCooldown++;
	}
	if (attCooldown >= 30)
	{
		attCooldown = 0;
	}
}

void const OOP::Player::saveInfoBecauseIHateCocos(OOP::PlatformGenerator *a_PlatformManager, double * velocityY, double * velocityX, int * againstWall, bool * onGround, cocos2d::Sprite * a_MainCharacter, int * health)
{
	toCalculate.saveInfoBecauseIHateCocos(a_PlatformManager, velocityY, velocityX, againstWall, onGround, a_MainCharacter, health);
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
void OOP::Player::initAnimations()
{

	frameCache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
	frameCache->addSpriteFramesWithFile("r.plist");
	//CCArray* testFrames = new CCArray;
	for (int i = 1; i <= 8; i++)
	{
		cocos2d::CCString* filename = cocos2d::CCString::createWithFormat("r%d.png", i);
		cocos2d::CCSpriteFrame* frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
		testframes.pushBack(frame);
	}

	testAnim = cocos2d::CCAnimation::createWithSpriteFrames(testframes, 0.1f);
	action = cocos2d::CCRepeatForever::create(cocos2d::CCAnimate::create(testAnim));

	//idle animation
	for (int i = 1; i <= 5; i++)
	{
		cocos2d::CCString* filename = cocos2d::CCString::createWithFormat("r1.png", i);
		cocos2d::CCSpriteFrame* frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
		
		A_idle.pushBack(frame);
	}
	


}

void OOP::Player::runAnimation(cocos2d::Vector<cocos2d::CCSpriteFrame *> animation)
{
	m_MainCharacter->stopAllActions();
		cocos2d::CCAnimation *newtestAnim = cocos2d::CCAnimation::createWithSpriteFrames(animation, 0.1f);
	cocos2d::CCAction *action = cocos2d::CCRepeatForever::create(cocos2d::CCAnimate::create(newtestAnim));
	m_MainCharacter->runAction(action);
	
	if (direction == true)
	{
		m_MainCharacter->setScaleX(-1.0f);
	}
	else
	{
		m_MainCharacter->setScaleX(1.0f);

	}

	//m_MainCharacter = cocos2d::Sprite::create("Monster3.png");
}

void OOP::Player::attack()
{
	if (keyBoard.getXKey())
	{
		//spawn hitbox
		attCooldown = 1;
	}
}

bool OOP::Player::isattack()
{
	return attCooldown;
}

bool OOP::Player::getDir()
{
	return direction;
}
