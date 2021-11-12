
#include <iostream>

using namespace std;

class testClass
{
private:
    int anInt;
    char aChar;
    float aFloat;
public:
    testClass(int in, char ch, float fl) 
    {
        anInt = in;
        aChar = ch;
        aFloat = fl;
    };
    ~testClass() {};

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
    testClass myClass(in, ch, fl);

    myClass.ShowValues();

    return 0;
}


