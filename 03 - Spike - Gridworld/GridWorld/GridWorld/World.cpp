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
	string map[9][8] =
	{
		"#", "#",  "#",  "#",  "#",  "#",  "#",  "#",
		"#", "G",  " ",  "D",  "#",  "D",  " ",  "#",
		"#", " ",  " ",  " ",  "#",  " ",  " ",  "#",
		"#", "#",  "#",  " ",  "#",  " ",  "D",  "#",
		"#", " ",  " ",  " ",  "#",  " ",  " ",  "#",
		"#", " ",  "#",  "#",  "#",  "#",  " ",  "#",
		"#", " ",  " ",  " ",  " ",  " ",  " ",  "#",
		"#", "#",  "S",  "#",  "#",  "#",  "#",  "#",
		"#", "#",  "#",  "#",  "#",  "#",  "#",  "#"
	};
	
};