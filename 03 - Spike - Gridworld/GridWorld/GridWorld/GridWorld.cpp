// GridWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "World.cpp"
#include "Player.cpp"
#include "string"

using namespace std;

string Input() 
{

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
	Player player = Player(world.GetStart());

	cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for You!" << endl;
	cout << "Valid commands: N, S, E and W for direction. Q to quit the game." << endl << endl;
	
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
