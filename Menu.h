#pragma once
#ifndef H_MENUUUUUUUUU
#define H_MENUUUUUUUUU
#include "cocos2d.h"
#include <functional>


namespace cocos2d {};

namespace OOP {

	class Menu {
	public:
		void initMenu(int menuNum);
		~Menu();
		bool const addMenuScreen(cocos2d::Scene *HelloWorld, bool Up, bool Down, bool Escape, bool Z, bool X); ///Also update function
		void const removeMenuScreen();

	private:
		cocos2d::Sprite* m_Arrow;
		cocos2d::Sprite* m_Screen;
		bool menuAlive = false, isMenu = false;
		int menuSelect = 0;
		bool wasHoldingUp = false, wasHoldingDown = false, wasHoldingEscape = false, wasHoldingZKey = false, wasHoldingXKey = false;

	};

}


#endif // !H_MENUUUUUUUUU