#pragma once
#include "IdentifiableObject.h"
class Attribute :
    public IdentifiableObject
{
public:
	Attribute() {};
	Attribute(vector<string> ids);
	~Attribute() {};
};

