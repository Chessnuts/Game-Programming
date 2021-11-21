#pragma once
#include <string>
#include "GameObject.h"
#include <map>
#include "Entity.h"

using namespace std;

class Location : public GameObject
{
public:
	map<string, Location*> connections;
	vector<Entity*> entities;

	Location() {};
	Location(vector<string> ids, string n, string d);
	~Location() {};

	Location* GetConnection(string direction);
	string ConnectionList();
	string EntityList();
	void AddConnection(string direction, Location* location);

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;
	Entity* Take(string id);
	Entity* Fetch(string id);
};

