#pragma once
#include "../movableEntity.h"
#include "../Items/Item.h"
#include "../Items/Heal.h"
#include "../Items/Damage.h"
#include "../Items/Protect.h"
#include "../Enemies/Enemy.h"

class Character : public movableEntity {
public:
	Character();
	const int getArmor() const;
	void setArmor(int val);
	const int getHealth() const;
	void setHealth(int val);
	const int getAttack() const;
	void setAttack(int val);
	void plusArmor(int val);
	void plusHealth(int val);
	void plusAttack(int val);
	void fight(Entity* enemy);
	void takeItem(Entity* potion);
	friend std::ostream& operator<<(std::ostream& out, const Character& MainHero);
};