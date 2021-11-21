
#include "Entity.h"
#include "Attribute.h"

using namespace std;

Entity::Entity(vector<string> ids, string n, string d, vector<string> ats = {" "}) : GameObject(ids, n, d)
{
	for (auto a : ats)
	{
		attributes.push_back(Attribute({ a }));
	}

	for (auto a : attributes)
	{
		if (a.AreYou("health"))
		{
			health = 100;
		}
	}
}

Entity::~Entity()
{
	for (auto e : items)
	{
		delete e;
	}
}

string Entity::GetShortDescription()
{
	return GetName();
}

string Entity::GetDescription()
{
	return GameObject::GetDescription();
}

string Entity::GetFullDescription()
{
	string output = GetName() + ": " + GetDescription();

	if (!attributes.at(0).AreYou(" "))
	{
		output += " (";
		for (auto a : attributes)
		{
			if (a.AreYou("health"))
			{
				output += a.FirstId() + " : " + to_string(health) + ", ";
			}
			else
			{
				output += a.FirstId() + ", ";
			}
		}
		output = output.substr(0, output.length() - 2);
		output += ")";
	}
	
	return output;
}

bool Entity::HasItem(string id)
{
	for (auto it : items)
	{
		if (it->AreYou(id))
		{
			return true;
		}
	}
	return false;
}

void Entity::Put(Entity* it)
{
	items.push_back(it);
}

Entity* Entity::Take(string id)
{
	Entity *it = Fetch(id);

	//remove the item
	//inventory is a vector list of pointers to items, not a vecotr list of items

	for (auto v : items)
	{
		if (v->AreYou(it->FirstId()))
		{
			items.erase(find(items.begin(), items.end(), v));
		}
	}
	return it;
}

Entity* Entity::Fetch(string id)
{
	for (auto it : items)
	{
		if (it->AreYou(id))
		{
			return it;
		}
	}
	return nullptr;
}

string Entity::ItemList()
{
	string output;
	if (items.size() > 0)
	{
		for (auto it : items)
		{
			output += "\t" + it->GetShortDescription() + "\n";
		}
	}
	else
	{
		output = "\t There is nothing.";
	}
	return output;
}


