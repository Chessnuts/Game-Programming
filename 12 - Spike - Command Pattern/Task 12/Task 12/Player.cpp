#include "Player.h"
#include "Location.h"

using namespace std;

Player::Player(string n, string d, Location& l) : GameObject({ "me", "inventory" }, n, d)
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
	return GameObject::GetFullDescription();
}