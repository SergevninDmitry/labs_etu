#include "Ghost.h"


Ghost::Ghost() { setHealth(7); setArmor(1); setAttack(2); }
void Ghost::fight(Entity* enemy) { plusHealth(-(dynamic_cast<Character&>(*enemy).getAttack() * (1 - getArmor() / 100))); };
void Ghost::change_dir(int iter) {
	if (iter % 12 == 0) { setDirection(RIGHT); }
	if (iter % 12 == 3) { setDirection(UP); }
	if (iter % 12 == 6) { setDirection(LEFT); }
	if (iter % 12 == 9) { setDirection(DOWN); }
}
