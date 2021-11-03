#pragma once
#include "string"
#include "Coordinates.cpp"

class World
{
private:
	string map[8][9] = {
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
	World();
	Coordinates GetStart();
	string GetPoint(Coordinates c);
	bool CheckNorth(Coordinates c);
	bool CheckSouth(Coordinates c);
	bool CheckEast(Coordinates c);
	bool CheckWest(Coordinates c);
};

