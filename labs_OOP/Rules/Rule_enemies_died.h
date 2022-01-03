#pragma once
#include "Game/GameStats.h"

template<int EnemiesDied>  // 5 врагов должно умереть при создании поля 10 на 10
class Rule_enemies_died {
public:
    bool Check(GameStats& stats);
};

template<int EnemiesDied>
bool Rule_enemies_died<EnemiesDied>::Check(GameStats& stats) {
    return EnemiesDied <= stats.getEnemyKilled();
}


