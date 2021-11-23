#include "Entity.h"

Entity::Entity(vector<string> ids, string n, string d, BlackBoard* bb) : GameObject(ids, n, d)
{
	blackBoard = bb;
}

string Entity::GetShortDescription()
{
	return GameObject::GetShortDescription();
}

string Entity::GetDescription()
{
	return GameObject::GetDescription();
}

string Entity::GetFullDescription()
{
	return GameObject::GetFullDescription();
}

