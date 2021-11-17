#pragma once
#include "GameObject.h"
#include "Location.h"

using namespace std;

class Player : public GameObject
{
public:
	Player() {};
	Player(string n, string d, Location& l);
	~Player() {};
	Location* location;
	void MoveTo(Location* l);
};

