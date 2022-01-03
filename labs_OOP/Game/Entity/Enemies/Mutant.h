#pragma once
#include "Enemy.h"


class Mutant : public Enemy {
public:
	Mutant();
	void fight(Entity* enemy);
	void change_dir(int iter);
};