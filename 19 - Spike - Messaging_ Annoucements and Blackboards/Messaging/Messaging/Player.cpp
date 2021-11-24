#include "Player.h"
#include <iostream>
#include <sstream>
#include "Item.h"

using namespace std;

extern bool running;

vector<string> split(string str, char splitter)
{
    stringstream ss(str);
    vector<string> result;

    while (ss.good())
    {
        string s;
        getline(ss, s, splitter);
        result.push_back(s);
    }
    if (result.size() == 0)
    {
        result.push_back(str);
    }
    return result;
}

Player::Player(string n, string d, BlackBoard* bb) : Entity({ "me", "inventory", "player" }, n, d, bb)
{
    cout << "Debug: Player Constructed" << endl;
}


string Player::GetShortDescription()
{
	return GameObject::GetShortDescription();
}

string Player::GetDescription()
{
	return GameObject::GetDescription();
}

string Player::GetFullDescription()
{
	return GetDescription() + "\n You are carrying: \n" + inventory.ItemList();
}

void Player::Update()
{
    //cout << "Debug: Player update" << endl;
    output = "";
    string input;
    getline(cin, input);

    vector<string> command = split(input, ' ');
    vector<Message> messages = blackBoard->GetMessages({ "player" });

    for (auto m : messages)
    {
        if (m.message == "receive item")
        {
            if (m.data != nullptr)
            {
                try
                {
                    Item* it = reinterpret_cast<Item*>(m.data);

                    inventory.Put(it);

                    output += "You got a " + it->GetName() + " from " + m.from + "!\n";
                }
                catch (...)
                {
                    output += GetName() + ": I can't do anything with this...\n";
                    delete m.data;
                }
            }
            blackBoard->RemoveMessage(m);
        }
    }

    if (!input.empty())
    {
        if (command.at(0) == "quit")
        {
            output += "Quitting game";
            running = false;
        }
        else if (command.at(0) == "open")
        {
            if (command.size() > 1)
            {
                blackBoard->AddMessage({"player", command.at(1), "open"});
                output += "Requested to open " + command.at(1) + ".\n";
            }
            else
            {
                output += "What would you like to open?\n";
            }
        }
        else if (command.at(0) == "say")
        {
            if (command.size() > 1 && command.at(1) == "hi")
            {
                blackBoard->AddMessage({ "player", "npc", "greeting", &name });
                output += "You said hi\n";
            }
            else
            {
                output += "What would you like to say?\n";
            }
        }
        else if (command.at(0) == "purchase")
        {
            if (command.size() > 1)
            {
                string* n = new string;
                *n = command.at(1);
                blackBoard->AddMessage({ "player", "npc", "purchase", n });
                output += "Requested to purchase " + command.at(1) + ".\n";
            }
            else
            {
                output += "What would you like to purchase?\n";
            }
        }
        else if (command.at(0) == "inventory")
        {
            output += GetFullDescription() + "\n";
        }
    }
}

void Player::Render()
{
    cout << output << endl;
}
