#pragma once
#include "../movableEntity.h"
#include "../Character/Character.h"
#include "../../Command/ControlsCommand.h"

class Enemy : public movableEntity {
private:
	COMMANDS direction = UP;
public:
	const COMMANDS getDirection() const;
	void setDirection(COMMANDS val);
	const int getArmor() const;
	void setArmor(int val);
	const int getHealth() const;
	void setHealth(int val);
	const int getAttack() const;
	void setAttack(int val);
	void plusHealth(int val);
	friend std::ostream& operator<<(std::ostream& out, const Enemy& enemy);
};