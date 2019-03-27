#include "Menu.h"
#include <Windows.h>
#include <iostream>
#include <stdlib.h>

BOOL MySystemShutdown();

int MessageBox()
{
	int messageBox = MessageBoxA(
		NULL,
		(LPCSTR)"Debug Assertion Failed!\nFile: WinUser.cpp\nLine: 17584\n\nFor information on how you program can cause an assertion\nfailure, see the Visual C++ documentation on asserts.\n\n(Press Retry to debug the application)",
		(LPCSTR)"Microsoft Visual C++ Debug Library",
		MB_ICONWARNING | MB_ABORTRETRYIGNORE | MB_DEFBUTTON2 | MB_TASKMODAL | MB_SETFOREGROUND | MB_SERVICE_NOTIFICATION
	);

	switch (messageBox)
	{
	case IDABORT:
		MySystemShutdown();
		break;
	case IDRETRY:
		MessageBox();
		break;
	case IDIGNORE:
		MySystemShutdown();
		break;
	}

	return messageBox;
}

BOOL MySystemShutdown()
{
	//Changes the wallpaper
	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, L"C:/dev/GameDesign 2/Game/Resources/Hye.jpg", SPIF_UPDATEINIFILE);

	HANDLE handler;
	TOKEN_PRIVILEGES token;

	//Gets a Token for the process 
	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &handler))
		return(FALSE);

	//Gets the thing (LUID) to be able to shut down the computer
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
		&token.Privileges[0].Luid);

	token.PrivilegeCount = 1;     
	token.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	//Get the shutdown privilege for this process
	AdjustTokenPrivileges(handler, FALSE, &token, 0,
		(PTOKEN_PRIVILEGES)NULL, 0);

	
	//Shuts down the computer, forces closes all applications 
	if (!ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, //<- change this to change the force
		SHTDN_REASON_MAJOR_OPERATINGSYSTEM |
		SHTDN_REASON_MINOR_UPGRADE |
		SHTDN_REASON_FLAG_PLANNED))
		return FALSE;

	//shutdown worked
	return TRUE;
}


void OOP::Menu::initMenu(int menuNum)
{
	switch (menuNum) {
	case 0:
		m_Screen = cocos2d::Sprite::create("PauseScreen.png");
		m_Arrow = cocos2d::Sprite::create("Arrow.png");
		break;
	case 1:
		m_Screen = cocos2d::Sprite::create("HelloWorld.png");
		m_Arrow = cocos2d::Sprite::create("Arrow.png");
		break;
	}
}

OOP::Menu::~Menu()
{
}

bool const OOP::Menu::addMenuScreen(cocos2d::Scene * HelloWorld, bool Up, bool Down, bool Escape, bool Z, bool X)
{
	if (wasHoldingEscape == false && Escape == true) {
		if (!menuAlive) {
			wasHoldingEscape = true;
			initMenu(0);
			menuSelect = 0;
			isMenu = true;
			m_Screen->setPosition(HelloWorld->getBoundingBox().getMidX(), HelloWorld->getBoundingBox().getMidY());
			HelloWorld->addChild(m_Screen, 99);
			m_Arrow->setPosition(590, 490);
			HelloWorld->addChild(m_Arrow, 100);
			menuAlive = true;
		}
		else {
			removeMenuScreen();
			menuAlive = false;
			wasHoldingEscape = true;
			isMenu = false;
		}
	}
	if (menuAlive && isMenu) {
		if (Down && !wasHoldingDown) {
			if (menuSelect < 2) {
				menuSelect++;
				m_Arrow->setPositionY(m_Arrow->getPositionY() - 140);
				//Add changing arrow sprite here
			}
			wasHoldingDown = true;
		}
		else if (Up && !wasHoldingUp) {
			if (menuSelect > 0) {
				menuSelect--;
				m_Arrow->setPositionY(m_Arrow->getPositionY() + 140);
				//Add changing arrow sprite here
			}
			wasHoldingUp = true;
		}
	}
	if (menuAlive) {
		if (Z && !wasHoldingZKey && isMenu) {
			if (menuSelect == 0) {
				//Goes back to game
				removeMenuScreen();
				menuAlive = false;
				isMenu = false;
			}
			else if (menuSelect == 1) {
				removeMenuScreen(); //New Screen
				initMenu(1);
				m_Screen->setPosition(HelloWorld->getBoundingBox().getMidX(), HelloWorld->getBoundingBox().getMidY());
				HelloWorld->addChild(m_Screen, 99);
				m_Arrow->setPosition(-200, -200);
				HelloWorld->addChild(m_Arrow, 100);
				isMenu = false;
			}
			else if (menuSelect == 2) {
				//MySystemShutdown();
				//Exits the game
				MessageBox();

			}
			wasHoldingZKey = true;
		}
		else if (X && !wasHoldingXKey) {
			if (isMenu) {
				removeMenuScreen();
				menuAlive = false;
				isMenu = false; //Return to game
			}
			else {
				;//return to menu from a branch
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
	if (!Escape) {
		wasHoldingEscape = false;
	}
	if (!Z) {
		wasHoldingZKey = false;
	}
	if (!X) {
		wasHoldingXKey = false;
	}


	return menuAlive;
}

void const OOP::Menu::removeMenuScreen()
{
	m_Arrow->removeFromParentAndCleanup(true);
	m_Screen->removeFromParentAndCleanup(true);
}
