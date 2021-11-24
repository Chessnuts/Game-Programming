#include "RectOnRectCollisionDetector.h"

const int WIDTH = 800;
const int HEIGHT = 800;
extern CollidingObject *wall;



bool RectOnRectCollisionDetector::collision(int* x, int* y, int* size)
{
    al = *x;
    ar = *x + *size;
    at = *y;
    ab = *y + *size;

    bl = wall->x;
    br = wall->x + wall->SIZE;
    bt = wall->y;
    bb = wall->y + wall->SIZE;

    if (ab <= bt)
        return false;
    if (at >= bb)
        return false;
    if (ar <= bl)
        return false;
    if (al >= br)
        return false;

    return true;
}

RectOnRectCollisionDetector::RectOnRectCollisionDetector()
{

}

bool RectOnRectCollisionDetector::CheckCollision(int* x, int* y, int* size)
{
    if (*x < 0 || *y < 0 || *x + *size > WIDTH || *y + *size > HEIGHT)
    {
        return true;
    }
    return collision(x, y, size);
 

    return false;
}
