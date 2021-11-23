// Task 17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;

bool success = true;
bool running = true;

SDL_Window* window = nullptr;
SDL_Surface* screen = nullptr;
SDL_Surface* background = nullptr;

SDL_Renderer* renderer = nullptr;
SDL_Texture* spriteSheet = nullptr;
SDL_Texture* bg = nullptr;

vector<SDL_Rect> objects = { { 0, 0, 64, 64 }, { 0, 0, 64, 64 }, { 0, 0, 64, 64 } };
vector<SDL_Rect> sprites = { { 0, 0, 64, 64 }, { 0, 64, 64, 64 }, { 0, 128, 64, 64 } };


SDL_Texture* loadTexture(std::string path)
{
    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

bool init()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("SDL Images", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == nullptr)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;

                }
                else
                {
                    //Get window surface
                    screen = SDL_GetWindowSurface(window);

                    if (screen == nullptr)
                    {
                        printf("screen could not be created! SDL Error: %s\n", SDL_GetError());
                        success = false;
                    }
                    else
                    {
                        SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 255, 255, 255));
                        SDL_UpdateWindowSurface(window);
                        //get background
                        background = IMG_Load("bg.png");
                        if (background == nullptr)
                        {
                            printf("SDL_image could not load background image! SDL_image Error: %s\n", IMG_GetError());
                            success = false;
                        }
                        else
                        {
                            bg = SDL_CreateTextureFromSurface(renderer, background);
                            if (bg == nullptr)
                            {
                                printf("Unable to create texture from %s! SDL Error: %s\n", "bg.png", SDL_GetError());
                                success = false;
                            }
                        }
                    }
                    

                    //render sprites
                    spriteSheet = loadTexture("tiles.png");
                    if (spriteSheet == nullptr)
                    {
                        printf("Failed to load sprite sheet!\n");
                        success = false;
                    }
                    
                }
            }
            
        }
    }

    return success;
}

void close()
{
    SDL_DestroyTexture(spriteSheet);
    spriteSheet = nullptr;


    SDL_FreeSurface(background);
    SDL_FreeSurface(screen);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    screen = nullptr;
    renderer = nullptr;
    background = nullptr;

    IMG_Quit();
    SDL_Quit();
}

int main()
{
    SDL_SetMainReady();
    success = init();
    
    SDL_Event e;
    bool bgOn = true;
    bool s1On = false;
    bool s2On = false;
    bool s3On = false;

    int range;

    while (running && success)
    {
        
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
            }

            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_0:
                    //turn bg on/off
                    bgOn = !bgOn;
                    break;
                case SDLK_1:
                    //turn bg on/off
                    s1On = !s1On;
                    if (s1On)
                    {
                        range = WIDTH - sprites.at(0).w + 1;
                        objects.at(0).x = rand() % range;
                        range = HEIGHT - objects.at(0).h + 1;
                        objects.at(0).y = rand() % range;
                    }
                    break;
                case SDLK_2:
                    //turn bg on/off
                    s2On = !s2On;
                    if (s2On)
                    {
                        range = WIDTH - sprites.at(1).w + 1;
                        objects.at(1).x = rand() % range;
                        range = HEIGHT - sprites.at(1).h + 1;
                        objects.at(1).y = rand() % range;
                    }
                    break;
                case SDLK_3:
                    //turn bg on/off
                    s3On = !s3On; 
                    if (s3On)
                    {
                        range = WIDTH - sprites.at(2).w + 1;
                        objects.at(2).x = rand() % range;
                        range = HEIGHT - sprites.at(2).h + 1;
                        objects.at(2).y = rand() % range;
                    }
                    break;
                }
            }
            //clear screen
            SDL_RenderClear(renderer);
           

            //background
            if (bgOn)
            {
                SDL_RenderCopy(renderer, bg, nullptr, nullptr);
            }
            
            //srpite 1
            if (s1On)
            {
                SDL_RenderCopy(renderer, spriteSheet, &sprites.at(0), &objects.at(0));
            }
            //sprite 2
            if (s2On)
            {
                SDL_RenderCopy(renderer, spriteSheet, &sprites.at(1), &objects.at(1));
            }
            //sprite 3
            if (s3On)
            {
                SDL_RenderCopy(renderer, spriteSheet, &sprites.at(2), &objects.at(2));
            }

            SDL_RenderPresent(renderer);
            
        }
    }

    close();

    return 0;
}

