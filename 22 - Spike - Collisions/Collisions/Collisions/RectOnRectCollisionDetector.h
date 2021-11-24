#pragma once
#include "CollisionDetector.h"

using namespace std;

class RectOnRectCollisionDetector : public CollisionDetector
{
private:
	int al;
	int ar;
	int at;
	int ab;

	int bl;
	int br;
	int bt;
	int bb;
public:
	RectOnRectCollisionDetector();
	~RectOnRectCollisionDetector() {};
	bool CheckCollision(int* x, int* y, int* size);
	bool collision(int* x, int* y, int* size);
};

