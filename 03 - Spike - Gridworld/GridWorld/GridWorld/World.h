#pragma once
#include "Coordinates.cpp"


class World
{
private:
	string map[8][9];

public:
	string GetPoint();
	string GetMoves();
};

