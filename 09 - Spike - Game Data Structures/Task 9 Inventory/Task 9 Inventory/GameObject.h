#pragma once
#include "IdentifiableObject.h"
class GameObject : public IdentifiableObject
{
private:
	string name;
	string description;

public:
	GameObject() {};
	GameObject(vector<string> ids, string n, string d) : IdentifiableObject(ids);
	~GameObject() {};
	string GetName();
	string GetShortDescription();
	string GetFullDescription();
};

