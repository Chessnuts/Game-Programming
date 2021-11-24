// Collisions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CollidingObject.h"
#include "Modes.h"

bool running = true;

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
