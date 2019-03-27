#pragma once
#ifndef H_HATE
#define H_HATE

#include <functional>
#include "cocos2d.h"

namespace cocos2d {

}


namespace OOP {
	class MonsterSpriteHolder {
	public:
		MonsterSpriteHolder(const cocos2d::Vec2 &a_Position, int identifiyer);
		~MonsterSpriteHolder();
		cocos2d::Sprite *getPrimitive();
	private:
		cocos2d::Sprite *m_Node;
	};
}







#endif // !H_HATE
