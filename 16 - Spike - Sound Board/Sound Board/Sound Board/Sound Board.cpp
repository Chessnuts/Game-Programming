#include <iostream>
#include <SDL.h>
#include <sdl_mixer.h>
#include <stdio.h>
#include <string>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;
bool running = true;
//The music that will be played
Mix_Music* jazz_music = nullptr;

//The sound effects that will be used
Mix_Chunk* gun_SE = nullptr;
Mix_Chunk* explode_SE = nullptr;
Mix_Chunk* pop_SE = nullptr;

SDL_Window* window = nullptr;

SDL_Surface* screen = nullptr;
bool success = true;

bool loadSounds()
{
    
    //Load music
    jazz_music = Mix_LoadMUS("jazz-loop-7163.wav");
    if (jazz_music == nullptr)
    {
        printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    
    //Load sound effects
    gun_SE = Mix_LoadWAV("LASRGun_Star wars blaster 2 (ID 1758)_BSB.wav");
    if (gun_SE == nullptr)
    {
        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    explode_SE = Mix_LoadWAV("FRWKRec_Firecracker with wick 3 (ID 1139)_BSB.wav");
    if (explode_SE == nullptr)
    {
        printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    pop_SE = Mix_LoadWAV("FOODGware_Cap cider 3 (ID 1860)_BSB.wav");
    if (pop_SE == nullptr)
    {
        printf("Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
    return success;
}

void close()
{
    //Free the sound effects
    Mix_FreeChunk(gun_SE);
    Mix_FreeChunk(explode_SE);
    Mix_FreeChunk(pop_SE);
    gun_SE = nullptr;
    explode_SE = nullptr;
    pop_SE = nullptr;

    //Free the music
    Mix_FreeMusic(jazz_music);
    jazz_music = nullptr;

    //Destroy window    
    SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
    window = nullptr;
    screen = nullptr;

    //Quit SDL subsystems
    Mix_Quit();
    SDL_Quit();
}

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        int rate = 44100;
        Uint16 format = MIX_DEFAULT_FORMAT;
        int channleNo = 2;
        int buffers = 2048;
        if (Mix_OpenAudio(rate, format, channleNo, buffers) < 0)
        {
            printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
            success = false;
        }

        //Create window
        window = SDL_CreateWindow("SDL DEMO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            screen = SDL_GetWindowSurface(window);

            //Fill the surface green
            SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 255, 255, 255));

            //Update the surface
            SDL_UpdateWindowSurface(window);
        }

        success = loadSounds();
    }



    //Event handler
    SDL_Event e;


    while (running && success)
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
                    //play pause music
                    if (Mix_PlayingMusic() == 0)
                    {
                        //Play the music
                        Mix_PlayMusic(jazz_music, -1);
                    }
                    //If music is being played
                    else
                    {
                        //If the music is paused
                        if (Mix_PausedMusic() == 1)
                        {
                            //Resume the music
                            Mix_ResumeMusic();
                        }
                        //If the music is playing
                        else
                        {
                            //Pause the music
                            Mix_PauseMusic();
                        }
                    }
                    break;
                case SDLK_1:
                    // Play Sound
                    Mix_PlayChannel(-1, gun_SE, 0);
                    break;
                case SDLK_2:
                    // Play Sound
                    Mix_PlayChannel(-1, explode_SE, 0);
                    break;
                case SDLK_3:
                    // Play Sound
                    Mix_PlayChannel(-1, pop_SE, 0);
                    break;
                }
            
            }
        }
    }

    close();

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}