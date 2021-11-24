#pragma once
#include "Modes.h"
#include "CircleOnCircleCollisionDetector.h"
#include "RectOnRectCollisionDetector.h"

using namespace std;

class CollisionChecker
{
private:
	CollisionDetector* detectionMode = nullptr;
	CircleOnCircleCollisionDetector c_on_c;
	RectOnRectCollisionDetector r_on_r;
public:
	CollisionChecker() {};
	~CollisionChecker() {};

	bool CheckForCollision(MODES mode, int* x, int* y, int* size);
};

