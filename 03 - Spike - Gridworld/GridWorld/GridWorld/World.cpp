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

string World::GetMoves(Coordinates c)
{
	//how do i want to pass this back and process it??
	return " ";
}
	
