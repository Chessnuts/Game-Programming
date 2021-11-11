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
    Item it1({ "item 1", "an item" }, "item 1", "this is an item");
    Item it2({ "item 2", "an item" }, "item 2", "this is an item");

    if (!in.HasItem("item 2"))
    {
        cout << "does not have the item" << endl;
    }

    cout << in.ItemList() << endl;

    in.Put(&it1);

    if (in.HasItem("item 1"))
    {
        cout << "it has the item we put in" << endl;
    }
    if (!in.HasItem("item 2"))
    {
        cout << "does not have the other item" << endl;
    }

    cout << in.ItemList() << endl;

    in.Put(&it2);

    if (in.HasItem("item 1"))
    {
        cout << "it has the item we put in" << endl;
    }
    if (in.HasItem("item 2"))
    {
        cout << "and it does have this one" << endl;
    }

    cout << in.ItemList() << endl;

    cout << in.Fetch("item 1")->GetShortDescription() << endl;
    cout << in.Fetch("item 2")->GetShortDescription() << endl;

    in.Take("item 1");

    if (!in.HasItem("item 1"))
    {
        cout << "we took this item out" << endl;
    }
    if (in.HasItem("item 2"))
    {
        cout << "and it does have this one" << endl;
    }

    cout << in.ItemList() << endl;

}

int main()
{
    identifiableObjectTest();
    GameObjectTest();
    ItemTest();
    InventoryTest();

    cout << "finished!!" << endl;

    return 0;
}
