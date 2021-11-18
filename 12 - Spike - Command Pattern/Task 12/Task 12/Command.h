#pragma once
#include "IdentifiableObject.h"
#include "Player.h"
#include "Location.h"
#include <string>
#include <vector>

using namespace std;

class Command : public IdentifiableObject
{
public:
	Command() {};
	Command(vector<string> ids);
	~Command() {};

	virtual string Execute(vector<string> input, Location* location, Player* player) = 0;
};

