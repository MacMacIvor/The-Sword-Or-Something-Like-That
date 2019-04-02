#ifndef H_MONSTER
#define H_MONSTER

#include <functional>
#include "cocos2d.h"
#include "EnemySpriteHolder.h"
#include "PlatformGenerator.h"
#include "Bullet.h"


namespace cocos2d {
	class Event;
	class EventListenerMouse;
	class Label;
}
class HelloWorld;


namespace OOP {
	class baseMonster {
	public:
		baseMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite, const cocos2d::Vec2 a_Maxes);

		virtual bool attack(cocos2d::Sprite *character);

		virtual void Update(float a_DeltaTime);
		
		virtual void move(float a_DeltaTime) = 0;

		void moveMaxes(float amountX) {	this->m_MaxMovement.y += amountX; this->m_MaxMovement.x += amountX; }

		void saveScene(cocos2d::Scene *scene) { m_Scene = scene; };
		virtual void moveBullets(float X, float Y) {};
		virtual void cleanBullets() {};
		virtual bool bulletDamage(cocos2d::Sprite *character) { return false; };
		
		//I HAAAAAAATTTTTTEEEEE CCCCOOOOOOCCCCCOOOOSSSS!!!!
		OOP::MonsterSpriteHolder m_Monster;
		cocos2d::Scene *m_Scene;
		//cocos2d::Vec2(0.0f,0.0f), 1);
		float m_Speed = 0.0f;
		void const reset();
		cocos2d::Sprite m_MainCharacter;
		cocos2d::Vec2 m_Spawn;
		cocos2d::Vec2 m_OG_Spawn;
		cocos2d::Vec2 m_MaxMovement;

		void beHert(int, bool);
		bool isDead();
		void setHP(int);
		void takeDMG();
		bool hashurt();
		void reduceI();

	private:
		int HP = 2;//health
		int I_frames = 0;
		int spriteToUse = 0;
		int swingCoolDown;
	};
	
	class ShootingMonster : public baseMonster {
	public:
		ShootingMonster(cocos2d::Vec2 a_Spawn, float a_Speed, int a_Sprite, const cocos2d::Vec2 a_Maxes);
		bool attack(cocos2d::Sprite *character);
		void savePlatforms(OOP::PlatformGenerator *toSave);
		virtual void Update(float a_DeltaTime);
		void move(float a_DeltaTime) { ; };
		virtual void moveBullets(float X, float Y);
		virtual void cleanBullets();
		virtual bool bulletDamage(cocos2d::Sprite *character);



	private:
		int HP = 1;
		std::vector <OOP::Bullet *> m_Bullets;
		OOP::PlatformGenerator *forCalculations;
		int shotCoolDown = 0;
	};

	class BasicMonster: public baseMonster {
	public:
		BasicMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite, const cocos2d::Vec2 a_Maxes);
		void move(float a_DeltaTime);
		virtual void Update(float a_DeltaTime);
		void savePlatforms(OOP::PlatformGenerator *toSave);
		cocos2d::Vec2 saveMax();
	private:
		int HP = 2;
		OOP::PlatformGenerator *forCalculations;
		bool isAttacking = false;
	};
	
	class HeavyMonster : public baseMonster {
	public:
		HeavyMonster(cocos2d::Vec2 & a_Spawn, float a_Speed, int a_Sprite, const cocos2d::Vec2 a_Maxes);
		void move(float a_DeltaTime);
		void Update(float a_DeltaTime);
		void savePlatforms(OOP::PlatformGenerator *toSave);
		cocos2d::Vec2 saveMax();

	private:
		int HP = 4;
		int isAttacking = 0;
		bool leftRight = true; //true is left and right is false for the monsters attack
		OOP::PlatformGenerator *forCalculations;
	};

	class MonsterManager: public OOP::myLevels {
	public:
		~MonsterManager();
		void spawn(cocos2d::Scene* scene, OOP::PlatformGenerator * toSave, OOP::myLevels* level);
		void const monsterResest(cocos2d::Scene* scene, OOP::PlatformGenerator * toSave);

		void update(float a_DeltaTime);
		void addMonster(BasicMonster &a_Monster);
		void moveMonstersWithScreen(float amountX, float amountY);
		bool damageLeft(cocos2d::Sprite *m_MainCharacter, int invincible);
		bool damageRight(cocos2d::Sprite *m_MainCharacter, int invincible);
		void getMainCharacter(cocos2d::Sprite* n_Character) { m_Character = n_Character; }
		void saveScene(cocos2d::Scene *scene) { m_Scene = scene; };
		bool isZipZilchZero();
		bool getHurt(cocos2d::Sprite *m_MainCharacter);

	private:
		std::vector <baseMonster*> m_MonsterContainer;
		cocos2d::Sprite* m_Character;
		cocos2d::Scene *m_Scene;

	};
}




#endif //!H_MONSTER