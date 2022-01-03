#pragma once
#include <iostream>

class InputCommand {
private://map из команд в контролс комманд команда-сивмвол контрол команд получает комманду и понимает сразу какую функцию надо выполнять
	char up = 'w', down = 's', right = 'd', left = 'a', none = '@', save = 'k', load = 'l'; // пофиксить переназначение клавиш qqqq
public:
	InputCommand() = default;
	char get_up() const { return up; }
	void set_up(char val);
	char get_down() const { return down; }
	void set_down(char val);
	char get_left() const { return left; }
	void set_left(char val);
	char get_right() const { return right; }
	void set_right(char val);
	char get_none() const { return none; }
	char get_save() { return save; }
	char get_load() { return load; }

	char get_command();
};