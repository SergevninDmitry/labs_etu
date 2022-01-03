#include "Troll.h"


Troll::Troll() { setHealth(10); setArmor(2); setAttack(3); }
void Troll::fight(Entity* enemy) { plusHealth(-(dynamic_cast<Character&>(*enemy).getAttack() * (1 - getArmor() / 100))); };
void Troll::change_dir(int iter) {
	if (iter % 8 == 0) { setDirection(LEFT); }
	if (iter % 8 == 2) { setDirection(UP); }
	if (iter % 8 == 4) { setDirection(DOWN); }
	if (iter % 8 == 6) { setDirection(RIGHT); }
}
