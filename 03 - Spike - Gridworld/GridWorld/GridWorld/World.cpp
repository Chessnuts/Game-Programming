#include "World.h"
#include "string"

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
	string GetPoint(Coordinates c) 
	{
		return map[c.x][c.y];
	};

	string GetMoves(Coordinates c)
	{
		//how do i want to pass this back and process it??
	};
	
};