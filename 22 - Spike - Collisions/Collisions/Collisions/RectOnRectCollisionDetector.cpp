#include "RectOnRectCollisionDetector.h"

extern const int WIDTH;
extern const int HEIGHT;
extern vector<CollidingObject> objects;

bool collision(int x, int y, int size, CollidingObject ob)
{
    int al = x;
    int ar = x + size;
    int at = y;
    int ab = y + size;

    int bl = ob.x;
    int br = ob.x + ob.SIZE;
    int bt = ob.y;
    int bb = ob.y + ob.SIZE;

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

bool RectOnRectCollisionDetector::CheckCollision(int x, int y, int size)
{
    if (x < 0 || y < 0 || x + size > WIDTH || y + size > HEIGHT)
    {
        return true;
    }

    bool result = false;

    for (auto ob : objects)
    {
        if (x != ob.x && y != ob.y)
        {
            return collision(x, y, size, ob);
        }
    }
    return false;
}
