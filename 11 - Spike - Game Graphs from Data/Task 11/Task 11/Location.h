#pragma once
#include <string>
#include "GameObject.h"
#include <map>

using namespace std;

class Location : public GameObject
{
private:
	map<string, Location> connections;
public:
	Location(vector<string> ids, string n, string d);
	~Location() {};

	string GetFullDescription();
};

