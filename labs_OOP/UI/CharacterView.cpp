#include "CharacterView.h"


CharacterView::CharacterView(Character& obj) : mainChar(obj) {}
void CharacterView::print() {
	std::cout << "\nHero stats: health - " << mainChar.getHealth() << ", armor - " << mainChar.getArmor() << ", damage - " << mainChar.getAttack() << "\n";
}