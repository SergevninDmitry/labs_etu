#include "InputCommand.h"

char InputCommand::get_command() {
	std::cout << "Enter the direction of movement of the character, where " << get_up() << " - up, "
		<< get_down() << " - down, " << get_left() << " - left," << get_right() << " - right:\nOr save by clicking " << get_save() << "\nOr load by clicking " << get_load() << '\n';
	char cur_control;
	std::cin >> cur_control;
	if (cur_control == up || cur_control == down || cur_control == right || cur_control == left || cur_control == save || cur_control == load) {// проверка поменяется с мап
		return cur_control;
	}
	else {
		return none;
	}
}

void InputCommand::set_up(char val) {
	this->up = val;
}
void InputCommand::set_down(char val) {
	this->down = val;
}
void InputCommand::set_left(char val) {
	this->left = val;
}
void InputCommand::set_right(char val) {
	this->right = val;
}
