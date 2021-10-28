// GridWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Player.h"
#include "World.h"

using namespace std;

string Input() 
{
	return " ";
}

void Update()
{

}

void Render()
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
	
	cout << player.GetCoords().x << " " << player.GetCoords().y << endl;
	cout << world.GetPoint(player.GetCoords()) << endl;

	/*
	while (isRunning)
	{
		input = Input();
		Update();
		Render();
	};
	*/
	return 0;
}
