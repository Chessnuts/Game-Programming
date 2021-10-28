#include "World.h"

using namespace std;
class World
{
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

private: 
	//set up so coords can be used as (x, y)
	string map[8][9] = 
	{
		{"#", "#", "#", "#", "#", "#", "#", "#", "#"},
		{"#", "#", " ", " ", " ", "#", " ", "G", "#"},
		{"#", "S", " ", "#", " ", "#", " ", " ", "#"},
		{"#", "#", " ", "#", " ", " ", " ", "D", "#"},
		{"#", "#", " ", "#", "#", "#", "#", "#", "#"},
		{"#", "#", " ", "#", " ", " ", " ", "D", "#"},
		{"#", "#", " ", " ", " ", "D", " ", " ", "#"},
		{"#", "#", "#", "#", "#", "#", "#", "#", "#"},
	};

public:
	Coordinates GetStart() 
	{
		//change this later to check the map for the starting point but for now  just give the hardcoded start
		Coordinates c;
		c.x = 2;
		c.y = 1;
		return c;
	}

	string GetPoint(Coordinates c) 
	{
		return map[c.x][c.y];
	};

	string GetMoves(Coordinates c)
	{
		//how do i want to pass this back and process it??
	};
	
};