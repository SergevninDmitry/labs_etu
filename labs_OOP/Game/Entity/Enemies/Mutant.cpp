#include "Mutant.h"


Mutant::Mutant() {
	setHealth(6);
	setArmor(4);
	setAttack(3);
}
void Mutant::fight(Entity* enemy) { plusHealth(-(dynamic_cast<Character&>(*enemy).getAttack() * (1 - getArmor() / 100))); };
void Mutant::change_dir(int iter) {
	if (iter % 4 == 0) { setDirection(UP); }
	if (iter % 4 == 1) { setDirection(LEFT); }
	if (iter % 4 == 2) { setDirection(DOWN); }
	if (iter % 4 == 3) { setDirection(RIGHT); }
}