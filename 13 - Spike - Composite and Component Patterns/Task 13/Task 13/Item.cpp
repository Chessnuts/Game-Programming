#include "Item.h"

Item::Item(vector<string> ids, string n, string d) : GameObject(ids, n, d)
{

}

string Item::GetShortDescription()
{
	return GameObject::GetShortDescription();
}

string Item::GetDescription()
{
	return GameObject::GetDescription();
}

string Item::GetFullDescription()
{
	return GameObject::GetFullDescription();
}