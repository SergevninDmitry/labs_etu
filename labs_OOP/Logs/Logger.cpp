#include "Logger.h"

Logger::Logger(Entity * hero, std::vector <Cell*> enemies){
	hero_sub = hero;
	clone_Character();
	for (int i = 0; i < enemies.size(); i++) {
		enemy_stats.insert(std::pair<Entity*, std::vector<int>>(enemies[i]->getEntity(), { 0, 0, 0 }));
		clone_Enemy(enemies[i]->getEntity());
	}
}


void Logger::clone_Character() {
	hero_stats[0] = (dynamic_cast<Character&>(*hero_sub)).getHealth();
	hero_stats[1] = (dynamic_cast<Character&>(*hero_sub)).getAttack();
	hero_stats[2] = (dynamic_cast<Character&>(*hero_sub)).getArmor();
}


void Logger::clone_Enemy(Entity* enemy) {
	enemy_stats[enemy][0] = (dynamic_cast<Enemy&>(*enemy)).getHealth();
	enemy_stats[enemy][1] = (dynamic_cast<Enemy&>(*enemy)).getAttack();
	enemy_stats[enemy][2] = (dynamic_cast<Enemy&>(*enemy)).getArmor();
}