#pragma once
#include <string>
#include "GameObject.h"
#include "Attribute.h"
#include "Inventory.h"

class Entity : public GameObject
{
public:
	Inventory inventory;
	int health;
	vector<Attribute> attributes;

	Entity(vector<string> ids, string n, string d, vector<string> ats);
	~Entity() {};

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;
};

