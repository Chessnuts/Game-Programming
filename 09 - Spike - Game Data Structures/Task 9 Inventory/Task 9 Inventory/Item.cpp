#include "Item.h"

Item::Item(string n, string d) {
    name = n;
    description = d;
}

string Item::GetName() {
    return name;
}


string Item::GetKey() {
    return key;
}


string Item::GetDescription() {
    return description;
}