#pragma once
#include <string>

using namespace std;

class Item
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

