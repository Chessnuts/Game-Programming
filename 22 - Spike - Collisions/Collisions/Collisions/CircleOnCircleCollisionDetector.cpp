#include "CircleOnCircleCollisionDetector.h"

extern const int WIDTH;
extern const int HEIGHT;
extern vector<CollidingObject> objects;

bool CircleOnCircleCollisionDetector::CheckCollision(int x, int y, int size)
{
    if (x < 0 || y < 0 || x + size > WIDTH || y + size > HEIGHT)
    {
        return true;
    }

    for (auto ob : objects)
    {
        if (x != ob.x && y != ob.y)
        {
            int c1_mid = size / 2;
            int c1_rsq = c1_mid ^ 2;
            int c1_x = x + c1_mid;
            int c1_y = y + c1_mid;

            int c2_mid = size / 2;
            int c2_rsq = c2_mid ^ 2;
            int c2_x = x + c2_mid;
            int c2_y = y + c2_mid;

            if (((c1_x - c2_x) ^ 2 + (c1_y - c2_y) ^ 2) < (c1_rsq + c2_rsq))
            {
                return true;
            }
        }
    }

    return false;
}
