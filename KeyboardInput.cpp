#include "KeyboardInput.h"


OOP::KeyboardListener::KeyboardListener()
{
	auto listenerTemp = cocos2d::EventListenerKeyboard::create();
	//listener->onKeyPressed = std::bind(&OOP::KeyboardListener::OnKeyPressed, this, std::placeholders::_1);
	listenerTemp->onKeyPressed = CC_CALLBACK_2(KeyboardListener::OnKeyPressed, this);
	listenerTemp->onKeyReleased = CC_CALLBACK_2(KeyboardListener::OnKeyReleased, this);
	m_Listener = listenerTemp;

}

OOP::KeyboardListener::~KeyboardListener()
{
}

void OOP::KeyboardListener::OnKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * a_Event)
{
	switch (keyCode) {
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		leftArrow = false;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		rightArrow = false;
		break;
	}
	switch (keyCode) {
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		upArrow = false;
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_Z) {
		zKey = false;
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_X) {
		xKey = false;
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SHIFT) {
		shiftKey = false;
	}
}

void OOP::KeyboardListener::OnKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * a_Event)
{
	switch (keyCode) {
	case cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		leftArrow = true;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		rightArrow = true;
		break;
	}
	switch (keyCode) {
	case cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW:
		upArrow = true;
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_Z) {
		zKey = true;
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_X) {
		xKey = true;
	}
	if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SHIFT) {
		shiftKey = true;
	}
	log("Key with keycode %d pressed", keyCode);
}

bool const OOP::KeyboardListener::getLeftArrow() const
{
	return leftArrow;
}
	  
bool const OOP::KeyboardListener::getRightArrow() const
{
	return rightArrow;
}
	  
bool const OOP::KeyboardListener::getUpArrow() const
{
	return upArrow;
}
	  
bool const OOP::KeyboardListener::getShiftKey() const
{
	return shiftKey;
}
	  
bool const OOP::KeyboardListener::getZKey() const 
{
	return zKey;
}
bool const OOP::KeyboardListener::getXKey() const
{
	return xKey;
}


cocos2d::EventListenerKeyboard * OOP::KeyboardListener::getListener()
{
	return m_Listener;
}



