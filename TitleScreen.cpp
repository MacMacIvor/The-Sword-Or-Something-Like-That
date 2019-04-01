#include "TitleScreen.h"

void const OOP::TitleScreen::initTitleScreen(int titleSelect)
{
	switch (titleSelect) {
	case 0:
		m_Screen = cocos2d::Sprite::create("title.png");
		m_Arrow = cocos2d::Sprite::create("Arrow.png");
		break;
	case 1:
		m_Screen = cocos2d::Sprite::create("HelloWorld2.png");
		m_Arrow = cocos2d::Sprite::create("Arrow.png");
		break;
	}
}
OOP::TitleScreen::~TitleScreen()
{
}
bool const OOP::TitleScreen::addTitleScreen(cocos2d::Scene * HelloWorld, bool Up, bool Down, bool Z, bool X)
{
	if (!titleInitialised) {
		initTitleScreen(0);
		titleInitialised = true;
		titleSelect = 0;
		isTitle = true;
		m_Screen->setPosition(HelloWorld->getBoundingBox().getMidX(), HelloWorld->getBoundingBox().getMidY());
		HelloWorld->addChild(m_Screen, 99);
		m_Arrow->setPosition(750, 440);
		HelloWorld->addChild(m_Arrow, 100);
		titleAlive = true;
	}
	//else {
		//removeTitleScreen();
		//titleAlive = false;
		//wasHoldingEscape = true;
		//isTitle = false;
	//}
	if (titleAlive && isTitle) {
		if (Down && !wasHoldingDown) {
			if (titleSelect < 2) {
				titleSelect++;
				m_Arrow->setPositionY(m_Arrow->getPositionY() - 95);
			}
			wasHoldingDown = true;
		}
		else if (Up && !wasHoldingUp) {
			if (titleSelect > 0) {
				titleSelect--;
				m_Arrow->setPositionY(m_Arrow->getPositionY() + 95);
			}
			wasHoldingUp = true;
		}
	}
	if (titleAlive) {
		if (Z && !wasHoldingZKey && isTitle) {
			if (titleSelect == 0) {
				//Goes to to game
				removeTitleScreen();
				titleAlive = false;
				isTitle = false;
			}
			else if (titleSelect == 1) {
				removeTitleScreen(); //New Screen
				initTitleScreen(1);
				m_Screen->setPosition(HelloWorld->getBoundingBox().getMidX(), HelloWorld->getBoundingBox().getMidY());
				HelloWorld->addChild(m_Screen, 99);
				m_Arrow->setPosition(-200, -200);
				HelloWorld->addChild(m_Arrow, 100);
				isTitle = false;
			}
			else if (titleSelect == 2) {
				//MySystemShutdown();
				//Exits the game

				exit(1);
				//MessageBox();

			}
			wasHoldingZKey = true;
		}
		else if (X && !wasHoldingXKey) {
			if (isTitle) {
				//removeTitleScreen();
				//titleAlive = false;
				//isTitle = false; //Return to game
				;
			}
			else {
				removeTitleScreen(); //New Screen
				initTitleScreen(0);
				m_Screen->setPosition(HelloWorld->getBoundingBox().getMidX(), HelloWorld->getBoundingBox().getMidY());
				HelloWorld->addChild(m_Screen, 99);
				m_Arrow->setPosition(750, 440);
				HelloWorld->addChild(m_Arrow, 100);
				isTitle = true;;//return to title from a branch
				titleSelect = 0;
			}
			wasHoldingXKey = true;
		}
	}
	if (!Up) {
		wasHoldingUp = false;
	}
	if (!Down) {
		wasHoldingDown = false;
	}
	if (!Z) {
		wasHoldingZKey = false;
	}
	if (!X) {
		wasHoldingXKey = false;
	}


	return titleAlive;
}

void const OOP::TitleScreen::removeTitleScreen()
{
	m_Arrow->removeFromParentAndCleanup(true);
	m_Screen->removeFromParentAndCleanup(true);
}