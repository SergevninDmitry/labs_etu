#pragma once
#include "Game/GameStats.h"

template<int EnemiesDied>  // 5 ������ ������ ������� ��� �������� ���� 10 �� 10
class Rule_enemies_died {
public:
    bool Check(GameStats& stats);
};

template<int EnemiesDied>
bool Rule_enemies_died<EnemiesDied>::Check(GameStats& stats) {
    return EnemiesDied <= stats.getEnemyKilled();
}


