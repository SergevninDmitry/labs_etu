#pragma once
#include "../Game/Objects/Cell.h"


class CellView {
private:
	Cell& cell;
public:
	CellView(Cell& obj);
	friend std::ostream& operator<< (std::ostream& out, const CellView& obj);
};