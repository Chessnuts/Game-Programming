// Messaging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "BlackBoard.h"
#include "Entity.h"
#include "Player.h"

using namespace std;

bool running = true;

void Update(vector<Entity*> &entities)
{
    cout << "Debug: update called" << endl;
    for (auto e : entities)
    {
        e->Update();
    }
}

void Render(vector<Entity*>& entities)
{
    cout << "Debug: render called" << endl;
    for (auto e : entities)
    {
        e->Render();
    }
}

int main()
{


    BlackBoard blackboard;

    vector<Entity*> entities;

    Player player = Player({ "Fred", "It's you!", &blackboard });
    entities.push_back(&player);

    cout << "Debug: game loaded" << endl;

    while (running)
    {
        Render(entities);
        Update(entities);
    }
    return 0;
}

