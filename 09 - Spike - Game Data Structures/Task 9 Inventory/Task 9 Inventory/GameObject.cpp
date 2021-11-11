#include "GameObject.h"
#include <string>

using namespace std;

GameObject::GameObject(vector<string> ids, string n, string d)
{
	name = n;
	description = d;
}

string GameObject::GetName()
{
	return name;
}

string GameObject::GetShortDescription()
{
	return name + " (" + FirstId() + ")";
}

string GameObject::GetFullDescription()
{
	return description;
}