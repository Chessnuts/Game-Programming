#include "Entity.h"

Entity::Entity(vector<string> ids, string n, string d) : GameObject(ids, n, d)
{
	
	
	
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