
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

    if (false)
    {
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

    return 0;
}