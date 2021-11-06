// Task 8 Zorkish States.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "State.h"

using namespace std;

void initializeGame()
{

}

string Input()
{

}

void Update()
{

}

void Render()
{

}

int main()
{
    bool running = true;
    string input;
    int currentState = 0;
    //MainMenu mainMenu;
    //Adventure adventure;
    //Help help;
    //About about;
    //Quit quit;

    State testState1;
    State testState2;

    State state[2] = {testState1, testState2};

    initializeGame();

    while (running)
    {
        //player input
        input = Input();

        //update function
        Update();

        //render
        Render();
    }

    return 0;
}
