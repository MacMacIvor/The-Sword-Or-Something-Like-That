#include "Monster.h"

OOP::baseMonster::baseMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite)
	:m_Monster(a_Spawn, a_Sprite)
{
	swingCoolDown = 0;
	m_Spawn = a_Spawn;
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
	this->m_Monster.getPrimitive()->setPosition(m_Spawn);
}


OOP::MonsterManager::~MonsterManager()
{
	for (unsigned int w = 0; w < m_MonsterContainer.size(); w++) {
		delete m_MonsterContainer[w];
	}
}

void OOP::MonsterManager::spawn(cocos2d::Scene * scene, OOP::PlatformGenerator * toSave)
{
	static int i = 0;
	if (i == 0) {
		//64 bottom of edge and 64 for half the emeny sprite size
		BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2(600.0f + 64, 64.0f + 64), 200, 0);
		l_Monster->saveScene(scene);
		l_Monster->savePlatforms(toSave);
		scene->addChild(l_Monster->m_Monster.getPrimitive());
		m_MonsterContainer.push_back(l_Monster);
		//i++;
	}
	else {
		//64 bottom of edge and 64 for half the emeny sprite size
		//ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2(0.0f + 64, 64.0f + 64), 30, 0);
		//l_Monster2->saveScene(scene);
		//scene->addChild(l_Monster2->m_Monster.getPrimitive());
		//m_ShootingMonsterContainer.push_back(l_Monster2);
		ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2(300.0f + 64, 64.0f + 64), 200, 2);
		l_Monster2->saveScene(scene);
		l_Monster2->savePlatforms(toSave);
		scene->addChild(l_Monster2->m_Monster.getPrimitive(), 9);
		//m_MonsterContainer.push_back(l_Monster2);
		//m_ShootingMonsterContainer.push_back(l_Monster2);
	}
}

void const OOP::MonsterManager::monsterResest(cocos2d::Scene* scene, OOP::PlatformGenerator * toSave)
{
	for (unsigned int w = 0; w < m_MonsterContainer.size(); w++) {
		m_MonsterContainer[w]->reset();
	}
}

void OOP::MonsterManager::update(float a_DeltaTime)
{
	for (unsigned int w = 0; w < m_MonsterContainer.size(); w++) {
		m_MonsterContainer[w]->Update(a_DeltaTime);
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


OOP::BasicMonster::BasicMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite)
	:baseMonster(a_Spawn, a_Speed, a_Sprite) {}

void OOP::BasicMonster::Update(float a_DeltaTime)
{
	m_Monster.getPrimitive()->getPosition();
	//(*forCalculations).getClosestX(m_Monster.getPrimitive(), m_Speed);
	m_Monster.getPrimitive()->setPosition(
		m_Monster.getPrimitive()->getPositionX(),// + m_Speed * a_DeltaTime,
		m_Monster.getPrimitive()->getPositionY()
	);
	(*forCalculations).getClosestY(m_Monster.getPrimitive(), 0);
	if ((*forCalculations).getTypeHitBoxY() != 1) {
		m_Speed *= -1;
	}
	if (m_Monster.getPrimitive()->getBoundingBox().getMinX() + m_Speed * a_DeltaTime < 0) {
		m_Speed = m_Speed - m_Monster.getPrimitive()->getBoundingBox().getMinX() / a_DeltaTime;
	}
	if (m_Monster.getPrimitive()->getBoundingBox().getMinX() == 0) {
		m_Speed = -200;
	}
}

void OOP::BasicMonster::savePlatforms(OOP::PlatformGenerator * toSave)
{
	forCalculations = toSave;
}

OOP::ShootingMonster::ShootingMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite)
	:baseMonster(a_Spawn, a_Sprite, a_Speed)
{
}


bool OOP::ShootingMonster::attack(cocos2d::Sprite * character)
{
	if (shotCoolDown == 0) {
		//m_Bullets = new OOP::Bullet(m_Monster.getPrimitive()->getPosition(), cocos2d::Vec2(1.0f, 0.0f), m_Scene, 10.0f);
		//m_ManageBullets.newBullet((*m_Bullets));

	}
	return false;
}

void OOP::ShootingMonster::savePlatforms(OOP::PlatformGenerator * toSave)
{
	forCalculations = toSave;
}

void OOP::ShootingMonster::Update(float a_DeltaTime)
{
	m_Monster.getPrimitive()->getPosition();
	//(*forCalculations).getClosestX(m_Monster.getPrimitive(), m_Speed);
	m_Monster.getPrimitive()->setPosition(
		m_Monster.getPrimitive()->getPositionX(),// + m_Speed * a_DeltaTime,
		m_Monster.getPrimitive()->getPositionY()
	);
	(*forCalculations).getClosestY(m_Monster.getPrimitive(), 0);
	if ((*forCalculations).getTypeHitBoxY() != 1) {
		m_Speed *= -1;
	}
	if (m_Monster.getPrimitive()->getBoundingBox().getMinX() + m_Speed * a_DeltaTime < 0) {
		m_Speed = m_Speed - m_Monster.getPrimitive()->getBoundingBox().getMinX() / a_DeltaTime;
	}
	if (m_Monster.getPrimitive()->getBoundingBox().getMinX() == 0) {
		m_Speed = -200;
	}
}
