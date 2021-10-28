#include "Player.h"

using namespace std;
class Player
{
private:
	Coordinates coords;

public: 
	// constructor
	Player(Coordinates startCoords)
	{
		coords = startCoords;
	};

	//returns the x coordinate 
	Coordinates GetCoords() 
	{
		return coords;
	};

	//moves the player north by updating the y position 
	void MoveNorth() 
	{
		coords.y++;
	};

	//moves the player south by updating the y position 
	void MoveSouth() 
	{
		coords.y--;
	};

	// moves the player east by updating the x position
	void MoveEast() 
	{
		coords.x++;
	};

	// moves the player east by updating the x position
	void MoveWest() 
	{
		coords.x--;
	};
};