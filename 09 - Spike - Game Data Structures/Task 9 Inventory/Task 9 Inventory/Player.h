#pragma once
#include "GameObject.h"
#include "Inventory.h"

using namespace std;

class Player : public GameObject
{
public:
	Inventory inventory;
	Player(string n, string d);
	~Player() {};
};

