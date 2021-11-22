#include <iostream>
#include <SDL.h>
#include <sdl_mixer.h>

using namespace std;

const int WIDTH = 800;
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
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            screen = SDL_GetWindowSurface(window);

            //Fill the surface green
            SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

            //Update the surface
            SDL_UpdateWindowSurface(window);
        }
    }

    //Event handler
    SDL_Event e;


    while (running)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
            }

            //Get keydown
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_0:
                    // Pause background music
                    break;
                case SDLK_1:
                    // Play Sound
                    break;
                case SDLK_2:
                    // Play Sound
                    break;
                case SDLK_3:
                    // Play Sound
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