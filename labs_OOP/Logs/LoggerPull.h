#pragma once
#include "ConsoleLogger.h"
#include "FileLogger.h"

class LoggerPull {
public:
	int mode;
	Logger* mainLogger;
	ConsoleLogger* consLogger;
	FileLogger* fileLogger;
	LoggerPull() = default;
	LoggerPull(int mode, Entity* hero, std::vector <Cell*> enemies);
	void writeHero();
	void writeEnemy(Entity* enemy);
	~LoggerPull();
};