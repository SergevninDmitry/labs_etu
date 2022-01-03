#pragma once
#include "Enemy.h"


class Troll : public Enemy {
public:
	Troll();
	void fight(Entity* enemy);
	void change_dir(int iter);
};