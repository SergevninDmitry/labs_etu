#include "LoggerPull.h"


LoggerPull::LoggerPull(int mode, Entity* hero, std::vector <Cell*> enemies){
	this->mode = mode;
	mainLogger = new Logger(hero, enemies);
	if (mode == 0 || mode == 2) {
		consLogger = new ConsoleLogger(mainLogger);
	}
	if (mode == 1 || mode == 2) {
		fileLogger = new FileLogger(mainLogger);
	}
}


void LoggerPull::writeHero() {
	if (mode == 0 || mode == 2) {
		consLogger->writeHero();
	}
	if (mode == 1 || mode == 2) {
		fileLogger->writeHero();
	}
}


void LoggerPull::writeEnemy(Entity* enemy) {
	if (mode == 0 || mode == 2) {
		consLogger->writeEnemy(enemy);
	}
	if (mode == 1 || mode == 2) {
		fileLogger->writeEnemy(enemy);
	}
}


LoggerPull::~LoggerPull() {
	delete mainLogger;
	if (mode == 0 || mode == 2) {
		delete consLogger;
	}
	if (mode == 1 || mode == 2) {
		delete fileLogger;
	}
}