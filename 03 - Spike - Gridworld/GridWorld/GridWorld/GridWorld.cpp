// GridWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

using namespace std;

bool isRunning = true;

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
