#include "Inventory.h"

using namespace std;

bool Inventory::HasItem(string id)
{
	for (auto it : inventory)
	{
		if (it->AreYou(id))
		{
			return true;
		}
	}
	return false;
}

Inventory::~Inventory()
{
	for (auto v : inventory)
	{
		delete v;
	}
}

void Inventory::Put(Entity* it)
{
	inventory.push_back(it);
}

Entity Inventory::Take(string id)
{
	Entity it = *Fetch(id);

	//remove the item
	//inventory is a vector list of pointers to items, not a vecotr list of items

	for (auto v : inventory)
	{
		if (v->AreYou(it.FirstId()))
		{
			inventory.erase(find(inventory.begin(), inventory.end(), v));
		}
	}


	return it;
}

Entity* Inventory::Fetch(string id)
{
	for (auto it : inventory)
	{
		if (it->AreYou(id))
		{
			return it;
		}
	}
	return nullptr;
}

string Inventory::ItemList()
{
	string output;
	if (inventory.size() > 0)
	{
		for (auto it : inventory)
		{
			output += "\t" + it->GetShortDescription() + "\n";
		}
	}
	else
	{
		output = "\t There is nothing";
	}
	return output;
}