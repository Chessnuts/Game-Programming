#pragma once
#include<vector>
#include"CollidingObject.h"

using namespace std;

class CollisionDetector
{
public:
	CollisionDetector() {};
	~CollisionDetector() {};
	virtual bool CheckCollision(int x, int y, int size) = 0;
};

