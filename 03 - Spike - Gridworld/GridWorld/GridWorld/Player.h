#pragma once
#include "Coordinates.cpp"

class Player
{
private:
	Coordinates coords;

public:
	Player(Coordinates startCoords);
	Coordinates GetCoords();
	void MoveNorth();
	void MoveSouth();
	void MoveEast();
	void MoveWest();
};