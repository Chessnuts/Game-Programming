#include "PlayAdventure.h"
#include <conio.h>
#include <string>
#include <vector>
#include "Player.h"
#include <sstream>
#include <fstream>
#include <algorithm>

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
    if (!locations.empty())
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
        if ((str.size() != 0) && (str.at(0) == 'E'))
        {
            if (!locations.empty())
            {
                vector<string> details = split(str, '|');
                if (details.size() > 4)
                {
                    locations.back().entities.emplace_back(Entity{ split(details[1], ','), details[2], details[3],  split(details[4], ',') });
                    if ((details.size() > 6) && (details.at(5) == "I"))
                    {
                        vector<string> items = split(details.at(6), '/');
                        for (auto i : items)
                        {
                            vector<string> d = split(str, ':');
                            if (d.size() > 3)
                            {
                                locations.back().entities.back().Put(new Entity{ split(d[0], ','), d[1], d[2],  split(d[3], ',') });
                            }
                            else
                            {
                                locations.back().entities.back().Put(new Entity{ split(d[0], ','), d[1], d[2],  {" "} });
                            }
                        }
                    }
                }
                else
                {
                    locations.back().entities.emplace_back(Entity{ split(details[1], ','), details[2], details[3], {" "} });
                }
            }
        }
    }

    fs.close();

    //Get Location Connections
    fs.open(fileName, fstream::in);
    int i = 0;
    while (getline(fs, str))
    {
        if (!locations.empty())
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
                i++;
            }
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

        transform(input.begin(), input.end(), input.begin(), ::tolower);

        getline(cin, input);

        vector<string> command = split(input, ' ');
        

        if (command.at(0) == "quit")
        {
            loaded = false;
            state = STATES::QUIT;
        }
        else
        {
            cout << commandProcessor.Execute(command, player.location, &player) << endl;
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
        cout << endl << player.location->GetFullDescription() << endl;
    }
}