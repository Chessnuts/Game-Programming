#include "Location.h"
#include <iostream>

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
			result += "\t" + l.first + " : " + l.second->GetName() + "\n";
		}
	}
	else
	{
		result = "There is nowhere to go...";
	}

	return result;
}

void Location::AddConnection(string direction, Location* location)
{
	connections.insert(make_pair(direction, location));
}

string Location::GetFullDescription()
{
	return "You are in " + GetName() + ". " + GetDescription() + ". \n" + ConnectionList();
}