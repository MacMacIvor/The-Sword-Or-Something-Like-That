#ifndef CPP_MONSTER
#define CPP_MONSTER
#include "Monster.h"

OOP::baseMonster::baseMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite)
	:m_Monster(a_Spawn, a_Sprite)
{
	swingCoolDown = 0;
	m_Spawn = a_Spawn;
	m_OG_Spawn = a_Spawn;
	m_Speed = a_Speed;
	spriteToUse = a_Sprite;
}

bool OOP::baseMonster::attack(cocos2d::Sprite * character)
{
	if (swingCoolDown == 0) {

		float temp = character->getBoundingBox().getMidX() - m_Monster.getPrimitive()->getBoundingBox().getMidX();
		if (temp < 0) {
			temp *= -1;
		}
		else {
			//swing->setPosition(m_Monster.getPrimitive()->getBoundingBox().getMidX() - m_Monster.getPrimitive()->getBoundingBox().size.width / 2 - swing->getBoundingBox().size.width, m_Monster.getPrimitive()->getBoundingBox().getMidY());
			//I HATE COCOS!!!!!!!
		}
		if (temp < 200) { //Less then the swing size
			swingCoolDown = 100;
		}
	}
	else if (swingCoolDown <= 70 && swingCoolDown >= 30) {
		//Swing
		float temp = character->getBoundingBox().getMidX() - m_Monster.getPrimitive()->getBoundingBox().getMidX();
		if (temp < 0) {
			temp *= -1;
		}
		if (temp < 200) {
			return true; //Used for damage truth
		}
		swingCoolDown--;
	}
	else if (swingCoolDown == 29) {

		swingCoolDown--;
	}
	else {
		swingCoolDown--;
	}
	return false;
}

void OOP::baseMonster::Update(float a_DeltaTime)
{
	cocos2d::Vec2 l_Tmp = m_Monster.getPrimitive()->getPosition();

	m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
	m_Monster.getPrimitive()->setPositionY(m_Monster.getPrimitive()->getPositionY() + m_Speed * a_DeltaTime);
}

void const OOP::baseMonster::reset()
{
	this->cleanBullets();
	this->m_Monster.getPrimitive()->removeFromParentAndCleanup(true);
}

void OOP::baseMonster::beHert(int dmg, bool isHit)
{
	if (isHit)
	{
		this->HP--;
	}
}

bool OOP::baseMonster::isDead()
{
	return (HP <= 0);
}

void OOP::baseMonster::setHP(int)
{
	HP = 0;
}




OOP::MonsterManager::~MonsterManager()
{
	for (unsigned int w = 0; w < m_MonsterContainer.size(); w++) {
		delete m_MonsterContainer[w];
	}
}

void OOP::MonsterManager::spawn(cocos2d::Scene * scene, OOP::PlatformGenerator * toSave, OOP::myLevels* level)
{
	m_Scene = scene;
	int number = 0;
	for (int i = 0; i < (sizeof levelOneHitBox / sizeof levelOneHitBox[0]); i++) { //rows
		for (int j = 0; j < (sizeof levelOneHitBox[0] / sizeof(int)); j++) { //collums
			if (levelOneHitBox[i][j] != -1) {
				if (levelOneHitBox[i][j] == 25)
				{
					if (number == 60 || number == 36) {
						;
					}
					else {
						;
					}
					
				}
				else {
					if (levelOneHitBox[i][j] == 0) { //Light enemy
						BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -20, 0);
						l_Monster->saveScene(scene);
						l_Monster->savePlatforms(toSave);
						scene->addChild(l_Monster->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster);
					}
					else if (levelOneHitBox[i][j] == 1) { //Shooting enemy
						//64 bottom of edge and 64 for half the emeny sprite size
						ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), 0, 1);
						l_Monster2->saveScene(scene);
						scene->addChild(l_Monster2->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster2);
					}
					else if (levelOneHitBox[i][j] == 2) { //Heavy enemy
						HeavyMonster * l_Monster3 = new HeavyMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -30, 2);
						l_Monster3->saveScene(scene);
						l_Monster3->savePlatforms(toSave);
						scene->addChild(l_Monster3->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster3);
					}
				}
				/*
				m_Platform[number]->setPosition(
					level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
						level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
				*/
				//help->addChild(m_Platform[number], 1);
				number++;
			}
		}
	}
}

void const OOP::MonsterManager::monsterResest(cocos2d::Scene* scene, OOP::PlatformGenerator * toSave)
{
	for (unsigned int w = 0; w < m_MonsterContainer.size(); w++) {
		m_MonsterContainer[w]->reset();
	}
	for (int i = m_MonsterContainer.size() - 1; i >= 0; i--) {
		m_MonsterContainer.erase((m_MonsterContainer.begin() + (i)));
	}
}

void OOP::MonsterManager::update(float a_DeltaTime)
{
	if (m_MonsterContainer.size() != 0) {
		for (unsigned int w = 0; w < m_MonsterContainer.size(); w++) {
			if (((m_MonsterContainer[w]->m_Monster.getPrimitive()->getBoundingBox().getMaxX() < m_Scene->getBoundingBox().getMaxX() &&
				m_MonsterContainer[w]->m_Monster.getPrimitive()->getBoundingBox().getMaxX() > m_Scene->getBoundingBox().getMinX()) || (
					m_MonsterContainer[w]->m_Monster.getPrimitive()->getBoundingBox().getMinX() < m_Scene->getBoundingBox().getMaxX() &&
					m_MonsterContainer[w]->m_Monster.getPrimitive()->getBoundingBox().getMinX() > m_Scene->getBoundingBox().getMinX())) &&
					(((m_MonsterContainer[w]->m_Monster.getPrimitive()->getBoundingBox().getMaxY() < m_Scene->getBoundingBox().getMaxY() &&
						m_MonsterContainer[w]->m_Monster.getPrimitive()->getBoundingBox().getMaxY() > m_Scene->getBoundingBox().getMinY()) || (
							m_MonsterContainer[w]->m_Monster.getPrimitive()->getBoundingBox().getMinY() < m_Scene->getBoundingBox().getMaxY() &&
							m_MonsterContainer[w]->m_Monster.getPrimitive()->getBoundingBox().getMinY() > m_Scene->getBoundingBox().getMinY())))) {

				m_MonsterContainer[w]->Update(a_DeltaTime);
				if (m_MonsterContainer[w]->isDead() == true) {
					m_MonsterContainer[w]->m_Monster.getPrimitive()->removeFromParentAndCleanup(true);
					m_MonsterContainer[w]->cleanBullets();
					m_MonsterContainer.erase(m_MonsterContainer.begin() + w);
					//delete m_MonsterContainer[w];

				}
				else {
					m_MonsterContainer[w]->attack(m_Character);

				}
			}
		}
	}
}

void OOP::MonsterManager::addMonster(BasicMonster & a_Monster)
{
	m_MonsterContainer.push_back(&a_Monster);
}

void OOP::MonsterManager::moveMonstersWithScreen(float amountX, float amountY)
{
	for (unsigned int y = 0; y < m_MonsterContainer.size(); y++) {
		m_MonsterContainer[y]->m_Monster.getPrimitive()->setPosition(
			m_MonsterContainer[y]->m_Monster.getPrimitive()->getPositionX() + amountX
			,
			m_MonsterContainer[y]->m_Monster.getPrimitive()->getPositionY() + amountY
		);
		m_MonsterContainer[y]->moveBullets(amountX, amountY);
		m_MonsterContainer[y]->m_Spawn.x + amountX;
		m_MonsterContainer[y]->m_Spawn.y + amountY;
	}
}

bool OOP::MonsterManager::damageLeft(cocos2d::Sprite * m_MainCharacter, int invincible)
{
	if (invincible = 0) {
		invincible--;
	}
	else {
		for (unsigned int y = 0; y < m_MonsterContainer.size(); y++) {
			//m_MonsterContainer[y]->m_Monster.getPrimitive()
			if (m_MainCharacter->getBoundingBox().getMaxX() <= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMaxX()
				&& m_MainCharacter->getBoundingBox().getMaxX() >= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMinX()
				&& (m_MainCharacter->getBoundingBox().getMaxY() <= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMaxY() &&
					m_MainCharacter->getBoundingBox().getMinY() >= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMinY())
				) {
				return true;
			}
		}
		
	}
	for (unsigned int y = 0; y < m_MonsterContainer.size(); y++) {
		if (true == m_MonsterContainer[y]->attack(m_MainCharacter) && invincible == 0) {
			return true;
		}
		if (true == m_MonsterContainer[y]->bulletDamage(m_MainCharacter) && invincible == 0) {
			return true;
		}
	}
	return false;
}

bool OOP::MonsterManager::damageRight(cocos2d::Sprite * m_MainCharacter, int invincible)
{
	if (invincible = 0) {
		invincible--;
	}
	else {
		for (unsigned int y = 0; y < m_MonsterContainer.size(); y++) {
			if (m_MainCharacter->getBoundingBox().getMinX() >= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMinX()
				&& m_MainCharacter->getBoundingBox().getMinX() <= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMaxX()
				&& (m_MainCharacter->getBoundingBox().getMaxY() <= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMaxY() &&
					m_MainCharacter->getBoundingBox().getMinY() >= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMinY())
				) {
				return true;
			}
		}
	}
	for (unsigned int y = 0; y < m_MonsterContainer.size(); y++) {
		if (true == m_MonsterContainer[y]->attack(m_MainCharacter) && invincible == 0) {
			return true;
		}
	}
	return false;
}

bool OOP::MonsterManager::isZipZilchZero()
{
	return (m_MonsterContainer.size() > 0);
}

bool OOP::MonsterManager::getHurt(cocos2d::Sprite * m_MainCharacter)
{
	for (unsigned int y = 0; y < m_MonsterContainer.size(); y++) {

		if (m_MainCharacter->getBoundingBox().getMaxX() >= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMinX()
			&& m_MainCharacter->getBoundingBox().getMinX() <= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMaxX()
			&& (m_MainCharacter->getBoundingBox().getMinY() <= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMaxY() &&
				m_MainCharacter->getBoundingBox().getMaxY() >= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMinY())
			) {
			m_MonsterContainer[y]->setHP(0);
			return true;
		}
	}
	return false;
}

OOP::BasicMonster::BasicMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite)
	:baseMonster(a_Spawn, a_Speed, a_Sprite) {}

void OOP::BasicMonster::move(float a_DeltaTime)
{
	//Monster needs to move based off of speed and time
	//Turns around if hits the edge of a platform or a wall
	int closestX = forCalculations->getClosestX(m_Monster.getPrimitive(), -m_Speed * a_DeltaTime);
	if (m_Speed > 0) {
		int closestY = forCalculations->getClosestY(m_Monster.getPrimitive()->getBoundingBox().getMidX(), m_Monster.getPrimitive()->getBoundingBox().getMinY(), 0);

		if ((m_Monster.getPrimitive()->getBoundingBox().getMaxX()) + m_Speed * a_DeltaTime >= forCalculations->getPlatform(closestX)->getBoundingBox().getMinX() && closestX != 0) {
			m_Monster.getPrimitive()->setPositionX(forCalculations->getPlatform(closestX)->getBoundingBox().getMinX() - m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
			m_Speed *= -1;
		}
		else if (m_Monster.getPrimitive()->getBoundingBox().getMaxX() + m_Speed * a_DeltaTime >= forCalculations->getPlatform(closestY)->getBoundingBox().getMaxX()){
			if (m_Monster.getPrimitive()->getBoundingBox().getMinY() != forCalculations->getPlatform(forCalculations->getClosestY(m_Monster.getPrimitive()->getBoundingBox().getMaxX(), m_Monster.getPrimitive()->getBoundingBox().getMinY(), 0))->getBoundingBox().getMaxY()) {
				m_Monster.getPrimitive()->setPositionX(forCalculations->getPlatform(closestY)->getBoundingBox().getMaxX() - m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
				m_Speed *= -1;
			}
			else {
				m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
			}
		}
		else {
			m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
		}
	}
	else if (m_Speed < 0) {
		int closestY = forCalculations->getClosestY(m_Monster.getPrimitive()->getBoundingBox().getMidX(), m_Monster.getPrimitive()->getBoundingBox().getMinY(), 0);

		if ((m_Monster.getPrimitive()->getBoundingBox().getMinX()) + m_Speed * a_DeltaTime <= forCalculations->getPlatform(closestX)->getBoundingBox().getMaxX() && closestX != 0) {
			m_Monster.getPrimitive()->setPositionX(forCalculations->getPlatform(closestX)->getBoundingBox().getMaxX() + m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
			m_Speed *= -1;
		}
		else if (m_Monster.getPrimitive()->getBoundingBox().getMinX() + m_Speed * a_DeltaTime <= forCalculations->getPlatform(closestY)->getBoundingBox().getMinX()) {
			if (m_Monster.getPrimitive()->getBoundingBox().getMinY() != forCalculations->getPlatform(forCalculations->getClosestY(m_Monster.getPrimitive()->getBoundingBox().getMinX(), m_Monster.getPrimitive()->getBoundingBox().getMinY(), 0))->getBoundingBox().getMaxY()) {
				m_Monster.getPrimitive()->setPositionX(forCalculations->getPlatform(closestY)->getBoundingBox().getMinX() + m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
				m_Speed *= -1;
			}
			else {
				m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
			}
		}
		else {
			m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
		}
	}
	//m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
}

void OOP::BasicMonster::Update(float a_DeltaTime)
{
	//m_Monster.getPrimitive()->getPosition();
	//(*forCalculations).getClosestX(m_Monster.getPrimitive(), m_Speed);
	
	//Add attack funtion here

	this->move(a_DeltaTime);
}

void OOP::BasicMonster::savePlatforms(OOP::PlatformGenerator * toSave)
{
	forCalculations = toSave;
}

OOP::ShootingMonster::ShootingMonster(cocos2d::Vec2 a_Spawn, float a_Speed, int a_Sprite)
	:baseMonster(a_Spawn, a_Speed, a_Sprite) {}

bool OOP::ShootingMonster::attack(cocos2d::Sprite * character)
{
	if (shotCoolDown == 0) {
		float distance = character->getBoundingBox().getMidX() - m_Monster.getPrimitive()->getBoundingBox().getMidX();
		if (distance < 0) {
			distance *= -1;
		}
		if (distance < 1000) {
			float l_TempX = character->getPosition().x - m_Spawn.x;
			float l_TempY = character->getPosition().y - m_Spawn.y;
			float angle = atan2(l_TempY, l_TempX);
			float l_X = cos(angle);
			float l_Y = sin(angle);

			//float angle = atan2(this->goalY - this->posY, this->goalX - this->posX);
			//this->speedX = cos(angle) * extraSpeed;
			//this->speedY = sin(angle) * extraSpeed;

			OOP::Bullet * m_Bullets2 = new OOP::Bullet(m_Monster.getPrimitive()->getPosition(), cocos2d::Vec2(l_X, l_Y), 200.0f);
			m_Scene->addChild(m_Bullets2->getBullet()->getBullet(), 1);
			m_Bullets.push_back(m_Bullets2);

			//m_Bullets->saveScene(m_Scene);
			//m_Bullets->newBullet(*m_Bullets2);

			shotCoolDown = 600;
		}
		//ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2(0.0f + 64, 64.0f + 64), 30, 0);
		//l_Monster2->saveScene(scene);
		//scene->addChild(l_Monster2->m_Monster.getPrimitive());
		//m_MonsterContainer.push_back(l_Monster2);
	}
	else {
		shotCoolDown--;
	}
	return false;
}

void OOP::ShootingMonster::savePlatforms(OOP::PlatformGenerator * toSave)
{
	forCalculations = toSave;
}

void OOP::ShootingMonster::Update(float a_DeltaTime) {
	int i = 0;
	//if (m_Bullets.size() != 0) {
		//for (int i = 0; i < m_Bullets.size(); i++) {
			//if (m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMidX() > m_Scene->getBoundingBox().getMaxX() ||
			//	m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMidX() > m_Scene->getBoundingBox().getMaxY() ||
			//	m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMidX() < m_Scene->getBoundingBox().getMinX() ||
			//	m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMidX() < m_Scene->getBoundingBox().getMinY()
			//	)
			//{
				//m_Bullets[i]->getBullet()->getBullet()->removeFromParentAndCleanup(true);
				//m_Bullets.erase(m_Bullets.begin() + i, m_Bullets.begin() + i);
				//delete m_Bullets[i];
			//}
		//}
		//for (int i = 0; i < m_Bullets.size() - 1; i++) {
		while (i < m_Bullets.size()) {
			m_Bullets[i]->update(a_DeltaTime);
			i++;
		}
		//}
		//}
		//m_Monster.getPrimitive()->getPosition();
		//(*forCalculations).getClosestX(m_Monster.getPrimitive(), m_Speed);
		//m_Monster.getPrimitive()->setPosition(
			//m_Monster.getPrimitive()->getPositionX(),// + m_Speed * a_DeltaTime,
			//m_Monster.getPrimitive()->getPositionY()
		//);
		//(*forCalculations).getClosestY(m_Monster.getPrimitive(), 0);
		//if ((*forCalculations).getTypeHitBoxY() != 1) {
			//m_Speed *= -1;
		//}
		//if (m_Monster.getPrimitive()->getBoundingBox().getMinX() + m_Speed * a_DeltaTime < 0) {
			//m_Speed = m_Speed - m_Monster.getPrimitive()->getBoundingBox().getMinX() / a_DeltaTime;
		//}
		//if (m_Monster.getPrimitive()->getBoundingBox().getMinX() == 0) {
			//m_Speed = -200;
		//}
	//}
	//else {
	//	;
	//}
}

void OOP::ShootingMonster::moveBullets(float X, float Y)
{
	for (int i = 0; i < m_Bullets.size(); i++) {
		m_Bullets[i]->getBullet()->getBullet()->setPosition(
			m_Bullets[i]->getBullet()->getBullet()->getPositionX() + X,
			m_Bullets[i]->getBullet()->getBullet()->getPositionY() + Y
		);
	}
}

void OOP::ShootingMonster::cleanBullets()
{
	for (int i = m_Bullets.size() - 1; i > -1; i--) {
		m_Bullets[i]->getBullet()->getBullet()->removeFromParentAndCleanup(true);
		m_Bullets.erase(m_Bullets.begin() + i);
	}
}

bool OOP::ShootingMonster::bulletDamage(cocos2d::Sprite * character)
{
	for (int i = 0; i < m_Bullets.size(); i++) {
		if (((m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMaxX() > character->getBoundingBox().getMinX() &&
			m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMaxX() < character->getBoundingBox().getMaxX()) && //Right of bullet within the player
			((m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMinY() > character->getBoundingBox().getMinY() &&
				m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMinY() < character->getBoundingBox().getMaxY()) ||
				(m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMaxY() > character->getBoundingBox().getMinY() &&
					m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMaxY() < character->getBoundingBox().getMaxY())) ||
			(((m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMinX() > m_MainCharacter.getBoundingBox().getMinX() &&
				m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMinX() < m_MainCharacter.getBoundingBox().getMaxX()) && //Left of bullet within the player
				(m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMinY() > m_MainCharacter.getBoundingBox().getMinY() &&
					(m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMinY() < m_MainCharacter.getBoundingBox().getMaxY()) ||
					(m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMaxY() > m_MainCharacter.getBoundingBox().getMinY() &&
						m_Bullets[i]->getBullet()->getBullet()->getBoundingBox().getMaxY() < m_MainCharacter.getBoundingBox().getMaxY()))))) == true) {
			//m_Bullets[i]->getBullet()->~BulletSprite();
			m_Bullets[i]->getBullet()->getBullet()->removeFromParentAndCleanup(true);
			m_Bullets.erase(m_Bullets.begin() + i);
			return true;
		}

	}
	return false;
}
#endif

OOP::HeavyMonster::HeavyMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite)
	:baseMonster(a_Spawn, a_Speed, a_Sprite) {}


void OOP::HeavyMonster::move(float a_DeltaTime)
{
	int closestX = forCalculations->getClosestX(m_Monster.getPrimitive(), -m_Speed * a_DeltaTime);
	if (m_Speed > 0) {
		int closestY = forCalculations->getClosestY(m_Monster.getPrimitive()->getBoundingBox().getMidX(), m_Monster.getPrimitive()->getBoundingBox().getMinY(), 0);

		if ((m_Monster.getPrimitive()->getBoundingBox().getMaxX()) + m_Speed * a_DeltaTime >= forCalculations->getPlatform(closestX)->getBoundingBox().getMinX() && closestX != 0) {
			m_Monster.getPrimitive()->setPositionX(forCalculations->getPlatform(closestX)->getBoundingBox().getMinX() - m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
			m_Speed *= -1;
		}
		else if (m_Monster.getPrimitive()->getBoundingBox().getMaxX() + m_Speed * a_DeltaTime >= forCalculations->getPlatform(closestY)->getBoundingBox().getMaxX()) {
			if (m_Monster.getPrimitive()->getBoundingBox().getMinY() != forCalculations->getPlatform(forCalculations->getClosestY(m_Monster.getPrimitive()->getBoundingBox().getMaxX(), m_Monster.getPrimitive()->getBoundingBox().getMinY(), 0))->getBoundingBox().getMaxY()) {
				m_Monster.getPrimitive()->setPositionX(forCalculations->getPlatform(closestY)->getBoundingBox().getMaxX() - m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
				m_Speed *= -1;
			}
			else {
				m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
			}
		}
		else {
			m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
		}
	}
	else if (m_Speed < 0) {
		int closestY = forCalculations->getClosestY(m_Monster.getPrimitive()->getBoundingBox().getMidX(), m_Monster.getPrimitive()->getBoundingBox().getMinY(), 0);

		if ((m_Monster.getPrimitive()->getBoundingBox().getMinX()) + m_Speed * a_DeltaTime <= forCalculations->getPlatform(closestX)->getBoundingBox().getMaxX() && closestX != 0) {
			m_Monster.getPrimitive()->setPositionX(forCalculations->getPlatform(closestX)->getBoundingBox().getMaxX() + m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
			m_Speed *= -1;
		}
		else if (m_Monster.getPrimitive()->getBoundingBox().getMinX() + m_Speed * a_DeltaTime <= forCalculations->getPlatform(closestY)->getBoundingBox().getMinX()) {
			if (m_Monster.getPrimitive()->getBoundingBox().getMinY() != forCalculations->getPlatform(forCalculations->getClosestY(m_Monster.getPrimitive()->getBoundingBox().getMinX(), m_Monster.getPrimitive()->getBoundingBox().getMinY(), 0))->getBoundingBox().getMaxY()) {
				m_Monster.getPrimitive()->setPositionX(forCalculations->getPlatform(closestY)->getBoundingBox().getMinX() + m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
				m_Speed *= -1;
			}
			else {
				m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
			}
		}
		else {
			m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
		}
	}
}

void OOP::HeavyMonster::Update(float a_DeltaTime)
{
	this->move(a_DeltaTime);
}

void OOP::HeavyMonster::savePlatforms(OOP::PlatformGenerator * toSave)
{
	forCalculations = toSave;
}
