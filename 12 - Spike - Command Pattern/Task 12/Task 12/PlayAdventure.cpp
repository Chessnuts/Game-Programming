#include "PlayAdventure.h"
#include <conio.h>
#include <string>
#include <vector>
#include "Player.h"
#include <sstream>
#include <fstream>
using namespace std;

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

void PlayAdventure::LoadAdventure(string fileName)
{
    if (locations.size() > 0)
    {
        locations.clear();
    }

    fstream fs;
    string str;

    fs.open(fileName, fstream::in);

    //Get Locations 
    while (getline(fs, str))
    {
        if ((str.size() != 0) && (str.at(0) == 'L'))
        {
            vector<string> details = split(str, '|');

            locations.push_back(Location{ split(details[1], ','), details[2], details[3] });
        }
    }

    fs.close();

    for (auto l : locations)
    {
        cout << l.FirstId() << endl;
    }

    //Get Location Connections
    fs.open(fileName, fstream::in);
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

    //Player
    player = Player({ "Fred", "It's you!", locations.at(0) });

    loaded = true;
}

void PlayAdventure::Update()
{
    if (!loaded)
    {
        char input = _getch();

        switch (input)
        {
        case '1':
            LoadAdventure("test.txt");
            break;

        case '2':
            state = STATES::MAIN_MENU;
            break;

        default:
            cout << "Try again" << endl;
        }
    }
    else
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
            loaded = false;
            state = STATES::QUIT;
        }
    }
    
}

void PlayAdventure::Render()
{
    if (!loaded)
    {
        cout << "\t" << "Select Adventure" << endl;
        cout << "\t" << "1. Test World" << endl;
        cout << "\t" << "2. Return to main menu" << endl;
    }
    else
    {
        cout << player.location->GetFullDescription() << endl;
    }
}