// GridWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Player.h"
#include "World.h"

using namespace std;

string Input() 
{
	// get input and ignore case
	return " ";
}

void Update(string input, World world, Player player, bool validAction)
{
	//check if valid

	//if valid, update position 

	//else don't and return invalid signal
}

void Render(World world, Player player, bool validAction)
{
	
}

int main()
{
	bool isRunning = true;

	string input;
	World world;
	Player player(world.GetStart());

	cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for You!" << endl;
	cout << "Valid commands: N, S, E and W for direction. Q to quit the game." << endl << endl;
	
	/*
	cout << player.GetCoords().x << " " << player.GetCoords().y << endl;
	cout << world.GetPoint(player.GetCoords()) << endl;
	*/
	
	while (isRunning)
	{
		bool validAction = false;
		input = Input();
		Update(input, world, player, validAction); 
		Render(world, player, validAction);
	};
	
	return 0;
}
