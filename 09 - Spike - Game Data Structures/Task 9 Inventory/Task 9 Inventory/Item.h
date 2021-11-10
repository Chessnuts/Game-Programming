#pragma once
#include <string>
#include "GameObject.h"

using namespace std;

class Item: public GameObject
{
private:
	string name;
	string key;
	string description;
public:
	Item(string n, string d);
	~Item() {};

	string GetName();
	string GetKey();
	string GetDescription();
};
