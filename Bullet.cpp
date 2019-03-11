#include "Bullet.h"

OOP::BulletManager::~BulletManager()
{
	for (int i = 0; i < m_BulletList.size(); i++) {
		delete m_BulletList[i];
	}
}

void OOP::BulletManager::update(float timePeriod)
{
	for (unsigned int i = 0; i < m_BulletList.size(); i++)
	{
		delete m_BulletList[i];
	}
}

void OOP::BulletManager::newBullet(Bullet & n_Bullet)
{
	m_BulletList.push_back(&n_Bullet);
}

OOP::BulletSprite::BulletSprite(const cocos2d::Vec2 & a_Position, cocos2d::Scene *Wonderland)
	:m_Node(cocos2d::Sprite::create())
{
	m_Node->setPosition(a_Position);
	Wonderland->addChild(m_Node, 6);
}

OOP::BulletSprite::~BulletSprite()
{
	m_Node->release();
}

cocos2d::Sprite * OOP::BulletSprite::getBullet()
{
	return m_Node;
}

OOP::Bullet::Bullet(const cocos2d::Vec2 & a_StartPosition, cocos2d::Vec2 & a_Direction, cocos2d::Scene *Wonderland, float speed)
	:m_Bullet(a_StartPosition, Wonderland)
{
	m_Direction = a_Direction;
	m_Speed = speed;
}

void OOP::Bullet::update(float timePeriod)
{
	cocos2d::Vec2 temp = m_Bullet.getBullet()->getPosition();
	m_Bullet.getBullet()->setPosition(temp + (m_Direction * m_Speed * timePeriod));
}
