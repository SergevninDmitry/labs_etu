#include "FieldView.h"


FieldView::FieldView(Field& obj) : field(obj) {}
void FieldView::print() {
	for (int i = 0; i < field.getWidth(); i++) {
		for (int j = 0; j < field.getHeight(); j++) {
			CellView tmp(field.getboard(i,j));// вроде все окей
			std::cout << tmp;
		}
		std::cout << '\n';
	}
	CharacterView charStats(dynamic_cast<Character&>(*field.getHero()->getEntity()));
	charStats.print();
}