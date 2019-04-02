#include "EnemySpriteHolder.h"

OOP::MonsterSpriteHolder::MonsterSpriteHolder(const cocos2d::Vec2 &a_Position, int identifiyer)
{
	switch (identifiyer) {
	case 0:
		m_Node = cocos2d::Sprite::create("Monster1.png");
		frameCache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
		frameCache->addSpriteFramesWithFile("BasicEnemy.plist");
		//CCArray* testFrames = new CCArray;
		for (int i = 1; i <= 8; i++)
		{
			cocos2d::CCString* filename = cocos2d::CCString::createWithFormat("b%d.png", i);
			cocos2d::CCSpriteFrame* frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
			testframes.pushBack(frame);
		}
		 
		testAnim = cocos2d::CCAnimation::createWithSpriteFrames(testframes, 0.1f);
		action = cocos2d::CCRepeatForever::create(cocos2d::CCAnimate::create(testAnim));
		//m_Node = cocos2d::Sprite::create("Monster1.png");
		//m_Node->stopAllActions();
		m_Node->runAction(action);
		m_Node->setPosition(a_Position);
		m_Node->setScaleX(-1.0f);
		break;
	case 1:
		m_Node = cocos2d::Sprite::create("s2.png");
		frameCache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
		frameCache->addSpriteFramesWithFile("ShootingEnemy.plist");
		//CCArray* testFrames = new CCArray;
		for (int i = 1, w = 1; i <= 12; w <= i ? w++ : i++)
		{
			cocos2d::CCString* filename = cocos2d::CCString::createWithFormat("s%d.png", i);
			cocos2d::CCSpriteFrame* frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
			testframes.pushBack(frame);
		}

		testAnim = cocos2d::CCAnimation::createWithSpriteFrames(testframes, 0.1f);
		action = cocos2d::CCRepeatForever::create(cocos2d::CCAnimate::create(testAnim));
		//m_Node = cocos2d::Sprite::create("Monster1.png");
		//m_Node->stopAllActions();
		m_Node->setPosition(a_Position);
		m_Node->setScaleX(-1.0f);
		break;
	case 2:
		m_Node = cocos2d::Sprite::create("Monster1.png");
		frameCache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
		frameCache->addSpriteFramesWithFile("HeavyEnemy.plist");
		//CCArray* testFrames = new CCArray;
		for (int i = 1, w = 1; i <= 12; w <= i ? w++ : i++)
		{
			cocos2d::CCString* filename = cocos2d::CCString::createWithFormat("h%d.png", i);
			
			
			cocos2d::CCSpriteFrame* frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
			testframes.pushBack(frame);
		}

		testAnim = cocos2d::CCAnimation::createWithSpriteFrames(testframes, 0.1f);
		action = cocos2d::CCRepeatForever::create(cocos2d::CCAnimate::create(testAnim));
		//m_Node = cocos2d::Sprite::create("Monster1.png");
		//m_Node->stopAllActions();
		m_Node->runAction(action);
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

void const OOP::MonsterSpriteHolder::heavyMonsterAttackAnim(bool startEnd)
{
	if (startEnd == true) {
		m_Node->stopAllActions();
		int temp = testframes.size();
		

		cocos2d::CCSpriteFrameCache* frameCache2 = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
		frameCache2->addSpriteFramesWithFile("HeavyEnemyAt.plist");

		for (int i = 12; i > 0; i--)
		{
			cocos2d::CCString* filename = cocos2d::CCString::createWithFormat("j%d.png", i);


			cocos2d::CCSpriteFrame* frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
			testframes.insert(0, frame);
		}
		for (int i = 0; i < temp; i++)
			testframes.popBack();

		cocos2d::CCAnimation *newtestAnim = cocos2d::CCAnimation::createWithSpriteFrames(testframes, 0.1f);
		cocos2d::CCAction *action2 = cocos2d::CCRepeatForever::create(cocos2d::CCAnimate::create(newtestAnim));
		
		//frameCache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
		//frameCache->addSpriteFramesWithFile("HeavyEnemyAt.plist");
		//CCArray* testFrames = new CCArray;
		

		//m_Node = cocos2d::Sprite::create("Monster1.png");
		//m_Node->stopAllActions();
		m_Node->runAction(action2);
	}
	else {
		m_Node->stopAllActions();
		int temp = testframes.size();


		cocos2d::CCSpriteFrameCache* frameCache2 = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
		frameCache2->addSpriteFramesWithFile("HeavyEnemy.plist");

		for (int i = 12; i > 0; i--)
		{
			cocos2d::CCString* filename = cocos2d::CCString::createWithFormat("h%d.png", i);


			cocos2d::CCSpriteFrame* frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
			testframes.insert(0, frame);
		}
		for (int i = 0; i < temp; i++)
			testframes.popBack();

		cocos2d::CCAnimation *newtestAnim = cocos2d::CCAnimation::createWithSpriteFrames(testframes, 0.1f);
		cocos2d::CCAction *action2 = cocos2d::CCRepeatForever::create(cocos2d::CCAnimate::create(newtestAnim));

		//frameCache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
		//frameCache->addSpriteFramesWithFile("HeavyEnemyAt.plist");
		//CCArray* testFrames = new CCArray;


		//m_Node = cocos2d::Sprite::create("Monster1.png");
		//m_Node->stopAllActions();
		m_Node->runAction(action2);
	}
}

void const OOP::MonsterSpriteHolder::shootingMonsterShoot(bool startEnd)
{
	if (startEnd == true) {
		m_Node->stopAllActions();
		int temp = testframes.size();


		cocos2d::CCSpriteFrameCache* frameCache2 = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
		frameCache2->addSpriteFramesWithFile("ShootingEnemy.plist");

		for (int i = 12; i > 0; i--)
		{
			cocos2d::CCString* filename = cocos2d::CCString::createWithFormat("s%d.png", i);


			cocos2d::CCSpriteFrame* frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
			testframes.insert(0, frame);
		}
		for (int i = 0; i < temp; i++)
			testframes.popBack();

		cocos2d::CCAnimation *newtestAnim = cocos2d::CCAnimation::createWithSpriteFrames(testframes, 0.1f);
		cocos2d::CCAction *action2 = cocos2d::CCRepeatForever::create(cocos2d::CCAnimate::create(newtestAnim));

		//frameCache = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache();
		//frameCache->addSpriteFramesWithFile("HeavyEnemyAt.plist");
		//CCArray* testFrames = new CCArray;


		//m_Node = cocos2d::Sprite::create("Monster1.png");
		//m_Node->stopAllActions();
		m_Node->runAction(action2);
	}
	else {
		m_Node->stopAllActions();
	}
}
