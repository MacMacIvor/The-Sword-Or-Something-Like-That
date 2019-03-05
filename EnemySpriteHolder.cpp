#include "EnemySpriteHolder.h"

OOP::MonsterSpriteHolder::MonsterSpriteHolder(const cocos2d::Vec2 &a_Position, int identifiyer)
{
	switch (identifiyer) {
	case 0:
		m_Node = cocos2d::Sprite::create("Monster1.png");
		m_Node->setPosition(a_Position);
		break;
	case 1:
		m_Node = cocos2d::Sprite::create("Monster2.png");
		m_Node->setPosition(a_Position);
		break;
	case 2:
		m_Node = cocos2d::Sprite::create("Monster3.png");
		m_Node->setPosition(a_Position);
		break;
	}
}

OOP::MonsterSpriteHolder::~MonsterSpriteHolder()
{
	m_Node->release();
}

cocos2d::Sprite * OOP::MonsterSpriteHolder::getPrimitive()
{
	return m_Node;
}
