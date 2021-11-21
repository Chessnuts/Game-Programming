#include "Location.h"
#include <iostream>
#include "Entity.h"

using namespace std;

Location::Location(vector<string> ids, string n, string d) : GameObject(ids, n, d)
{

}

Location* Location::GetConnection(string direction)
{
	if (connections.count(direction))
	{
		return connections[direction];
	}
	return nullptr;
}

string Location::ConnectionList()
{
	string result = "You can move: \n";
	if (connections.size() > 0)
	{
		for (const auto& l : connections)
		{
			result += "\t" + l.first + "\n";
		}
	}
	else
	{
		result = "There is nowhere to go... \n";
	}

	return result;
}

string Location::EntityList()
{
	string result = "You can see: \n";
	if (!entities.empty())
	{
		for (auto e : entities)
		{
			if (e != nullptr)
			{
				result += "\t" + e->GetShortDescription() + "\n";
			}
		}
	}
	else
	{
		result += "Nothing... \n";
	}

	return result;
}

Entity* Location::Take(string id)
{
	Entity* it = Fetch(id);

	//remove the item
	//inventory is a vector list of pointers to items, not a vecotr list of items

	for (auto v : entities)
	{
		if (v->AreYou(it->FirstId()))
		{
			entities.erase(find(entities.begin(), entities.end(), v));
		}
	}
	return it;
}

Entity* Location::Fetch(string id)
{
	for (auto it : entities)
	{
		if (it->AreYou(id))
		{
			return it;
		}
	}
	return nullptr;
}

void Location::AddConnection(string direction, Location* location)
{
	connections.insert(make_pair(direction, location));
}

string Location::GetFullDescription()
{
	return "You are in " + GetName() + ". " + GetDescription() + ". \n" + ConnectionList() + "\n" + EntityList();
}

string Location::GetShortDescription()
{
	return "You are in " + GetName() + ". ";
}

string Location::GetDescription()
{
	return GameObject::GetDescription();
}
