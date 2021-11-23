#pragma once
#include <string>
#include "GameObject.h"
#include "Attribute.h"
#include "Health.cpp"

using namespace std;

class Entity : public GameObject
{
public:
	vector<Entity*> items;
	Health hp = { NULL };
	vector<Attribute> attributes;

	Entity() {};
	Entity(vector<string> ids, string n, string d, vector<string> ats);
	~Entity();

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;

	bool HasItem(string id);
	void Put(Entity *it);
	Entity* Take(string id);
	Entity* Fetch(string id);
	string ItemList();
};

