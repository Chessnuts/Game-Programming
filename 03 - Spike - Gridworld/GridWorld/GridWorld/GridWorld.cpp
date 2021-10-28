// GridWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "World.cpp"
#include "Player.cpp"

using namespace std;

bool isRunning = true;

void Init() 
{

}

void Input() 
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
	Player player;
	World world;

	cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for You!" << endl;
	cout << "Valid commands: N, S, E and W for direction. Q to quit the game." << endl << endl;
	
	while (isRunning)
	{
		Input();
		Update();
		Render();
	};

	return 0;
}
