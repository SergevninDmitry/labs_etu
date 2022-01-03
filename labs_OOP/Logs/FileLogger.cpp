#include "FileLogger.h"

FileLogger::FileLogger(Logger* logger) {
	this->logger = logger;
	file.open("logs.txt");
}

void FileLogger::writeHero() {
	file << "\n[HERO CHANGE]\n";
	file << "From:\nHealth: " << (*logger).hero_stats[0] << "\nDamage: " << (*logger).hero_stats[1] << "\nArmor: " << (*logger).hero_stats[2] << "\nTo: " << dynamic_cast<Character&>(*(*logger).hero_sub);
}

void FileLogger::writeEnemy(Entity* enemy) {
	file << "\n[ENEMY_CHANGE]\n";
	file << "From:\nHealth: " << (*logger).enemy_stats[enemy][0] << "\nDamage: " << (*logger).enemy_stats[enemy][1] << "\nArmor: " << (*logger).enemy_stats[enemy][2] << "\nTo: " << dynamic_cast<Enemy&>(*enemy);
}


FileLogger::~FileLogger() {
	file.close();
}