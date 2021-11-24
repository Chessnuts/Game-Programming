#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Modes.h"

extern SDL_Renderer* renderer;

class CollidingObject
{
private:
	int x_velocity;
	int y_velocity;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	SDL_Rect box;
public:
	int x;
	int y;

	bool isMoving;

	int SIZE = 80;
	int VELOCITY = 6;

	CollidingObject(bool moving, int start_x, int start_y);
	~CollidingObject() {};

	void Move(MODES mode);

	void Render(MODES mode);

	bool operator==(const CollidingObject &co);
};

