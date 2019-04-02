#ifndef CPP_PLATFORM
#define CPP_PLATFORM

#include "PlatformGenerator.h"
#include <string>

OOP::PlatformGenerator::PlatformGenerator()
	:index(0) {}

cocos2d::Sprite * OOP::PlatformGenerator::getPlatform(int reference)
{
	return m_Platform[reference];
}

cocos2d::Vec2 const OOP::PlatformGenerator::generateNew(cocos2d::Scene *help, OOP::myLevels* level)
{
	number = 0;
	cocos2d::Vec2 mainCharacterSpawn;
	switch (level->getLevelNum()) {
	case 0:
		for (int i = 0; i < (sizeof levelOneHitBox / sizeof levelOneHitBox[level->getLevelNum()]); i++) { //collums
			for (int j = 0; j < (sizeof levelOneHitBox[level->getLevelNum()] / sizeof(int)); j++) { //rows
				/*
				1 is regular enemy, 2 is the coffin platforms (so you can jump through the bottom and land on top, they're not in this one)
				3 is ground, 4 is falling spikes, 5 is shooty boy, 6 is spikes on the ground, 7 is death pit (only in the  mountain level), 8 is heavy enemy
				0 is nothing and -1 is nothing
				99 next level

				*/
				if (levelOneHitBox[i][j] != -1) {
					if (levelOneHitBox[i][j] == 2) {
						types.push_back(2);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelOneHitBox[i][j] == 3)
					{
						types.push_back(3);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelOneHitBox[i][j] == 6) {
						types.push_back(6);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelOneHitBox[i][j] == 10) {
						types.push_back(99);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelOneHitBox[i][j] == 9) {
						mainCharacterSpawn = cocos2d::Vec2(level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64);
					}
					else if (levelOneHitBox[i][j] == 1 || levelOneHitBox[i][j] == 5 || levelOneHitBox[i][j] == 8 || levelOneHitBox[i][j] == 4) {
						;
					}
					else {
						types.push_back(7);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));
						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}

				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < (sizeof levelTwoHitBox / sizeof levelTwoHitBox[level->getLevelNum()]); i++) { //collums
			for (int j = 0; j < (sizeof levelTwoHitBox[level->getLevelNum()] / sizeof(int)); j++) { //rows
				/*
				1 is regular enemy, 2 is the coffin platforms (so you can jump through the bottom and land on top, they're not in this one)
				3 is ground, 4 is falling spikes, 5 is shooty boy, 6 is spikes on the ground, 7 is death pit (only in the  mountain level), 8 is heavy enemy
				0 is nothing and -1 is nothing
				99 next level

				*/
				if (levelTwoHitBox[i][j] != -1) {
					if (levelTwoHitBox[i][j] == 2) {
						types.push_back(2);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelTwoHitBox[i][j] == 3)
					{
						types.push_back(3);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelTwoHitBox[i][j] == 6) {
						types.push_back(6);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelTwoHitBox[i][j] == 10) {
						types.push_back(99);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelTwoHitBox[i][j] == 9) {
						mainCharacterSpawn = cocos2d::Vec2(level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64);
					}
					else if (levelTwoHitBox[i][j] == 1 || levelTwoHitBox[i][j] == 5 || levelTwoHitBox[i][j] == 8 || levelTwoHitBox[i][j] == 4) {
						;
					}
					else {
						types.push_back(7);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));
						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}

				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < (sizeof levelThreeHitBox / sizeof levelThreeHitBox[level->getLevelNum()]); i++) { //collums
			for (int j = 0; j < (sizeof levelThreeHitBox[level->getLevelNum()] / sizeof(int)); j++) { //rows
				/*
				1 is regular enemy, 2 is the coffin platforms (so you can jump through the bottom and land on top, they're not in this one)
				3 is ground, 4 is falling spikes, 5 is shooty boy, 6 is spikes on the ground, 7 is death pit (only in the  mountain level), 8 is heavy enemy
				0 is nothing and -1 is nothing
				99 next level

				*/
				if (levelThreeHitBox[i][j] != -1) {
					if (levelThreeHitBox[i][j] == 2) {
						types.push_back(2);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelThreeHitBox[i][j] == 3)
					{
						types.push_back(3);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelThreeHitBox[i][j] == 6) {
						types.push_back(6);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelThreeHitBox[i][j] == 10) {
						types.push_back(99);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelThreeHitBox[i][j] == 9) {
						mainCharacterSpawn = cocos2d::Vec2(level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64);
					}
					else if (levelThreeHitBox[i][j] == 1 || levelThreeHitBox[i][j] == 5 || levelThreeHitBox[i][j] == 8 || levelThreeHitBox[i][j] == 4) {
						;
					}
					else {
						types.push_back(7);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));
						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}

				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < (sizeof levelFourHitBox / sizeof levelFourHitBox[level->getLevelNum()]); i++) { //collums
			for (int j = 0; j < (sizeof levelFourHitBox[level->getLevelNum()] / sizeof(int)); j++) { //rows
				/*
				1 is regular enemy, 2 is the coffin platforms (so you can jump through the bottom and land on top, they're not in this one)
				3 is ground, 4 is falling spikes, 5 is shooty boy, 6 is spikes on the ground, 7 is death pit (only in the  mountain level), 8 is heavy enemy
				0 is nothing and -1 is nothing
				99 next level

				*/
				if (levelFourHitBox[i][j] != -1) {
					if (levelFourHitBox[i][j] == 2) {
						types.push_back(2);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelFourHitBox[i][j] == 3)
					{
						types.push_back(3);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelFourHitBox[i][j] == 6) {
						types.push_back(6);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelFourHitBox[i][j] == 10) {
						types.push_back(99);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelFourHitBox[i][j] == 9) {
						mainCharacterSpawn = cocos2d::Vec2(level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64);
					}
					else if (levelFourHitBox[i][j] == 1 || levelFourHitBox[i][j] == 5 || levelFourHitBox[i][j] == 8 || levelFourHitBox[i][j] == 4) {
						;
					}
					else {
						types.push_back(7);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));
						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}

				}
			}
		}
		break;
	case 4:
		for (int i = 0; i < (sizeof levelFiveHitBox / sizeof levelFiveHitBox[level->getLevelNum()]); i++) { //collums
			for (int j = 0; j < (sizeof levelFiveHitBox[level->getLevelNum()] / sizeof(int)); j++) { //rows
				/*
				1 is regular enemy, 2 is the coffin platforms (so you can jump through the bottom and land on top, they're not in this one)
				3 is ground, 4 is falling spikes, 5 is shooty boy, 6 is spikes on the ground, 7 is death pit (only in the  mountain level), 8 is heavy enemy
				0 is nothing and -1 is nothing
				99 next level

				*/
				if (levelFiveHitBox[i][j] != -1) {
					if (levelFiveHitBox[i][j] == 2) {
						types.push_back(2);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelFiveHitBox[i][j] == 3)
					{
						types.push_back(3);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelFiveHitBox[i][j] == 6) {
						types.push_back(6);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelFiveHitBox[i][j] == 10) {
						types.push_back(99);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelFiveHitBox[i][j] == 9) {
						mainCharacterSpawn = cocos2d::Vec2(level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64);
					}
					else if (levelFiveHitBox[i][j] == 1 || levelFiveHitBox[i][j] == 5 || levelFiveHitBox[i][j] == 8 || levelFiveHitBox[i][j] == 4) {
						;
					}
					else {
						types.push_back(7);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));
						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}

				}
			}
		}
		break;
	case 5:
		for (int i = 0; i < (sizeof levelSixHitBox / sizeof levelSixHitBox[level->getLevelNum()]); i++) { //collums
			for (int j = 0; j < (sizeof levelSixHitBox[level->getLevelNum()] / sizeof(int)); j++) { //rows
				/*
				1 is regular enemy, 2 is the coffin platforms (so you can jump through the bottom and land on top, they're not in this one)
				3 is ground, 4 is falling spikes, 5 is shooty boy, 6 is spikes on the ground, 7 is death pit (only in the  mountain level), 8 is heavy enemy
				0 is nothing and -1 is nothing
				99 next level

				*/
				if (levelSixHitBox[i][j] != -1) {
					if (levelSixHitBox[i][j] == 2) {
						types.push_back(2);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelSixHitBox[i][j] == 3)
					{
						types.push_back(3);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelSixHitBox[i][j] == 6) {
						types.push_back(6);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelSixHitBox[i][j] == 10) {
						types.push_back(99);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelSixHitBox[i][j] == 9) {
						mainCharacterSpawn = cocos2d::Vec2(level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64);
					}
					else if (levelSixHitBox[i][j] == 1 || levelSixHitBox[i][j] == 5 || levelSixHitBox[i][j] == 8 || levelSixHitBox[i][j] == 4) {
						;
					}
					else {
						types.push_back(7);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));
						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}

				}
			}
		}
		break;
	case 6:
		for (int i = 0; i < (sizeof levelSevenHitBox / sizeof levelSevenHitBox[level->getLevelNum()]); i++) { //collums
			for (int j = 0; j < (sizeof levelSevenHitBox[level->getLevelNum()] / sizeof(int)); j++) { //rows
				/*
				1 is regular enemy, 2 is the coffin platforms (so you can jump through the bottom and land on top, they're not in this one)
				3 is ground, 4 is falling spikes, 5 is shooty boy, 6 is spikes on the ground, 7 is death pit (only in the  mountain level), 8 is heavy enemy
				0 is nothing and -1 is nothing
				99 next level

				*/
				if (levelSevenHitBox[i][j] != -1) {
					if (levelSevenHitBox[i][j] == 2) {
						types.push_back(2);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelSevenHitBox[i][j] == 3)
					{
						types.push_back(3);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelSevenHitBox[i][j] == 6) {
						types.push_back(6);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelSevenHitBox[i][j] == 10) {
						types.push_back(99);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));

						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}
					else if (levelSevenHitBox[i][j] == 9) {
						mainCharacterSpawn = cocos2d::Vec2(level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64, level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64);
					}
					else if (levelSevenHitBox[i][j] == 1 || levelSevenHitBox[i][j] == 5 || levelSevenHitBox[i][j] == 8 || levelSevenHitBox[i][j] == 4) {
						;
					}
					else {
						types.push_back(7);
						m_Platform.push_back(cocos2d::Sprite::create("testforms.png"));
						m_Platform[number]->setPosition(
							level->getLevel()->getBoundingBox().getMinX() + (128 * j) + 64,
							level->getLevel()->getBoundingBox().getMaxY() - (128 * i) - 64
						);

						help->addChild(m_Platform[number], 1);
						number++;
					}

				}
			}
		}
		break;
	}
	vectorSize = m_Platform.size();
	return mainCharacterSpawn;
}

cocos2d::Vec2 OOP::PlatformGenerator::getMonsterMaxMovement(float positionX, float positionY) //Returns a cocos Vec2 with the first value representing
//The minimum positionX monsters may move to and the seccond
//Being the masimum positionX

{
	//Needs to get the closest walls (left and right)
	//Then compare to the closest pits

	int tempClosestWallRight = 0; //Right for to the right of the monsters
	int groundExtentionRight = 0;
	int bufferRight = 0;
	int tempClosestWallLeft = 0; //Left for to the Left of the monsters
	int groundExtentionLeft = m_Platform.size() - 1;
	int bufferLeft = 0;


	for (int i = 0, w = m_Platform.size() - 1; i < m_Platform.size(); i++, w--) {


		if (!((m_Platform[tempClosestWallRight]->getBoundingBox().getMaxY() > positionY + 10 && m_Platform[tempClosestWallRight]->getBoundingBox().getMinY() < positionY + 10) && 
			m_Platform[tempClosestWallRight]->getBoundingBox().getMidX() > positionX
			))
			tempClosestWallRight = i;

		if (bufferRight == 0) {
			if (m_Platform[i]->getBoundingBox().getMaxY() == positionY && 
				(positionX > m_Platform[i]->getBoundingBox().getMinX() &&
				positionX < m_Platform[i]->getBoundingBox().getMaxX())) {
				groundExtentionRight = i;
				bufferRight++;
			}
		}
		else if (bufferRight == 1) {
			if ((m_Platform[i]->getBoundingBox().getMaxY() == positionY) && (m_Platform[i]->getBoundingBox().getMidX() == (m_Platform[groundExtentionRight]->getBoundingBox().getMidX() + 128))) {
				groundExtentionRight = i;
			}
		}

		//Closest Wall Left
		if (!((m_Platform[tempClosestWallLeft]->getBoundingBox().getMaxY() > positionY + 10 && m_Platform[tempClosestWallLeft]->getBoundingBox().getMinY() < positionY + 10) &&
			m_Platform[tempClosestWallLeft]->getBoundingBox().getMidX() < positionX
			))
			tempClosestWallLeft = w;

		if (bufferLeft == 0) {
			if (m_Platform[w]->getBoundingBox().getMaxY() == positionY &&
				(positionX > m_Platform[w]->getBoundingBox().getMinX() &&
					positionX < m_Platform[w]->getBoundingBox().getMaxX())) {
				groundExtentionLeft = w;
				bufferLeft++;
			}
		}
		else if (bufferLeft == 1) {
			if (m_Platform[w]->getBoundingBox().getMaxY() == positionY && m_Platform[w]->getBoundingBox().getMidX() == (m_Platform[groundExtentionLeft]->getBoundingBox().getMidX() - 128)) {
				groundExtentionLeft = w;
			}
		}
	}
	
	cocos2d::Vec2 minX_maxX;
	if (tempClosestWallLeft == 0) {
		tempClosestWallLeft = groundExtentionLeft;
	}
	else if (groundExtentionLeft == 0) {
		groundExtentionLeft = tempClosestWallLeft;
	}
	if (groundExtentionRight == 0) {
		groundExtentionRight = tempClosestWallLeft;
	}
	else if (tempClosestWallRight == 0) {
		tempClosestWallRight = groundExtentionRight;
	}
	float hi = m_Platform[tempClosestWallLeft]->getBoundingBox().getMidX();
	float hi2 = m_Platform[groundExtentionLeft]->getBoundingBox().getMidX();
	float hi3 = m_Platform[tempClosestWallRight]->getBoundingBox().getMidX();
	float hi4 = m_Platform[groundExtentionRight]->getBoundingBox().getMidX();

	if (numberForMonsters == 35) {
		numberForMonsters++;
	}
	numberForMonsters++;
	
	minX_maxX.x = (m_Platform[tempClosestWallLeft]->getBoundingBox().getMidX() > m_Platform[groundExtentionLeft]->getBoundingBox().getMidX() ?
		m_Platform[tempClosestWallLeft]->getBoundingBox().getMidX() : m_Platform[groundExtentionLeft]->getBoundingBox().getMidX());

	minX_maxX.y = (m_Platform[tempClosestWallRight]->getBoundingBox().getMidX() < m_Platform[groundExtentionRight]->getBoundingBox().getMidX() ?
		m_Platform[tempClosestWallRight]->getBoundingBox().getMidX() : m_Platform[groundExtentionRight]->getBoundingBox().getMidX());

	return minX_maxX;
}

void const OOP::PlatformGenerator::moveHitBoxesX(float X)
{
	for (int i = 0; i < m_Platform.size(); i++) {
		m_Platform[i]->setPosition(
			m_Platform[i]->getPositionX() + X,
			m_Platform[i]->getPositionY()
			);
	}
}

void const OOP::PlatformGenerator::moveHitBoxesY(float Y)
{
	for (int i = 0; i < m_Platform.size(); i++) {
		m_Platform[i]->setPosition(
			m_Platform[i]->getPositionX(),
			m_Platform[i]->getPositionY() + Y
		);
	}
}

int const OOP::PlatformGenerator::getTypeHitBoxX() const
{
	return typeHitBoxX;
}

int const OOP::PlatformGenerator::getTypeHitBoxY() const
{
	return typeHitBoxY;
}

cocos2d::Vec2 const OOP::PlatformGenerator::resetHitBox(cocos2d::Scene *help, OOP::myLevels* level)
{
	for (int i = m_Platform.size() - 1; i >= 0; i--) {
		m_Platform[i]->removeFromParentAndCleanup(true);
	}
	for (int i = m_Platform.size() - 1; i >= 0; i--) {
		m_Platform.erase((m_Platform.begin() + (i)));
	}
	int hello = m_Platform.size();
	int testing = 0;

	return OOP::PlatformGenerator::generateNew(help, level);
}

int OOP::PlatformGenerator::getPlayerTypeOfHitBox(int index)
{
	int wut = types[index];
	return types[index];
}

#endif







/*
float OOP::PlatformGenerator::getPositionX(cocos2d::Sprite * platform)
{
	std::vector<cocos2d::Sprite *>::iterator necessaryStep = std::find(m_Platform.begin(), m_Platform.end(), platform);
	int position = std::distance(m_Platform.begin(), necessaryStep);
	return positionX[position];
}
float OOP::PlatformGenerator::getPositionY(cocos2d::Sprite * platform)
{
	std::vector<cocos2d::Sprite *>::iterator necessaryStep = std::find(m_Platform.begin(), m_Platform.end(), platform);
	int position = std::distance(m_Platform.begin(), necessaryStep);
	return positionY[position];
}
*/