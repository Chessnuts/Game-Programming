#include "Player.h"
#include "Location.h"

using namespace std;

Player::Player(string n, string d, Location l) : GameObject({ "me", "inventory" }, n, d)
{
	location = &l;
}

Location Player::GetLocation()
{
	return *location;
}

void Player::MoveTo(Location *l)
{
	location = l;
}