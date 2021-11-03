// GridWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Player.h"
#include "World.h"
#include <algorithm>

using namespace std;

bool isRunning = true;

string Input() 
{
	string i;
	cin >> i;
	transform(i.begin(), i.end(), i.begin(), ::toupper);
	return i;
}

void Update(string input, World world, Player player, bool validAction)
{

	switch (input[0]) 
	{
	case 'N' :
		if (world.CheckNorth(player.GetCoords())) 
		{
			player.MoveNorth();
			bool validAction = true;
		}

		break;

	case 'S' :
		if (world.CheckSouth(player.GetCoords()))
		{
			player.MoveSouth();
			bool validAction = true;
		}

		break;

	case 'E' :
		if (world.CheckEast(player.GetCoords()))
		{
			player.MoveEast();
			bool validAction = true;
		}

		break;

	case 'W' :
		if (world.CheckWest(player.GetCoords()))
		{
			player.MoveWest();
			bool validAction = true;
		}

		break;

	case 'Q' :
		isRunning = false;
		
		break;

	default :
		bool validAction = false;
	}


}

void Render(World world, Player player, bool validAction)
{
	
}

int main()
{
	bool validAction = true;

	string input;
	World world;
	Player player(world.GetStart());

	cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for You!" << endl;
	cout << "Valid commands: N, S, E and W for direction. Q to quit the game." << endl << endl;
	


	Render(world, player, validAction);
	
	while (isRunning)
	{
		validAction = false;
		input = Input();
		Update(input, world, player, validAction); 
		Render(world, player, validAction);
	};
	
	return 0;
}
