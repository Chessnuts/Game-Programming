// Collisions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "CollisionChecker.h"
#include "CollidingObject.h"
#include "Modes.h"

using namespace std;

bool running = true;
const int WIDTH = 800;
const int HEIGHT = 800;

CollisionChecker collisionChecker;

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;

CollidingObject* object = nullptr;;
CollidingObject* wall = nullptr;;

bool Init()
{
	object = new CollidingObject({ true, 1, 1 });
	wall = new CollidingObject({ false, 320, 320 });
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == nullptr)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}

	return success;
}

void Close()
{	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;
	delete object;
	delete wall;
	object = nullptr;
	wall = nullptr;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main()
{
	SDL_SetMainReady();
	bool success = Init();

	MODES mode = MODES::SQUARE;

	SDL_Event e;

	//While application is running
	while (running && success)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_1:
					mode = MODES::SQUARE;
					break;
				case SDLK_2:
					mode = MODES::CIRCLE;
					break;
				}
			}
			
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);


		object->Move(mode);

		object->Render(mode);
		wall->Render(mode);

		SDL_RenderPresent(renderer);

	}
	Close();

	return 0;
}
