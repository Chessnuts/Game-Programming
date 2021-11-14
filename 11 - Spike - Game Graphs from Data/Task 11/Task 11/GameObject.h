#pragma once
#include "IdentifiableObject.h"
class GameObject : public IdentifiableObject
{
private:
	string name;
	string description;

public:
	GameObject() {};
	GameObject(vector<string> ids, string n, string d);
	~GameObject() {};
	string GetName();
	string GetShortDescription();
	string GetDescription();
	string GetFullDescription();
};

