
#include <iostream>
#include <SDL.h>

using namespace std;

const int WIDTH = 600;
const int HEIGHT = 800;
bool running = true;

int main(int argc, char* args[])
{
    SDL_Window* window = nullptr;

    SDL_Surface* screen = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    else
    {
        //Create window
        window = SDL_CreateWindow("SDL DEMO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            screen = SDL_GetWindowSurface(window);

            //Fill the surface green
            SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 0, 255, 26));

            //Update the surface
            SDL_UpdateWindowSurface(window);
        }
    }
    
    //Event handler
    SDL_Event e;


    while (running)
    {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            //User requests quit
            if (e.type == SDL_QUIT)
            {
                running = false;
            }

            //Get keydown
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                    case SDLK_r:
                        SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, rand() % 256, rand() % 256, rand() % 256));
                        
                        SDL_UpdateWindowSurface(window); //it's just a demo and this is the only thing that's updated so no need to call update all the time
                        break;
                }
            }
        }
    }

    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}