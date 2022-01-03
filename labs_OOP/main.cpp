#include "Game/Game.h"



int main() {
	setlocale(0, "");
	srand(static_cast<unsigned int>(time(0)));
	Game<Rule_enemies_died<1>, Rule_step<1>> modelGame; // 6 врагов
	modelGame.StartGame();
}