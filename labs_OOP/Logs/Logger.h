#pragma once
#include "../Game/Entity/Entity.h"
#include "../Game/Objects/Cell.h"
#include "../Game/Entity/Character/Character.h"
#include "../Game/Entity/Enemies/Troll.h"
#include "../Game/Entity/Enemies/Mutant.h"
#include "../Game/Entity/Enemies/Ghost.h"
#include <vector>
#include <map>


class Logger {
public:
	Entity* hero_sub = nullptr;
	std::map <Entity*, std::vector <int>> enemy_stats;
	std::vector <int> hero_stats = { 0, 0, 0 }; // hp, dmg, armor
	Logger() = default;
	Logger(Entity* hero, std::vector <Cell*> enemies);
	void clone_Character();
	void clone_Enemy(Entity* enemy);
};