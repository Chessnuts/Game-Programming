// GridWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Player.h"
#include "World.h"
#include <algorithm>

using namespace std;

string Input() 
{
	string i;
	cin >> i;
	transform(i.begin(), i.end(), i.begin(), ::toupper);
	return i;
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
