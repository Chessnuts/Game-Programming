#pragma once
#include <string>
#include "GameObject.h"

using namespace std;

class Item : public GameObject
{
private:

public:
	Item(vector<string> ids, string n, string d);
	~Item() {};

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;
};
