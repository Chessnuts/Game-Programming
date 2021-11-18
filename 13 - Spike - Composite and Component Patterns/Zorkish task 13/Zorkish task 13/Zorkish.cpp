// Zorkish.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Zorkish.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "State.h"
#include "StateManager.h"
#include "MainMenu.h"
#include "Welcome.h"
#include "States.h"

using namespace std;
STATES state = STATES::WELCOME;

int main()
{
    StateManager manager;


    while (manager.Running())
    {
        manager.Current()->Render();
        manager.Current()->Update();
    }

    return 0;
}
