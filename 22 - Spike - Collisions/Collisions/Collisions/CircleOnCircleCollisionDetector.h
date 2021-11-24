#pragma once
#include "CollisionDetector.h"
class CircleOnCircleCollisionDetector :
    public CollisionDetector
{
public:
    CircleOnCircleCollisionDetector() {};
    ~CircleOnCircleCollisionDetector() {};
    bool CheckCollision(int x, int y, int size) override;
};

