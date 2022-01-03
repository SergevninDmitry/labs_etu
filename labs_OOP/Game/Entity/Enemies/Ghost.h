#pragma once
#include "Enemy.h"


class Ghost : public Enemy {
public:
	Ghost();
	void fight(Entity* enemy);
	void change_dir(int iter);
};