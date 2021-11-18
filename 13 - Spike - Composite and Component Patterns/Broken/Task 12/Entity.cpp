#include "Entity.h"
#include "Attribute.h"

Entity::Entity(vector<string> ids, string n, string d, vector<string> ats) : GameObject(ids, n, d)
{
	for (auto a : ats)
	{
		attributes.push_back(Attribute({ a }));
	}

	for (auto a : attributes)
	{
		if (a.AreYou("health"))
		{
			health = 100;
		}
	}
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