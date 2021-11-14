#pragma once
#include "GameObject.h"
#include "Location.h"

using namespace std;

class Player : public GameObject
{
private:
	Location *location;
public:
	Player(string n, string d, Location l);
	~Player() {};

	Location GetLocation();
	void MoveTo(Location *l);
};

