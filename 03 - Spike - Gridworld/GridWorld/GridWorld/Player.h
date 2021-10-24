#pragma once
using namespace std;
class Player
{
private:
	int x;
	int y;

public:
	Player(int startX, int startY);
	int GetX();
	int GetY();
	void MoveNorth();
	void MoveSouth();
	void MoveEast();
	void MoveWest();
};