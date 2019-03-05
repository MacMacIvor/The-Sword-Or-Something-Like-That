#include "Monster.h"

OOP::baseMonster::baseMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite)
	:m_Monster(a_Spawn, a_Sprite)
{
	m_Speed = a_Speed;
	spriteToUse = a_Sprite;
}

void OOP::baseMonster::Update(float a_DeltaTime)
{
	cocos2d::Vec2 l_Tmp = m_Monster.getPrimitive()->getPosition();

	m_Monster.getPrimitive()->setPositionX(m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime);
	m_Monster.getPrimitive()->setPositionY(m_Monster.getPrimitive()->getPositionY() + m_Speed * a_DeltaTime);
}

OOP::MonsterManager::~MonsterManager()
{
	for (unsigned int w = 0; w < m_MonsterContainer.size(); w++) {
		delete m_MonsterContainer[w];
	}
}

void OOP::MonsterManager::spawn(cocos2d::Scene * scene, OOP::PlatformGenerator * toSave)
{
	//64 bottom of edge and 64 for half the emeny sprite size
	BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2(64.0f + 64, 64.0f + 64), 200, 2);
	l_Monster->saveScene(scene);
	l_Monster->savePlatforms(toSave);
	scene->addChild(l_Monster->m_Monster.getPrimitive());
	m_MonsterContainer.push_back(l_Monster);
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
				&& m_MainCharacter->getBoundingBox().getMaxX() >= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMinX()) {
				return true;
			}
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
				&& m_MainCharacter->getBoundingBox().getMinX() <= m_MonsterContainer[y]->m_Monster.getPrimitive()->getBoundingBox().getMaxX()) {
				return true;
			}
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
		m_Monster.getPrimitive()->getPositionX() + m_Speed * a_DeltaTime,
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
