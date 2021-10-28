#pragma once
#include "string"
#include "Coordinates.cpp"

class World
{
private:
	string map[8][9];

public:
	Coordinates GetStart();
	string GetPoint(Coordinates c);
	string GetMoves(Coordinates c);
};

