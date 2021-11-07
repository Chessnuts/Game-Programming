#pragma once
#include "Item.h"


class Inventory
{
private:

public:
	Inventory();
	~Inventory();

	void add(Item item);
	void remove();
};

