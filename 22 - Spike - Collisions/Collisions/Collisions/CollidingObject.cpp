#include "CollidingObject.h"
#include "CollisionChecker.h"
#include <iostream>

extern CollisionChecker collisionChecker;

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

    x = start_x;
    y = start_y;

    x_velocity = VELOCITY;
    y_velocity = VELOCITY;

    box = { x, y, SIZE, SIZE };
}

void CollidingObject::Move(MODES mode)
{
    
    if (isMoving)
    {
        x += x_velocity;
        box.x = x;

        if (collisionChecker.CheckForCollision(mode, &x, &y, &SIZE))
        {
            c1 = rand() % 256;
            c2 = rand() % 256;
            c3 = rand() % 256;
            
            cout << "collision detected" << endl;
            x -= x_velocity;
            x_velocity *= -1;
            box.x = x;
        }

        y += y_velocity;
        box.y = y;

        if (collisionChecker.CheckForCollision(mode, &x, &y, &SIZE))
        {

            c1 = rand() % 256;
            c2 = rand() % 256;
            c3 = rand() % 256;

            cout << "collision detected" << endl;
            y -= y_velocity;
            y_velocity *= -1;
            box.y = y;
        }

        SDL_SetRenderDrawColor(renderer, c1, c2, c3, 255);
    }
}

void CollidingObject::Render(MODES mode)
{
    if (mode == MODES::SQUARE)
    {
        SDL_RenderDrawRect(renderer, &box);
    }
    else if (mode == MODES::CIRCLE)
    {
        int radius = SIZE / 2;
        DrawCircle(renderer, x + radius, y + radius, radius);
    }
    else
    {
        SDL_RenderDrawRect(renderer, &box);
    }
}

bool CollidingObject::operator==(const CollidingObject& co)
{
    return (&box == &co.box && x == co.x && y == co.y);
}
