// Task 9 Inventory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IdentifiableObject.h"
#include "GameObject.h"

using namespace std;

int main()
{
    IdentifiableObject io({ "1", "2", "3" });

    cout << io.FirstId() << endl;

    return 0;
}
