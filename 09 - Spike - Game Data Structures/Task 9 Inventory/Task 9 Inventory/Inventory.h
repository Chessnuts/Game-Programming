#pragma once
#include "Item.h"
#include <string>
#include <map>

using namespace std;

class Inventory
{
private:
	multimap<string&, Item> inventory;
public:
	Inventory();
	~Inventory();

	void Add(Item *item);
	void Remove(Item* item, string key);
	bool HasItem(Item* item, string key);
	Item Get(string name);
	void View();
};

