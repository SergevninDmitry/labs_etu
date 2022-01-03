#pragma once
#include "../Game/Objects/Field.h"
#include "CellView.h"
#include "CharacterView.h"

class FieldView {
private:
	Field& field;
public:
	FieldView(Field& obj);
	void print();
};
