// Collisions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "CollidingObject.h"
#include "Modes.h"

using namespace std;

bool running = true;
const int WIDTH = 800;
const int HEIGHT = 800;

vector<CollidingObject> objects = { {true, 0, 0}, {false, 400, 400}};

int main()
{

	SDL_Event e;

	//While application is running
	while (running)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				running = false;
			}

		}

	}

	return 0;
}
