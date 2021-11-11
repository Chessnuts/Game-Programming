#pragma once
#include "Item.h"
#include <string>
#include <vector>

using namespace std;

class Inventory
{
private:
	vector<Item*> inventory;
public:
	Inventory();
	~Inventory();

	bool HasItem(string id);
	void Put(Item *it);
	Item Take(string id);
	Item* Fetch(string id);
	string ItemList();
};

