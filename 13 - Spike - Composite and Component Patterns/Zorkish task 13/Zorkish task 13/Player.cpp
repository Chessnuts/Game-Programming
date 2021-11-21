#include "Player.h"
#include "Location.h"
#include "Entity.h"

using namespace std;

Player::Player(string n, string d, Location& l) : Entity({ "me", "inventory" }, n, d, { "searchable" })
{
	location = &l;
}


void Player::MoveTo(Location* l)
{
	location = l;
}

string Player::GetShortDescription()
{
	return GameObject::GetShortDescription();
}

string Player::GetDescription()
{
	return GameObject::GetDescription();
}

string Player::GetFullDescription()
{
	return GetDescription() + "\n You are carrying: \n" + ItemList(); //add an item list
}