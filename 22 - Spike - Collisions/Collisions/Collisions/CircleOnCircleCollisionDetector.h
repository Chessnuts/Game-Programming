#pragma once
#include "CollisionDetector.h"

using namespace std;

class CircleOnCircleCollisionDetector : public CollisionDetector
{
private:
    int c1_rad;
    int c1_rsq;
    int c1_x;
    int c1_y;

    int c2_rad;
    int c2_rsq;
    int c2_x;
    int c2_y;
public:
    CircleOnCircleCollisionDetector();
    ~CircleOnCircleCollisionDetector() {};
    bool CheckCollision(int* x, int* y, int* size) override;
};

