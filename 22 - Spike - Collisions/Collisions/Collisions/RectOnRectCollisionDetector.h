#pragma once
#include "CollisionDetector.h"

using namespace std;

class RectOnRectCollisionDetector : public CollisionDetector
{
public:
	RectOnRectCollisionDetector() {};
	~RectOnRectCollisionDetector() {};
	bool CheckCollision(int x, int y, int size) override;
};

