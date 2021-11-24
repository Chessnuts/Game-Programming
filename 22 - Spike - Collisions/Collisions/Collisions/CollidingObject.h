#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Modes.h"

class CollidingObject
{
private:
	int x;
	int y;

	int x_velocity;
	int y_velocity;

	
	SDL_Rect collider;
public:

	static const int SIZE = 20;
	static const int MAX_VELOCITY = 10;

	CollidingObject();

	void move(SDL_Rect& object, MODES mode);

	void render(MODES mode);
};

