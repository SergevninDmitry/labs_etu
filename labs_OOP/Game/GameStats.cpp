#include "GameStats.h"

GameStats::GameStats() {
    enemy_killed = 0;
    steps_made = 0;
}

void GameStats::setEnemyKilled(int number) {
    this->enemy_killed = number;
}

void GameStats::setStepsMade() {
    this->steps_made += 1;
}

int GameStats::getEnemyKilled() const {
    return this->enemy_killed;
}

int GameStats::getStepsMade() const {
    return this->steps_made;
}