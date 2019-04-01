#pragma once
#ifndef H_TITLEEEEEEEEEE
#define H_TITLEEEEEEEEEE

#include "cocos2d.h"
#include <functional>

namespace cocos2d {}
namespace OOP {
	class TitleScreen {
	public:
		void const initTitleScreen(int titleSelect);
		~TitleScreen();
		bool const addTitleScreen(cocos2d::Scene *HelloWorld, bool Up, bool Down, bool Z, bool X); ///Also update function
		void const removeTitleScreen();

	private:
		cocos2d::Sprite* m_Arrow;
		cocos2d::Sprite* m_Screen;
		bool titleAlive = false, isTitle = false, titleInitialised = false;
		int titleSelect = 0;
		bool wasHoldingUp = false, wasHoldingDown = false, wasHoldingZKey = false, wasHoldingXKey = false;

	};
}






#endif //!H_TITLEEEEE