#pragma once
#include "GameObject.h"
#include "Location.h"
#include "Inventory.h"

using namespace std;

class Player : public GameObject
{
public:
	Player() {};
	Player(string n, string d, Location& l);
	~Player() {};
	Inventory inventory;
	Location* location;
	void MoveTo(Location* l);

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;
};

