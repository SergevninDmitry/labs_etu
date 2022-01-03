#pragma once
#include "Entity.h"


class movableEntity : public Entity {
protected:
	int Armor = 0;
	int Health = 0;
	int Attack = 0;
public:
	virtual void setArmor(int val) = 0;
	virtual void setHealth(int val) = 0;
	virtual void setAttack(int val) = 0;
	virtual const  int getArmor() const = 0;
	virtual const  int getAttack() const = 0;
	virtual const  int getHealth() const = 0;
	virtual void plusHealth(int val) = 0;
	virtual void fight(Entity* enemy) = 0;// можем вернуть указатель узнаем какой это из врагов по этому указателю оповещаем логгер об изменении

};