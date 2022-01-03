#pragma once
#include <string>
#include <iostream>
#include"../Entity/Entity.h"

enum STATE { EMPTY, WALL, START, FINISH };

class Cell {
private:
	Entity* entity = nullptr;
	int x;
	int y;
	STATE Type; // EMPTY, WALL, START, FINISH

public:
	Cell();
	Cell(int x, int y, STATE typeCell);
	void setposX(int val);
	void setposY(int val);
	const int getposX() const;
	const int getposY() const;
	const STATE getType() const;
	void setType(STATE val);
	void setEntity(Entity* val);
	Entity* getEntity() const;

};
