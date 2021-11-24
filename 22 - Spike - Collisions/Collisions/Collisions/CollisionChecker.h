#pragma once
#include "Modes.h"
#include "CollisionDetector.h"
#include "CircleOnCircleCollisionDetector.h"
#include "RectOnRectCollisionDetector.h"

class CollisionChecker
{
private:
	CollisionDetector* detectionMode = nullptr;
	CircleOnCircleCollisionDetector c_on_c;
	RectOnRectCollisionDetector r_on_r;
public:
	CollisionChecker() {};
	~CollisionChecker() {};

	bool CheckForCollision(MODES mode, int x, int y, int size);
};

