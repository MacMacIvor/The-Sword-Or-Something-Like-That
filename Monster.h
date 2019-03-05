#ifndef H_MONSTER
#define H_MONSTER

#include <functional>
#include "cocos2d.h"
#include "EnemySpriteHolder.h"
#include "PlatformGenerator.h"

namespace cocos2d {
	class Event;
	class EventListenerMouse;
	class Label;
}
class HelloWorld;

namespace OOP {
	class baseMonster {
	public:
		baseMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite);

		virtual void Update(float a_DeltaTime);
		
		void saveScene(cocos2d::Scene *scene) { m_Scene = scene; };

		//I HAAAAAAATTTTTTEEEEE CCCCOOOOOOCCCCCOOOOSSSS!!!!
		OOP::MonsterSpriteHolder m_Monster;
		cocos2d::Scene *m_Scene;
		//cocos2d::Vec2(0.0f,0.0f), 1);
		float m_Speed = 0.0f;

	private:
		cocos2d::Vec2 m_Spawn;
		int spriteToUse = 0;
	};

	class BasicMonster: public baseMonster {
	public:
		BasicMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite);
		virtual void Update(float a_DeltaTime);
		void savePlatforms(OOP::PlatformGenerator *toSave);
	private:
		OOP::PlatformGenerator *forCalculations;
	};

	class MonsterManager {
	public:
		~MonsterManager();
		void spawn(cocos2d::Scene* scene, OOP::PlatformGenerator * toSave);
		void update(float a_DeltaTime);
		void addMonster(BasicMonster &a_Monster);
		void moveMonstersWithScreen(float amountX, float amountY);
		bool damageLeft(cocos2d::Sprite *m_MainCharacter, int invincible);
		bool damageRight(cocos2d::Sprite *m_MainCharacter, int invincible);

	private:
		std::vector <BasicMonster*> m_MonsterContainer;
	};
}




#endif //!H_MONSTER