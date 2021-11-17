
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include "IdentifiableObject.h"
#include "GameObject.h"
#include "Location.h"
#include "Player.h"



using namespace std;

bool running = true;



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
void Update(Player &player) 
{
    string input;
    getline(cin, input);

    vector<string> command = split(input, ' ');

    if (command.at(0) == "go")
    {
        //cout << "go command" << endl;
        //for (auto s : command)
        //{
        //    cout << s << endl;
        //}
        if (command.size() > 1)
        {
            //cout << "argument found" << endl;
            if (player.location->GetConnection(command.at(1)) != nullptr)
            { 
                cout << "moving to : " << player.location->GetConnection(command.at(1))->GetName() << endl;
                player.MoveTo(player.location->GetConnection(command.at(1)));
            }
        }
    }
    else if (command.at(0) == "quit")
    {
        running = false;
    }
}

void Render(Player &player)
{
    if (!running)
    {
        cout << "Quitting game" << endl;
        return;
    }
    cout << player.location->GetFullDescription() << endl;
}

int main(int argc, char* argv[])
{
    fstream fs;
    string str;

    vector<Location> locations;

    fs.open(argv[1], fstream::in);

    while (getline(fs, str))
    {
        if ((str.size() != 0) && (str.at(0) == 'L'))
        {
            vector<string> details = split(str, '|');

            locations.push_back(Location{split(details[1], ','), details[2], details[3]});
        }
    }

    fs.close();

    for (auto l : locations)
    {
        cout << l.FirstId() << endl;
    }

    fs.open(argv[1], fstream::in);
    int i = 0;
    while (getline(fs, str))
    {

        if ((str.size() != 0) && (str.at(0) == 'C'))
        {
            for (auto s : split(str, '|'))
            {
                if (s != "C")
                {
                    vector<string> pair = split(s, ',');

                    for (auto& l : locations)
                    {
                        if (l.AreYou(pair[1]))
                        {
                            locations[i].AddConnection(pair[0], &l);
                        }
                    }
                }
            }
            cout << i << endl;
            i++;
        }
    }

    fs.close();

    for (auto l : locations)
    {
        cout << l.GetFullDescription() << endl;
    }

    cout << "<< game test >>" << endl;


    Player player({"Fred", "It's you!", locations.at(0)});

    cout << player.location->GetFullDescription() << endl;

    while (running)
    {
        Update(player);
        Render(player);
    }

    return 0;
}


