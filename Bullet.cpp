#include "Bullet.h"

OOP::BulletManager::~BulletManager()
{
	for (int i = 0; i < m_BulletList.size(); i++) {
		delete m_BulletList[i];
	}
}

void OOP::BulletManager::spawnBullet(cocos2d::Vec2 a_Position, cocos2d::Vec2 a_Direcion)
{
	Bullet * l_Bullet = new Bullet(a_Position, a_Direcion, 30);
	m_Scene->addChild(l_Bullet->getBullet()->getBullet());
	//m_BulletList.push_back(l_Bullet);

	/*
	static int i = 0;
	if (i == 0) {
		//64 bottom of edge and 64 for half the emeny sprite size
		BasicMonster * l_Monster = new BasicMonster(cocos2d::Vec2(600.0f + 64, 64.0f + 64), 200, 0);
		l_Monster->saveScene(scene);
		l_Monster->savePlatforms(toSave);
		scene->addChild(l_Monster->m_Monster.getPrimitive());
		m_MonsterContainer.push_back(l_Monster);
		i++;
	}
	else {
		//64 bottom of edge and 64 for half the emeny sprite size
		ShootingMonster * l_Monster2 = new ShootingMonster(cocos2d::Vec2(0.0f + 64, 64.0f + 64), 30, 0);
		l_Monster2->saveScene(scene);
		scene->addChild(l_Monster2->m_Monster.getPrimitive());
		m_MonsterContainer.push_back(l_Monster2);
	}
	*/
}

void OOP::BulletManager::update(float timePeriod)
{
	for (unsigned int i = 0; i < m_BulletList.size(); i++)
	{
		delete m_BulletList[i];
	}
}

void OOP::BulletManager::newBullet(Bullet &n_Bullet)
{
	m_BulletList.push_back(&n_Bullet);
	//m_BulletList[(m_BulletList.size())]->saveScene(m_Scene);
}

OOP::BulletSprite::BulletSprite(const cocos2d::Vec2 & a_Position)
	:m_Node(cocos2d::Sprite::create("CloseNormal.png"))
{
	m_Node->setPosition(a_Position);
	//Wonderland->addChild(m_Node, 6);
}

OOP::BulletSprite::~BulletSprite()
{
	m_Node->release();
}

cocos2d::Sprite * OOP::BulletSprite::getBullet()
{
	return m_Node;
}

OOP::Bullet::Bullet(const cocos2d::Vec2 & a_StartPosition, cocos2d::Vec2 & a_Direction, float speed)
	:m_Bullet(a_StartPosition)
{
	m_Direction = a_Direction;
	m_Speed = speed;
	//m_Bullet.getBullet()->setPosition(0, 0);
	//m_Scene->addChild(m_Bullet.getBullet(), 10);
	double distanceToTarget = 0;
	double temp = (distanceToTarget*98.0f) / (speed * speed);
	double angle = 0;
	if (temp > 1)
	{
		angle = asin(1) / std::_Pi * 90;
	}
	else
	{
		angle = asin(temp) / std::_Pi * 90;
	}
	vel = m_Direction * m_Speed;
}

void OOP::Bullet::update(float timePeriod)
{
	cocos2d::Vec2 temp = m_Bullet.getBullet()->getPosition();
	m_Bullet.getBullet()->setPosition(temp + (m_Direction * m_Speed * timePeriod));
	vel = cocos2d::Vec2(vel.x, vel.y - 98.0 * timePeriod);
	m_Bullet.getBullet()->setPosition(temp + (vel * timePeriod));
}

OOP::BulletSprite * OOP::Bullet::getBullet()
{
	return (&m_Bullet);
}
