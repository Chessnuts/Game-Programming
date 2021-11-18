#pragma once
#include "Entity.h"
#include <string>
#include <vector>

using namespace std;

class Inventory
{
private:
	vector<Entity*> inventory;
public:
	Inventory() {};
	~Inventory();

	bool HasItem(string id);
	void Put(Entity* it);
	Entity Take(string id);
	Entity* Fetch(string id);
	string ItemList();
};

