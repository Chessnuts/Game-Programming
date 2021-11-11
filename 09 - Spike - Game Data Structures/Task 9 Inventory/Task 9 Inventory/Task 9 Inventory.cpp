// Task 9 Inventory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IdentifiableObject.h"
#include "GameObject.h"
#include "Item.h"
#include "Inventory.h"

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
    GameObject go({ "game object", "an object" }, "game object", "this is a game object");

    if (go.AreYou("an object"))
    {
        cout << "ids work" << endl;
    }

    cout << go.GetName() << endl;

    cout << go.GetShortDescription() << endl;

    cout << go.GetFullDescription() << endl;
}

void ItemTest()
{
    //same as gameobject, basically just testing that the inheritance works
    Item it({ "item", "an item" }, "item", "this is an item");

    if (it.AreYou("an item"))
    {
        cout << "ids work" << endl;
    }

    cout << it.GetName() << endl;

    cout << it.GetShortDescription() << endl;

    cout << it.GetFullDescription() << endl;
}

void InventoryTest()
{
    Inventory in;
    Item it({ "item 1", "an item" }, "item 1", "this is an item");
}

int main()
{
    identifiableObjectTest();
    GameObjectTest();
    ItemTest();


    cout << "finished!!" << endl;

    return 0;
}
