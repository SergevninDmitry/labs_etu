#pragma once
#include "../Game/Entity/Character/Character.h"


class CharacterView {
private:
	Character& mainChar;
public:
	CharacterView(Character& obj);
	void print();
};