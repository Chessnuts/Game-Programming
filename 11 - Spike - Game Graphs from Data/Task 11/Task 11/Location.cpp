#include "Location.h"
#include <iostream>

using namespace std;

Location::Location(vector<string> ids, string n, string d) : GameObject(ids, n, d)
{

}

Location* Location::GetConnection(string direction)
{
	return connections[direction];
}

string Location::ConnectionList()
{
	string result = "You can move: \n";

	for (const auto& l : connections)
	{
		result += "\t" + l.first + "\n";
	}

	return result;
}

void Location::AddConnection(string direction, Location *location)
{
	connections.insert(make_pair(direction, location));
}

string Location::GetFullDescription()
{
	return "You are in " + GetName() + ".";
}