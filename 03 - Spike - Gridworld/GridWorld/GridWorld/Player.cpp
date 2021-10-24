#include "Player.h"

using namespace std;
class Player
{
private:
	int x;
	int y;

public: 
	// constructor
	Player(int startX, int startY)
	{
		x = startX;
		y = startY;
	};

	//returns the x coordinate 
	int GetX() 
	{
		return x;
	};


	//returns the y coordinate
	int GetY() 
	{
		return y;
	};

	//moves the player north by updating the y position 
	void MoveNorth() 
	{
		y++;
	};

	//moves the player south by updating the y position 
	void MoveSouth() 
	{
		y--;
	};

	// moves the player east by updating the x position
	void MoveEast() 
	{
		x++;
	};

	// moves the player east by updating the x position
	void MoveWest() 
	{
		x--;
	};
};