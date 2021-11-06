// Task 8 Zorkish States.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "State.h"

using namespace std;

int main()
{
    StateManager manager;

    while (manager.running())
    {
        manager.render();
        manager.update();
    }

    return 0;
}
