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

void Update(string input, World world, Player& player, bool& validAction)
{

	switch (input[0]) 
	{
	case 'N' :
		if (world.CheckNorth(player.GetCoords())) 
		{
			//cout << "you moved north" << endl;
			player.MoveNorth();
			validAction = true;
		}

		break;

	case 'S' :
		if (world.CheckSouth(player.GetCoords()))
		{
			//cout << "you moved south" << endl;
			player.MoveSouth();
			validAction = true;
		}

		break;

	case 'E' :
		if (world.CheckEast(player.GetCoords()))
		{
			//cout << "you moved east" << endl;
			player.MoveEast();
			validAction = true;
		}

		break;

	case 'W' :
		if (world.CheckWest(player.GetCoords()))
		{
			//cout << "you moved west" << endl;
			player.MoveWest();
			validAction = true;
		}

		break;

	case 'Q' :
		isRunning = false;
		validAction = true;
		break;

	default :
		validAction = false;
	}


}

void Render(World world, Player player, bool validAction)
{
	// cout << player.GetCoords().x << player.GetCoords().y << endl;
	if (isRunning)
	{
		if (validAction == false)
		{
			cout << "Invalid command, please try again." << endl;
		}

		if (world.GetPoint(player.GetCoords()) == "G")
		{
			cout << "Wow - you’ve discovered a large chest filled with GOLD coins!" << endl;
			cout << "YOU WIN!!" << endl;

			isRunning = false;

			return;
		}
		else if (world.GetPoint(player.GetCoords()) == "D")
		{
			cout << "Arrrrgh... you’ve fallen down a pit." << endl;
			cout << "YOU HAVE DIED!" << endl;

			isRunning = false;

			return;
		}

		string moves = "You can move ";

		if (world.CheckNorth(player.GetCoords()))
		{
			moves += "N, ";
		}

		if (world.CheckSouth(player.GetCoords()))
		{
			moves += "S, ";
		}

		if (world.CheckEast(player.GetCoords()))
		{
			moves += "E, ";
		}

		if (world.CheckWest(player.GetCoords()))
		{
			moves += "W, ";
		}
		moves = moves.substr(0, moves.length() - 2);
		cout << moves << ": >";
	}
	else 
	{
		cout << "Closing game...";
	}
}

int main()
{
	bool validAction = new bool(true);
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
