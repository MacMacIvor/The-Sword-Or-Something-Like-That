#ifndef H_BULLET
#define H_BULLET

#include "cocos2d.h"
#include <functional>

namespace cocos2d {

};

namespace OOP {
	class BulletSprite {
	public:
		BulletSprite(const cocos2d::Vec2 &a_Position, cocos2d::Scene *Wonderland);
		~BulletSprite();
		cocos2d::Sprite *getBullet();
	private:
		cocos2d::Sprite *m_Node;
	};
	class Bullet {
	public:
		Bullet(const cocos2d::Vec2 &a_StartPosition, cocos2d::Vec2 &Direction, cocos2d::Scene *Wonderland, float speed);
		virtual void update(float timePeriod);
	private:
		BulletSprite m_Bullet;
		cocos2d::Vec2 m_Direction;
		float m_Speed = 0.0f;
	};
	class BulletManager {
	public:
		~BulletManager();
		void update(float timePeriod);
		void newBullet(Bullet &n_Bullet);
	private:
		std::vector <Bullet *> m_BulletList;
	};
}







#endif //!H_BULLET