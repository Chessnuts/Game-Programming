#pragma once
#include <string>
#include "GameObject.h"
#include "Attribute.h"

using namespace std;

class Entity : public GameObject
{
public:
	vector<Entity*> items;
	int health = 0;
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

