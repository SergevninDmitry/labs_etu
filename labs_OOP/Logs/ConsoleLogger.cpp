#include "ConsoleLogger.h"


void ConsoleLogger::writeHero() {
	std::cout << "\n[HERO CHANGE]\n";
	std::cout << "From:\nHealth: " << (*logger).hero_stats[0] << "\nDamage: " << (*logger).hero_stats[1] << "\nArmor: " << (*logger).hero_stats[2] << "\nTo: " << dynamic_cast<Character&>(*(*logger).hero_sub);
}

void ConsoleLogger::writeEnemy(Entity* enemy) {
	std::cout << "\n[ENEMY_CHANGE]\n";
	std::cout << "From:\nHealth: " << (*logger).enemy_stats[enemy][0] << "\nDamage: " << (*logger).enemy_stats[enemy][1] << "\nArmor: " << (*logger).enemy_stats[enemy][2] << "\nTo: " << dynamic_cast<Enemy&>(*enemy);
}