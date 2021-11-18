#pragma once
#include "GameObject.h"
#include "Location.h"
#include "Entity.h"

using namespace std;

class Player : public Entity
{
public:
	Player() {};
	Player(string n, string d, Location& l);
	~Player() {};
	Location* location;
	void MoveTo(Location* l);

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;
};

