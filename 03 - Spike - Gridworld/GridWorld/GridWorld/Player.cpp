#pragma once
#include "Player.h"
#include <iostream>

using namespace std;


//constructor
Player::Player(Coordinates startCoords)
{
	coords = startCoords;
}

//returns the x coordinate 
Coordinates Player::GetCoords() 
{
	return coords;
}

//moves the player north by updating the y position 
void Player::MoveNorth() 
{
	//cout << coords.y << endl;

	coords.y++;

	//cout << coords.y << endl;
}

//moves the player south by updating the y position 
void Player::MoveSouth() 
{
	coords.y--;
}

// moves the player east by updating the x position
void Player::MoveEast() 
{
	coords.x++;
}

// moves the player east by updating the x position
void Player::MoveWest() 
{
	coords.x--;
}
