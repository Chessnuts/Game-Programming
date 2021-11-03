#pragma once
#include "World.h"

using namespace std;

//Object that holds the world data

/*
	Intended map:

	########
	#G D#D #
	#   #  #
	### # D#
	#   #  #
	# #### #
	#      #
	##S#####
	########

	# = wall (impassable)
	S = Starting posisition
	D = Death
	G = Goal
*/

World::World()
{

}

Coordinates World::GetStart()
{
	//change this later to check the map for the starting point but for now  just give the hardcoded start
	Coordinates c;
	c.x = 2;
	c.y = 1;
	return c;
}

string World::GetPoint(Coordinates c) 
{
		return map[c.x][c.y];
}

bool World::CheckNorth(Coordinates c)
{
	if (map[c.x][c.y + 1] != "#")
	{
		return true;
	}
	return false;
}
	
bool World::CheckSouth(Coordinates c)
{
	if (map[c.x][c.y - 1] != "#")
	{
		return true;
	}
	return false;
}

bool World::CheckEast(Coordinates c)
{
	if (map[c.x + 1][c.y] != "#")
	{
		return true;
	}
	return false;
}

bool World::CheckWest(Coordinates c)
{
	if (map[c.x - 1][c.y] != "#")
	{
		return true;
	}
	return false;
}