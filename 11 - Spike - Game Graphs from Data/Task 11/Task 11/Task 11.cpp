
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "IdentifiableObject.h"
#include "GameObject.h"
#include "Location.h"

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

int main()
{
    fstream fs;
    string str;

    vector<Location> locations;

    fs.open("Adventure.txt", fstream::in);

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

    fs.open("Adventure.txt", fstream::in);
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

    while (!running)
    {

    }

    return 0;
}


