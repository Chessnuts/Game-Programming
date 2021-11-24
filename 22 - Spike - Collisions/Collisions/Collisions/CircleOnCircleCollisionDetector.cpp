#include "CircleOnCircleCollisionDetector.h"

const int WIDTH = 800;
const int HEIGHT = 800;
extern CollidingObject* wall;

CircleOnCircleCollisionDetector::CircleOnCircleCollisionDetector()
{

}

bool CircleOnCircleCollisionDetector::CheckCollision(int *x, int *y, int *size)
{
    c2_rad = wall->SIZE / 2;
    c2_x = wall->x + c2_rad;
    c2_y = wall->y + c2_rad;

    c1_rad = *size / 2;
    c1_x = *x + c1_rad;
    c1_y = *y + c1_rad;

    if (*x < 0 || *y < 0 || *x + *size > WIDTH || *y + *size > HEIGHT)
    {
        return true;
    }

    int distSquared = (c2_x - c1_x)* (c2_x - c1_x) + (c2_y - c1_y) * (c2_y - c1_y);
    int radSquared = (c1_rad + c2_rad) * (c1_rad + c2_rad);
    if (distSquared < radSquared)
    {
        return true;
    }

    return false;
}
