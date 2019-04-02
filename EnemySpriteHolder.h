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
		void const heavyMonsterAttackAnim(bool startEnd);
		void const shootingMonsterShoot(bool startEnd);
	private:
		cocos2d::Sprite *m_Node;
		cocos2d::CCSpriteFrameCache* frameCache;
		cocos2d::Vector<cocos2d::CCSpriteFrame *> testframes;
		cocos2d::CCAnimation* testAnim;
		cocos2d::CCAction *action;


	};
}







#endif // !H_HATE
