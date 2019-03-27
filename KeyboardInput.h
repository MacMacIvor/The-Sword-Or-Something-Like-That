#ifndef H_KEYBOARD
#define H_KEYBOARD
#include <functional>
#include <iostream>
#include "cocos2d.h"

namespace cocos2d //Namespace
{
	class Event;
	class EventListenerKeyboard;
	class Node;
}


namespace OOP //Our namespace
{
	class KeyboardListener
	{
	public:
		//Constructor is called when an object of type MouseListener is called
		KeyboardListener();
		//Destructor is called when an object of type MouseListener is destroyed
		~KeyboardListener();

		void OnKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *a_Event); //Gets called when the mouse button is released
		void OnKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *a_Event); //Gets called when the mouse button is pressed


		bool const getLeftArrow() const;
		bool const getRightArrow() const;
		bool const getUpArrow() const;
		bool const getDownArrow() const;
		bool const getShiftKey() const;
		bool const getZKey() const;
		bool const getXKey() const;
		bool const getEscapeKey() const;

		cocos2d::EventListenerKeyboard *getListener(); //Returns the listener that holds the event


	private:
		cocos2d::EventListenerKeyboard *m_Listener; //The listener that saves the event
		bool upArrow = false;
		bool leftArrow = false;
		bool rightArrow = false;
		bool downArrow = false;
		bool shiftKey = false;
		bool zKey = false;
		bool xKey = false;
		bool escapeKey = false;
	};
}

#endif //!H_KEYBOARD