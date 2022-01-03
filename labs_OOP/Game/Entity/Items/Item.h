#pragma once
#include "../Entity.h"


class Item : public Entity {
protected:
	int Value = 0;
public:
	const int getValue() const;
};