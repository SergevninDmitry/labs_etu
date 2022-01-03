#include "Cell.h"

Cell::Cell() { Type = EMPTY; x = 0; y = 0; entity = nullptr; }


Cell::Cell(int x, int y, STATE typeCell) {
	this->x = x;
	this->y = y;
	this->Type = typeCell;
	entity = nullptr;
}


void Cell::setposX(int val) { this->x = val; }
void Cell::setposY(int val) { this->y = val; }
const int Cell::getposX() const { return this->x; }
const int Cell::getposY() const { return this->y; }
const STATE Cell::getType() const { return this->Type; }
void Cell::setType(STATE val) { this->Type = val; }
void Cell::setEntity(Entity* val) { this->entity = val; }
Entity* Cell::getEntity() const { return entity; }