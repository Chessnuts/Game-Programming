#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Modes.h"
#include "CollisionChecker.h"

extern CollisionChecker collisionChecker;
extern SDL_Renderer* renderer;

class CollidingObject
{
private:
	int x_velocity;
	int y_velocity;

	SDL_Rect box;
public:
	int x;
	int y;

	bool isMoving;

	static const int SIZE = 20;
	static const int VELOCITY = 10;

	CollidingObject(bool moving, int start_x, int start_y);

	void Move(SDL_Rect& object, MODES mode);

	void Render(MODES mode);

	bool operator==(const CollidingObject &co);
};

