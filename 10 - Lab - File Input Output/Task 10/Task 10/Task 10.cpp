
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "json.hpp"

// for convenience
using json = nlohmann::json;

using namespace std;

struct Test
{
    int anInt;
    char aChar;
    float aFloat;

    void ShowValues()
    {
        cout << anInt << endl;
        cout << aChar << endl;
        cout << aFloat << endl;
    };
};

vector<string> split(string str)
{
    stringstream ss(str);
    vector<string> result;

    while (ss.good())
    {
        string s;
        getline(ss, s, ':');
        result.push_back(s);
    }
    return result;
}

int main()
{
    
    if (false)
    {
        int in;
        char ch;
        float fl;

        fstream fs;
        fs.open("test1.bin", fstream::in | fstream::binary);

        fs.read(reinterpret_cast<char*>(&in), 4);
        fs.read(reinterpret_cast<char*>(&ch), 1);
        fs.read(reinterpret_cast<char*>(&fl), 4);

        fs.close();

        Test myData{ in, ch, fl };

        myData.ShowValues();
    }

    if (false)
    {
        int in;
        char ch;
        float fl;

        Test myData{ in, ch, fl };

        //open in write mode
        fstream fs;
        fs.open("test1.bin", fstream::out | fstream::binary | fstream::trunc);

        //write data
        fs.write(reinterpret_cast<const char*>(&myData.anInt), sizeof(myData.anInt));
        fs.write(reinterpret_cast<const char*>(&myData.aChar), sizeof(myData.aChar));
        fs.write(reinterpret_cast<const char*>(&myData.aFloat), sizeof(myData.aFloat));

        //close file
        fs.close();
    }
    
    if (false)
    {
        fstream fs;
        string str;

        fs.open("test2.txt", fstream::in);

        while (getline(fs, str))
        {
            if ((str.size() != 0) && (str.at(0) != '#'))
            {
                for (auto s : split(str))
                {
                    cout << s << endl;
                }
            }
        }

        fs.close();
    }

    if (true)
    {
        fstream fs;
        
        fs.open("test3.json", fstream::in);
        json jf = json::parse(fs);


        cout << "exp: " << jf["exp"] << endl;
        cout << "health: " << jf["health"] << endl;
        cout << "jsonType: " << jf["jsonType"] << endl;
        cout << "level: " << jf["level"] << endl;
        cout << "name: " << jf["name"] << endl;
        cout << "uuid: " << jf["uuid"] << endl;

        fs.close();
    }

    cout << endl << "done" << endl;
    
    return 0;
};
