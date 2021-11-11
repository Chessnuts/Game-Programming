// Task 9 Inventory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IdentifiableObject.h"
#include "GameObject.h"


using namespace std;

void identifiableObjectTest()
{
    IdentifiableObject io({ "identifier 1", "identifier 2", "identifier 3" });

    cout << io.FirstId() << endl;

    if (io.AreYou("identifier 1"))
    {
        cout << "i am identifier 1" << endl;
    }

    if (io.AreYou("identifier 2"))
    {
        cout << "i am identifier 2" << endl;
    }

    if (io.AreYou("identifier 3"))
    {
        cout << "i am identifier 3" << endl;
    }

    if (!io.AreYou("identifier 4"))
    {
        cout << "i am not identifier 4" << endl;
    }

    io.AddIdentifier("identifier 4");
    
    if (io.AreYou("identifier 4"))
    {
        cout << "i am now identifier 4" << endl;
    }
}

void GameObjectTest()
{

}

void ItemTest()
{

}

void InventoryTest()
{

}

int main()
{
    identifiableObjectTest();

    return 0;
}
