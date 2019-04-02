#ifndef CPP_MONSTER
#define CPP_MONSTER
#include "Monster.h"

OOP::baseMonster::baseMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite, const cocos2d::Vec2 a_Maxes)
	:m_Monster(a_Spawn, a_Sprite)
{
	swingCoolDown = 0;
	m_Spawn = a_Spawn;
	m_OG_Spawn = a_Spawn;
	m_Speed = a_Speed;
	spriteToUse = a_Sprite;
	m_MaxMovement = a_Maxes;
}

bool OOP::baseMonster::attack(cocos2d::Sprite * character)
{
	if (((character->getBoundingBox().getMaxX() < this->m_Monster.getPrimitive()->getBoundingBox().getMaxX() && 
		character->getBoundingBox().getMaxX() > this->m_Monster.getPrimitive()->getBoundingBox().getMinX()) ||
		(character->getBoundingBox().getMinX() < this->m_Monster.getPrimitive()->getBoundingBox().getMaxX() &&
			character->getBoundingBox().getMinX() > this->m_Monster.getPrimitive()->getBoundingBox().getMinX()))
		&&
		((character->getBoundingBox().getMinY() <= this->m_Monster.getPrimitive()->getBoundingBox().getMaxY() &&
			character->getBoundingBox().getMinY() >= this->m_Monster.getPrimitive()->getBoundingBox().getMinY()) ||
			(character->getBoundingBox().getMaxY() <= this->m_Monster.getPrimitive()->getBoundingBox().getMaxY() &&
				character->getBoundingBox().getMaxY() >= this->m_Monster.getPrimitive()->getBoundingBox().getMinY()))
		) {
		return true;
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

void OOP::baseMonster::takeDMG()
{
	HP--;
	this->m_Speed *= -1;
	I_frames = 50;
}
bool OOP::baseMonster::hashurt()
{
	return I_frames;
}

void OOP::baseMonster::reduceI()
{
	I_frames--;
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
	switch (level->getLevelNum()) {
	case 0:
		for (int i = 0; i < (sizeof levelOneHitBox / sizeof levelOneHitBox[0]); i++) { //rows
			for (int j = 0; j < (sizeof levelOneHitBox[0] / sizeof(int)); j++) { //collums
				if (levelOneHitBox[i][j] != -1) {
					if (levelOneHitBox[i][j] == 1) { //Light enemy
						BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -100, 0, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster->saveScene(scene);
						l_Monster->savePlatforms(toSave);
						scene->addChild(l_Monster->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster);
					}
					else if (levelOneHitBox[i][j] == 5) { //Shooting enemy
						//64 bottom of edge and 64 for half the emeny sprite size
						ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), 0, 1, cocos2d::Vec2(0, 0));
						l_Monster2->saveScene(scene);
						scene->addChild(l_Monster2->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster2);
					}
					else if (levelOneHitBox[i][j] == 8) { //Heavy enemy
						HeavyMonster * l_Monster3 = new HeavyMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -30, 2, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster3->saveScene(scene);
						l_Monster3->savePlatforms(toSave);
						scene->addChild(l_Monster3->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster3);
					}
					else if (levelOneHitBox[i][j] == 4) { //Falling skipes
						;
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
		break;
	case 1:
		for (int i = 0; i < (sizeof levelTwoHitBox / sizeof levelTwoHitBox[0]); i++) { //rows
			for (int j = 0; j < (sizeof levelTwoHitBox[0] / sizeof(int)); j++) { //collums
				if (levelTwoHitBox[i][j] != -1) {
					if (levelTwoHitBox[i][j] == 1) { //Light enemy
						BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -100, 0, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster->saveScene(scene);
						l_Monster->savePlatforms(toSave);
						scene->addChild(l_Monster->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster);
					}
					else if (levelTwoHitBox[i][j] == 5) { //Shooting enemy
						//64 bottom of edge and 64 for half the emeny sprite size
						ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), 0, 1, cocos2d::Vec2(0,0));
						l_Monster2->saveScene(scene);
						scene->addChild(l_Monster2->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster2);
					}
					else if (levelTwoHitBox[i][j] == 8) { //Heavy enemy
						HeavyMonster * l_Monster3 = new HeavyMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -30, 2, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster3->saveScene(scene);
						l_Monster3->savePlatforms(toSave);
						scene->addChild(l_Monster3->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster3);
					}
					else if (levelTwoHitBox[i][j] == 4) { //Falling skipes
						;
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
		break;
	case 2:
		for (int i = 0; i < (sizeof levelThreeHitBox / sizeof levelThreeHitBox[0]); i++) { //rows
			for (int j = 0; j < (sizeof levelThreeHitBox[0] / sizeof(int)); j++) { //collums
				if (levelThreeHitBox[i][j] != -1) {
					if (levelThreeHitBox[i][j] == 1) { //Light enemy
						BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -100, 0, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster->saveScene(scene);
						l_Monster->savePlatforms(toSave);
						scene->addChild(l_Monster->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster);
					}
					else if (levelThreeHitBox[i][j] == 5) { //Shooting enemy
						//64 bottom of edge and 64 for half the emeny sprite size
						ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), 0, 1, cocos2d::Vec2(0, 0));
						l_Monster2->saveScene(scene);
						scene->addChild(l_Monster2->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster2);
					}
					else if (levelThreeHitBox[i][j] == 8) { //Heavy enemy
						HeavyMonster * l_Monster3 = new HeavyMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -30, 2, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster3->saveScene(scene);
						l_Monster3->savePlatforms(toSave);
						scene->addChild(l_Monster3->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster3);
					}
					else if (levelThreeHitBox[i][j] == 4) { //Falling skipes
						;
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
		break;
	case 3:
		for (int i = 0; i < (sizeof levelFourHitBox / sizeof levelFourHitBox[0]); i++) { //rows
			for (int j = 0; j < (sizeof levelFourHitBox[0] / sizeof(int)); j++) { //collums
				if (levelFourHitBox[i][j] != -1) {
					if (levelFourHitBox[i][j] == 1) { //Light enemy
						BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -100, 0, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster->saveScene(scene);
						l_Monster->savePlatforms(toSave);
						scene->addChild(l_Monster->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster);
					}
					else if (levelFourHitBox[i][j] == 5) { //Shooting enemy
						//64 bottom of edge and 64 for half the emeny sprite size
						ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), 0, 1, cocos2d::Vec2(0, 0));
						l_Monster2->saveScene(scene);
						scene->addChild(l_Monster2->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster2);
					}
					else if (levelFourHitBox[i][j] == 8) { //Heavy enemy
						HeavyMonster * l_Monster3 = new HeavyMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -30, 2, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster3->saveScene(scene);
						l_Monster3->savePlatforms(toSave);
						scene->addChild(l_Monster3->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster3);
					}
					else if (levelFourHitBox[i][j] == 4) { //Falling skipes
						;
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
		break;
	case 4:
		for (int i = 0; i < (sizeof levelFiveHitBox / sizeof levelFiveHitBox[0]); i++) { //rows
			for (int j = 0; j < (sizeof levelFiveHitBox[0] / sizeof(int)); j++) { //collums
				if (levelFiveHitBox[i][j] != -1) {
					if (levelFiveHitBox[i][j] == 1) { //Light enemy
						BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -100, 0, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster->saveScene(scene);
						l_Monster->savePlatforms(toSave);
						scene->addChild(l_Monster->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster);
					}
					else if (levelFiveHitBox[i][j] == 5) { //Shooting enemy
						//64 bottom of edge and 64 for half the emeny sprite size
						ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), 0, 1, cocos2d::Vec2(0, 0));
						l_Monster2->saveScene(scene);
						scene->addChild(l_Monster2->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster2);
					}
					else if (levelFiveHitBox[i][j] == 8) { //Heavy enemy
						HeavyMonster * l_Monster3 = new HeavyMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -30, 2, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster3->saveScene(scene);
						l_Monster3->savePlatforms(toSave);
						scene->addChild(l_Monster3->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster3);
					}
					else if (levelFiveHitBox[i][j] == 4) { //Falling skipes
						;
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
		break;
	case 5:
		for (int i = 0; i < (sizeof levelSixHitBox / sizeof levelSixHitBox[0]); i++) { //rows
			for (int j = 0; j < (sizeof levelSixHitBox[0] / sizeof(int)); j++) { //collums
				if (levelSixHitBox[i][j] != -1) {
					if (levelSixHitBox[i][j] == 1) { //Light enemy
						BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -100, 0, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster->saveScene(scene);
						l_Monster->savePlatforms(toSave);
						scene->addChild(l_Monster->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster);
					}
					else if (levelSixHitBox[i][j] == 5) { //Shooting enemy
						//64 bottom of edge and 64 for half the emeny sprite size
						ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), 0, 1, cocos2d::Vec2(0, 0));
						l_Monster2->saveScene(scene);
						scene->addChild(l_Monster2->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster2);
					}
					else if (levelSixHitBox[i][j] == 8) { //Heavy enemy
						HeavyMonster * l_Monster3 = new HeavyMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -30, 2, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster3->saveScene(scene);
						l_Monster3->savePlatforms(toSave);
						scene->addChild(l_Monster3->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster3);
					}
					else if (levelSixHitBox[i][j] == 4) { //Falling skipes
						;
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
		break;
	case 6:
		for (int i = 0; i < (sizeof levelSevenHitBox / sizeof levelSevenHitBox[0]); i++) { //rows
			for (int j = 0; j < (sizeof levelSevenHitBox[0] / sizeof(int)); j++) { //collums
				if (levelSevenHitBox[i][j] != -1) {
					if (levelSevenHitBox[i][j] == 1) { //Light enemy
						BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -100, 0, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster->saveScene(scene);
						l_Monster->savePlatforms(toSave);
						scene->addChild(l_Monster->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster);
					}
					else if (levelSevenHitBox[i][j] == 5) { //Shooting enemy
						//64 bottom of edge and 64 for half the emeny sprite size
						ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), 0, 1, cocos2d::Vec2(0, 0));
						l_Monster2->saveScene(scene);
						scene->addChild(l_Monster2->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster2);
					}
					else if (levelSevenHitBox[i][j] == 8) { //Heavy enemy
						HeavyMonster * l_Monster3 = new HeavyMonster(cocos2d::Vec2((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64), -30, 2, toSave->getMonsterMaxMovement((128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 128));
						l_Monster3->saveScene(scene);
						l_Monster3->savePlatforms(toSave);
						scene->addChild(l_Monster3->m_Monster.getPrimitive());
						m_MonsterContainer.push_back(l_Monster3);
					}
					else if (levelSevenHitBox[i][j] == 4) { //Falling skipes
						;
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
		break;
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
		m_MonsterContainer[y]->m_Spawn.x += amountX;
		m_MonsterContainer[y]->m_Spawn.y += amountY; 
		m_MonsterContainer[y]->moveMaxes(amountX);
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
			if (m_MonsterContainer[y]->hashurt() == false)
			{

				m_MonsterContainer[y]->takeDMG();

			}

			//m_MonsterContainer[y]->m_MainCharacter.getBoundingBox().
			return true;
		}
	}
	return false;
}

OOP::BasicMonster::BasicMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite, const cocos2d::Vec2 a_Maxes)
	:baseMonster(a_Spawn, a_Speed, a_Sprite, a_Maxes) {}

void OOP::BasicMonster::move(float a_DeltaTime)
{
	//Monster needs to move based off of speed and time
	//Turns around if hits the edge of a platform or a wall
	
	if (m_Speed > 0) {
		if ((m_Monster.getPrimitive()->getBoundingBox().getMaxX() + m_Speed * a_DeltaTime) > m_MaxMovement.y - m_Monster.getPrimitive()->getBoundingBox().size.width / 2) {
			float tosee = m_Monster.getPrimitive()->getBoundingBox().getMaxX() + m_Speed * a_DeltaTime;
			m_Monster.getPrimitive()->setPositionX(m_MaxMovement.y - m_Monster.getPrimitive()->getBoundingBox().size.width);
			m_Speed *= -1;
		}
		else {
			m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
		}
	}


	else if (m_Speed < 0) {
		if ((m_Monster.getPrimitive()->getBoundingBox().getMinX() + m_Speed * a_DeltaTime) < m_MaxMovement.x - m_Monster.getPrimitive()->getBoundingBox().size.width / 2) {
			m_Monster.getPrimitive()->setPositionX(m_MaxMovement.x + m_MaxMovement.x - m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
			m_Speed *= -1;
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
	int hello = m_MainCharacter.getBoundingBox().getMidX() - this->m_Monster.getPrimitive()->getBoundingBox().getMidX();
	if (m_MainCharacter.getBoundingBox().getMidX() - this->m_Monster.getPrimitive()->getBoundingBox().getMidX() < 700 &&
		m_MainCharacter.getBoundingBox().getMidX() - this->m_Monster.getPrimitive()->getBoundingBox().getMidX() > -700 && isAttacking == false) {
		isAttacking = true;
		m_Speed *= 7;
	}
	else if (!(m_MainCharacter.getBoundingBox().getMidX() - this->m_Monster.getPrimitive()->getBoundingBox().getMidX() < 700 &&
		m_MainCharacter.getBoundingBox().getMidX() - this->m_Monster.getPrimitive()->getBoundingBox().getMidX() > -700) && isAttacking == true) {
		isAttacking = false;
		m_Speed /= 7;
	}
	else {
		this->move(a_DeltaTime);
	}
	if (hashurt())
	{
		reduceI();
	}
	if (m_Speed > 0)
	{
		m_Monster.getPrimitive()->setScaleX(1.0f);
	}
	else
	{
		m_Monster.getPrimitive()->setScaleX(-1.0f);

	}
}

void OOP::BasicMonster::savePlatforms(OOP::PlatformGenerator * toSave)
{
	forCalculations = toSave;
	m_MaxMovement = saveMax();
}

cocos2d::Vec2 OOP::BasicMonster::saveMax()
{
	return forCalculations->getMonsterMaxMovement(m_Spawn.x, m_Spawn.y - 64);

}

OOP::ShootingMonster::ShootingMonster(cocos2d::Vec2 a_Spawn, float a_Speed, int a_Sprite, const cocos2d::Vec2 a_Maxes)
	:baseMonster(a_Spawn, a_Speed, a_Sprite, a_Maxes) {}

bool OOP::ShootingMonster::attack(cocos2d::Sprite * character)
{
	if (shotCoolDown > 0) {
		shotCoolDown--;
	}
	else if (shotCoolDown == 0) {
		float distance = character->getBoundingBox().getMidX() - m_Monster.getPrimitive()->getBoundingBox().getMidX();
		if (distance < 0) {
			distance *= -1;
		}
		if (distance < 1000) {
			const int AMOUNTOFTIME = 200;
			static int timeOutForAnim = AMOUNTOFTIME;
			if (timeOutForAnim == AMOUNTOFTIME) {
				m_Monster.shootingMonsterShoot(true);
			}
			if (timeOutForAnim > 0) {
				timeOutForAnim--;
			}
			else {
				shotCoolDown = SHOOTCOOLDOWN_CONST;
				timeOutForAnim = AMOUNTOFTIME;
				m_Monster.shootingMonsterShoot(false);
				float l_TempX = character->getPosition().x - m_Spawn.x;
				float l_TempY = character->getPosition().y - m_Spawn.y;
				float angle = atan2(l_TempY, l_TempX);
				//float l_X = cos(angle);
				//float l_Y = sin(angle);

				double distanceToTarget = character->getPositionX() - m_Spawn.x;
				double temp = (distanceToTarget*98.0f) / (500.0f*500.0f);
				if (temp > 1)
				{
					angle = asin(1) / std::_Pi * 90;
				}
				else if (temp < -1)
				{
					angle = asin(-1) / std::_Pi * 90;
				}
				else
				{
					angle = asin(temp) / std::_Pi * 90;
				}
				//angle = asin(temp) / std::_Pi * 90;
				float vel_X = cos(angle * (std::_Pi / 180));
				float vel_Y = sin(angle * (std::_Pi / 180));

				//float angle = atan2(this->goalY - this->posY, this->goalX - this->posX);
				//this->speedX = cos(angle) * extraSpeed;
				//this->speedY = sin(angle) * extraSpeed;

				OOP::Bullet * m_Bullets2 = new OOP::Bullet(m_Monster.getPrimitive()->getPosition(), cocos2d::Vec2(vel_X, vel_Y), -500.0f);
				m_Scene->addChild(m_Bullets2->getBullet()->getBullet(), 1);
				m_Bullets.push_back(m_Bullets2);

				//m_Bullets->saveScene(m_Scene);
				//m_Bullets->newBullet(*m_Bullets2);
			}
		}
		//ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2(0.0f + 64, 64.0f + 64), 30, 0);
		//l_Monster2->saveScene(scene);
		//scene->addChild(l_Monster2->m_Monster.getPrimitive());
		//m_MonsterContainer.push_back(l_Monster2);
	}
	return false;
}

void OOP::ShootingMonster::savePlatforms(OOP::PlatformGenerator * toSave)
{
	forCalculations = toSave;

}

void OOP::ShootingMonster::Update(float a_DeltaTime) {
	int i = 0;

	while (i < m_Bullets.size()) {
		m_Bullets[i]->update(a_DeltaTime);
		i++;
	}
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

OOP::HeavyMonster::HeavyMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite, const cocos2d::Vec2 a_Maxes)
	:baseMonster(a_Spawn, a_Speed, a_Sprite, a_Maxes) {}


void OOP::HeavyMonster::move(float a_DeltaTime)
{
	if (m_Speed > 0) {
		if ((m_Monster.getPrimitive()->getBoundingBox().getMaxX() + m_Speed * a_DeltaTime) > m_MaxMovement.y - m_Monster.getPrimitive()->getBoundingBox().size.width / 2) {
			float tosee = m_Monster.getPrimitive()->getBoundingBox().getMaxX() + m_Speed * a_DeltaTime;
			m_Monster.getPrimitive()->setPositionX(m_MaxMovement.y - m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
			m_Speed *= -1;
			if (m_Speed < -30) {
				m_Speed = -30;
			}
		}
		else {
			m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
		}
	}


	else if (m_Speed < 0) {
		if ((m_Monster.getPrimitive()->getBoundingBox().getMinX() + m_Speed * a_DeltaTime) < m_MaxMovement.x + m_Monster.getPrimitive()->getBoundingBox().size.width / 2) {
			m_Monster.getPrimitive()->setPositionX(m_MaxMovement.x + m_Monster.getPrimitive()->getBoundingBox().size.width / 2);
			m_Speed *= -1;
			if (m_Speed > 30) {
				m_Speed = 30;
			}
		}
		else {
			m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
		}
	}
}

void OOP::HeavyMonster::Update(float a_DeltaTime)
{
	if (m_MainCharacter.getBoundingBox().getMidX() - this->m_Monster.getPrimitive()->getBoundingBox().getMidX() < 1000 &&
		m_MainCharacter.getBoundingBox().getMidX() - this->m_Monster.getPrimitive()->getBoundingBox().getMidX() > -1000 && isAttacking == 0) { //Detecting character
		int hello = m_MainCharacter.getBoundingBox().getMidX() - this->m_Monster.getPrimitive()->getBoundingBox().getMidX();
		isAttacking = 100;
		hello > 0 ? leftRight = true : leftRight = false;
		m_Monster.heavyMonsterAttackAnim(true);
	}
	else if (isAttacking <= 100 && isAttacking >= 70) { //PrePounce
		isAttacking--;
	}
	else if (isAttacking == 69) { //Thaidan if you see this don't even it was just a coincidence you immature fool
		//Pounce starts
		if (m_Speed < 30 && m_Speed > 0)
			m_Speed = 30;
		if (m_Speed < 0 && m_Speed > -30)
			m_Speed = -30;
		leftRight == true ? m_Speed *= -70 : m_Speed *= 70;
		isAttacking--;
	}
	else if (isAttacking >= 60 && isAttacking <= 68) { //Pounce
		this->move(a_DeltaTime);
		isAttacking--;
	}
	else if (isAttacking == 59) {
		leftRight == true ? m_Speed /= -70 : m_Speed /= 70;
		isAttacking--;
		m_Monster.heavyMonsterAttackAnim(false);
	}
	else if (isAttacking <= 60 && isAttacking >= 20) { //Cooldown
		isAttacking--;

	}
	else {
		if (m_Speed < 30 && m_Speed > 0)
			m_Speed = 30;
		if (m_Speed < 0 && m_Speed > -30)
			m_Speed = -30;
		this->move(a_DeltaTime);
		isAttacking = 0;
	}

	if (m_Speed > 0)
	{
		m_Monster.getPrimitive()->setScaleX(-1.0f);
	}
	else
	{
		m_Monster.getPrimitive()->setScaleX(1.0f);
	}
}

void OOP::HeavyMonster::savePlatforms(OOP::PlatformGenerator * toSave)
{
	forCalculations = toSave;
	m_MaxMovement = saveMax();
}

cocos2d::Vec2 OOP::HeavyMonster::saveMax()
{
	return forCalculations->getMonsterMaxMovement(m_Monster.getPrimitive()->getBoundingBox().getMidX(), m_Monster.getPrimitive()->getBoundingBox().getMinY());
}




#endif