#pragma once
#include <string>
#include "GameObject.h"
#include <map>

using namespace std;

class Location : public GameObject
{
private:
	map<string, Location*> connections;
public:
	Location() {};
	Location(vector<string> ids, string n, string d);
	~Location() {};

	Location* GetConnection(string direction);
	string ConnectionList();
	void AddConnection(string direction, Location *location);

	string GetFullDescription();
};

