#pragma once
#include "InputCommand.h"

enum COMMANDS { UP, DOWN, RIGHT, LEFT, NONE, SAVE, LOAD };


class Commander
{
private:
	InputCommand* controls;
public:
	Commander() {
		controls = new InputCommand;
	};
	COMMANDS determinate_the_command();
	InputCommand* get_controls() const;
	~Commander() {
		delete controls;
	}
};