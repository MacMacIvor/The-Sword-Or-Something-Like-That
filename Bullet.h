#ifndef H_BULLET
#define H_BULLET

#include "cocos2d.h"
#include <functional>
#include <vector>

namespace cocos2d {

};

namespace OOP {
	class BulletSprite {
	public:
		BulletSprite(const cocos2d::Vec2 &a_Position);
		~BulletSprite();
		cocos2d::Sprite *getBullet();
	private:
		cocos2d::Sprite *m_Node;
	};
	class Bullet {
	public:
		Bullet(const cocos2d::Vec2 &a_StartPosition, cocos2d::Vec2 &Direction, float speed);
		virtual void update(float timePeriod);
		void saveScene(cocos2d::Scene * newScene) { m_Scene = newScene; }
		cocos2d::Scene *m_Scene;
		OOP::BulletSprite *getBullet();
	private:
		BulletSprite m_Bullet;
		cocos2d::Vec2 m_Direction;
		float m_Speed = 0.0f;
	};
	class BulletManager {
	public:
		void saveScene(cocos2d::Scene * newScene) { m_Scene = newScene; }
		~BulletManager();
		void spawnBullet(cocos2d::Vec2 a_Position, cocos2d::Vec2 a_Direcion);
		void update(float timePeriod);
		void newBullet(Bullet &n_Bullet);
		cocos2d::Scene *m_Scene;

	private:
		std::vector <Bullet *> m_BulletList;

	};
}







#endif //!H_BULLET