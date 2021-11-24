#include "CollidingObject.h"

// Function from: https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl
void DrawCircle(SDL_Renderer* renderer, int centreX, int centreY, int radius)
{
    const int32_t diameter = (radius * 2);

    int x = (radius - 1);
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

CollidingObject::CollidingObject(bool moving, int start_x, int start_y)
{
    isMoving = moving;

    x = 0;
    y = 0;

    x_velocity = VELOCITY;
    y_velocity = VELOCITY;
}

void CollidingObject::Move(SDL_Rect& object, MODES mode)
{

}

void CollidingObject::Render(MODES mode)
{

}

bool CollidingObject::operator==(const CollidingObject& co)
{
    return (&box == &co.box && x == co.x && y == co.y);
}
