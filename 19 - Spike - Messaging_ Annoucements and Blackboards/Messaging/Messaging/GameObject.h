#pragma once
#include "IdentifiableObject.h"
class GameObject : public IdentifiableObject
{
protected:
	string name;
	string description;

public:
	GameObject() {};
	GameObject(vector<string> ids, string n, string d);
	~GameObject() {};
	string GetName();
	virtual string GetShortDescription();
	virtual string GetDescription();
	virtual string GetFullDescription();
};

