#pragma once

class GameStats {
private:
    int enemy_killed;
    int steps_made;//change for count
public:
    GameStats();
    int getEnemyKilled() const;
    int getStepsMade() const;
    void setEnemyKilled(int number);
    void setStepsMade();
};