#include "Character.h"


Character::Character() { setArmor(2); setHealth(10); setAttack(3); }

const int Character::getArmor() const {
	return this->Armor;
}
void Character::setArmor(int val) {
	this->Armor = val;
}
const int Character::getHealth() const {
	return this->Health;
}
void Character::setHealth(int val) {
	this->Health = val;
}
const int Character::getAttack() const {
	return this->Attack;
}
void Character::setAttack(int val) {
	this->Attack = val;
}
void Character::plusArmor(int val) {
	this->Armor += val;
}
void Character::plusHealth(int val) {
	this->Health += val;
}
void Character::plusAttack(int val) {
	this->Attack += val;
}
void Character::fight(Entity* enemy) {
	plusHealth(-(dynamic_cast<Enemy&>(*enemy).getAttack() * (1 - getArmor() / 100)));
};
void Character::takeItem(Entity* potion) {
	if (typeid(*potion).name() == typeid(Heal).name()) {
		plusHealth(dynamic_cast<Item&>(*potion).getValue());
	}
	if (typeid(*potion).name() == typeid(Protect).name()) {
		plusArmor(dynamic_cast<Item&>(*potion).getValue());
	}
	if (typeid(*potion).name() == typeid(Damage).name()) {
		plusAttack(dynamic_cast<Item&>(*potion).getValue());
	}
};

std::ostream& operator<<(std::ostream& out, const Character& MainHero) {
	std::string text = "\nPlayer info: \nHealth: " + std::to_string(MainHero.getHealth()) + "\nDamage: " + std::to_string(MainHero.getAttack()) + "\nArmor: " + std::to_string(MainHero.getArmor()) + '\n';
	out << text;
	return out;
}