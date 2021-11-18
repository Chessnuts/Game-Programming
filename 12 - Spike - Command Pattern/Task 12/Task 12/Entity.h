#pragma once
#include <string>
#include "GameObject.h"
class Entity : public GameObject
{
public:
	Entity(vector<string> ids, string n, string d);
	~Entity() {};

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;
};

