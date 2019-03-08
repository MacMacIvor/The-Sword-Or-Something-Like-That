/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <string>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	cocos2d::Scene *scene = Scene::create();
	HelloWorld *layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to KILL YOURSELF, then initialize your instance
bool HelloWorld::init()
{
	if (!Scene::init()) {
		return false;
	}


	m_Level.initLevel(this);
	m_Platform.generateNew(this, &m_Level);


	m_mainCharacter.getMainCharacter()->setPosition(100,200);
	std::string s = "a1.png";
	m_mainCharacter.getMainCharacter()->setTexture(s);
	this->addChild(m_mainCharacter.getMainCharacter(), 0);
	//this be thing


	//code for animation
	CCSpriteFrameCache* frameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	frameCache->addSpriteFramesWithFile("B.plist");

	CCSpriteBatchNode* spriteSheet = CCSpriteBatchNode::create("Monster1.png");
	this->addChild(spriteSheet);

	Vector<CCSpriteFrame *> testframes;
	//CCArray* testFrames = new CCArray;
	for (int i = 1; i <= 3; i++)
	{
		CCString* filename = CCString::createWithFormat("a%d.png", i);
		CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(filename->getCString());
		//testFrames->addObject(frame);
		testframes.pushBack(frame);
	}

	CCAnimation* testAnim = CCAnimation::createWithSpriteFrames(testframes, 0.1f);
	//CCSprite* test = CCSprite::createWithSpriteFrameName("a1.png");
	//test->setPosition(Vec2(400, 200));

	CCAction* action = CCRepeatForever::create(CCAnimate::create(testAnim));
	m_mainCharacter.runAnimation(action);

	//test->runAction(action);
	//spriteSheet->addChild(test);
	//m_mainCharacter.getMainCharacter()->runAction(action);



	m_mainCharacter.getTheLastAmountOfPatienceIHaveWithCocos()->setPosition(-100, -100);
	this->addChild(m_mainCharacter.getTheLastAmountOfPatienceIHaveWithCocos(), 3);

	this->scheduleUpdate();

	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(m_mainCharacter.getListener(), this);
	
	
	m_mainCharacter.saveScene(this);
	//m_mainCharacter.updateHealthSprite();
	m_mainCharacter.initHealth();

	auto label = Label::createWithTTF("This is what a killer's Smile looks like!\n"
										"               Fear it!", "fonts/Marker Felt.ttf", 24);
	    if (label == nullptr)
	    {
	        problemLoading("'fonts/Marker Felt.ttf'");
	    }
	   else
	    {
	// position the label
	        label->setPosition(Vec2(200, 250));

		//	 add the label as a child to this layer
		    this->addChild(label, 1);
		}

		m_MonsterManager.spawn(this, &m_Platform);


    return true;
}




void HelloWorld::update(float justSomeRandomThingBecauseCososNeedsAFloatVariableHereToRecogniseTheUpdateFunction) {
	static int taunt = 0;
	
	

	if (m_mainCharacter.getHealth() > 0 && taunt == 0) {

		cocos2d::Vec2 position = m_mainCharacter.getMainCharacter()->getPosition();

		
		m_Platform.getClosestY(m_mainCharacter.getMainCharacter(), m_mainCharacter.getVelocityY());
		m_Platform.getClosestX(m_mainCharacter.getMainCharacter(), m_mainCharacter.getVelocityX());

		m_mainCharacter.updateVelocities(m_mainCharacter.getMainCharacter(),
			m_Platform.getPlatform(m_Platform.getClosestY(m_mainCharacter.getMainCharacter(), m_mainCharacter.getVelocityY())),
			m_Platform.getPlatform(m_Platform.getClosestX(m_mainCharacter.getMainCharacter(), m_mainCharacter.getVelocityX())), m_Platform.getTypeHitBoxX(), m_Platform.getTypeHitBoxY());

		position.x -= m_mainCharacter.getVelocityX();
		position.y += m_mainCharacter.getVelocityY();




		if (position.x < 100 - (m_mainCharacter.getMainCharacter()->getBoundingBox().size.width / 2)) {
			if (m_Level.checkMaxX(m_mainCharacter.getVelocityX(), this) != true) {
				m_Level.moveBackGroundX(m_mainCharacter.getVelocityX(), this);
				m_Platform.moveHitBoxesX(m_Level.getMovedAmountX());
				m_MonsterManager.moveMonstersWithScreen(m_Level.getMovedAmountX(), 0);
				position.x = 100 - (m_mainCharacter.getMainCharacter()->getBoundingBox().size.width / 2);
			}
			position.x = 100 - (m_mainCharacter.getMainCharacter()->getBoundingBox().size.width / 2);

		}

		else if (position.x > this->getBoundingBox().getMaxX() - (50 + m_mainCharacter.getMainCharacter()->getBoundingBox().size.width / 2)) {
			if (m_Level.checkMaxX(m_mainCharacter.getVelocityX(), this) == false) {
				m_Level.moveBackGroundX(m_mainCharacter.getVelocityX(), this);
				m_Platform.moveHitBoxesX(m_Level.getMovedAmountX());
				m_MonsterManager.moveMonstersWithScreen(m_Level.getMovedAmountX(), 0);
			}
			position.x = this->getBoundingBox().getMaxX() - (50 + m_mainCharacter.getMainCharacter()->getBoundingBox().size.width / 2);
		}

		if (position.y > this->getBoundingBox().getMaxY() - 100) {
			if (m_Level.checkMaxY(m_mainCharacter.getVelocityY(), this) == false) {
				m_Level.moveBackGroundY(m_mainCharacter.getVelocityY(), this);
				m_Platform.moveHitBoxesY(m_Level.getMovedAmountY());
				position.y = this->getBoundingBox().getMaxY() - 100;
				m_MonsterManager.moveMonstersWithScreen(0, m_Level.getMovedAmountY());

			}
			position.y = this->getBoundingBox().getMaxY() - 100;

		}
		else if (position.y < 100) {
			if (m_Level.checkMaxY(m_mainCharacter.getVelocityY(), this) == false) {
				m_Level.moveBackGroundY(m_mainCharacter.getVelocityY(), this);
				m_Platform.moveHitBoxesY(m_Level.getMovedAmountY());
				m_MonsterManager.moveMonstersWithScreen(0, m_Level.getMovedAmountY());
				position.y = 100;
			}
			else {
				if (m_mainCharacter.getMainCharacter()->getBoundingBox().getMinX() < 0) {
					position.y = 0 + m_mainCharacter.getMainCharacter()->getBoundingBox().size.height / 2;
				}
			}
		}
		m_mainCharacter.getMainCharacter()->setPosition(position);
		m_mainCharacter.updateHealthSprite();

		m_MonsterManager.update(justSomeRandomThingBecauseCososNeedsAFloatVariableHereToRecogniseTheUpdateFunction);
		m_mainCharacter.damage(m_mainCharacter.getMainCharacter(), m_MonsterManager.damageLeft(m_mainCharacter.getMainCharacter(), m_mainCharacter.getInvincible()), m_MonsterManager.damageRight(m_mainCharacter.getMainCharacter(), m_mainCharacter.getInvincible()));
		
	}
	else if (m_mainCharacter.getHealth() <= 0 && taunt != 100) {
		if (taunt == 0) {
			m_mainCharacter.getTheLastAmountOfPatienceIHaveWithCocos()->setPosition(m_mainCharacter.getMainCharacter()->getBoundingBox().getMidX(), m_mainCharacter.getMainCharacter()->getBoundingBox().getMidY());
		}
		taunt++;
	}
	else {
		m_mainCharacter.getTheLastAmountOfPatienceIHaveWithCocos()->setPosition(-100, -100);
		taunt = 0;
		m_mainCharacter.resetPlayer();
		m_Level.resetLevel(this);
		m_Platform.resetHitBox(this, &m_Level);
		m_mainCharacter.saveScene(this);
	}

}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
