
#include <iostream>
#include <fstream>

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

int main()
{
    int in = 6;
    char ch = 'a';
    float fl = 2.2;
    Test myData{ in, ch, fl };

    myData.ShowValues();

    //open in write mode
    fstream fs;
    fs.open("test1.bin", fstream::out | fstream::binary);

    //write data
    fs << myData.anInt;
    fs << myData.aChar;
    fs << myData.aFloat;

    //close file
    fs.close();

    return 0;
}