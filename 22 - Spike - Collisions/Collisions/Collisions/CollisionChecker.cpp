#include "CollisionChecker.h"

bool CollisionChecker::CheckForCollision(MODES mode, int *x, int *y, int *size)
{
    if (mode == MODES::SQUARE)
    {
        detectionMode = &r_on_r;
    }
    else if (mode == MODES::CIRCLE)
    {
        detectionMode = &c_on_c;
    }
    return detectionMode->CheckCollision(x, y, size);
}
