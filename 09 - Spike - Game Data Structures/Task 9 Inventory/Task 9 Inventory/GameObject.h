#pragma once
#include "IdentifiableObject.h"
class GameObject : public IdentifiableObject
{
private:
	string name;
	string description;

public:
	string GetName();
};

