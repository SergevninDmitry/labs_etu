#pragma once
#include "../Game/GameStats.h"

template<int Steps>
class Rule_step {
public:
    bool Check(GameStats& stats);
};

// изменить на поинты
template<int Steps>
bool Rule_step<Steps>::Check(GameStats& stats) {
    return Steps <= stats.getStepsMade();
}