#pragma once
#include "Coordinates.cpp"

class Player
{
private:
	Coordinates coords;

public:
	Player(int startX, int startY);
	int GetCoords();
	void MoveNorth();
	void MoveSouth();
	void MoveEast();
	void MoveWest();
};