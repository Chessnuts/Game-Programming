#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


/*
Create a function that accepts at least two values (simple parameter values, not user 
input), prints the values to screen, and returns nothing.Call this function from your
main.
*/
void MethodOne(string a, string b) 
{
	cout << a << ' ' << b << endl;
};

/*
 Create a function that accepts one value, alters it, and returns it (simple value). Call
this function from main, and print the returned value.
*/
int MethodTwo(int v) 
{
	v++;
	return v;
};

/*
 Declare a pointer to a variable, and demonstrate the setting and reading of the value
in the variable using the pointer.
*/
void MethodThree()
{
	int v = 5;
	int* p;

	p = &v;

	cout << v << endl;
	cout << p << endl;
	cout << *p << endl;

	*p += 2;

	cout << v << endl;
	cout << *p << endl;

};

/*
 Create a function that uses a for loop to print all odd numbers between 0 and 20 on a
single text line of text output, formatted with spaces. Call this from main.
*/
void MethodFour()
{
	for (int i = 0; i++; i > 20) 
	{
		cout << i << endl;
	}
};

/*
 Create a function that creates a 1-dimensional array of 5 integers, then fill the array
with random int values, print the contents of the array to the screen. Call from main
*/
void MethodFive()
{
	int a[5];

	for (int i = 0; i++; i > 5)
	{
		a[i] = rand() % 100;
	};

	for (int i = 0; i++; i > 5)
	{
		cout << a[i] << endl;
	};

};

/*
 Split the line of text, such as “this has spaces in it”, by spaces, and show each part to
screen.
*/
void MethodSix()
{
	string s = "this has spaces in it";
	cout << s << endl;

	vector<string> words{};

	istringstream iss(s);
	copy(std::istream_iterator<string>(iss),
		std::istream_iterator<string>(),
		std::ostream_iterator<string>(cout, "\n"));

};

/*
 Declare a simple class that has at least one private variable, one public variable, and
one public method. Create an instance of the class, and demonstrate its use.
*/
class MyClass 
{
	private: string thisIsPrivate = "This is a private string.";
	public: string thisIsPublic = "This is a public string";
	
	public: int Addtwenty(int n)
	{
		return n + 20;
	};

};

int main()
{
	MyClass obj;

	string a = "Hello";
	string b = "World";

	int v = 1;

	MethodOne(a, b);

	cout << v << endl;
	v = MethodTwo(v);
	cout << v << endl;

	MethodThree();

	MethodFour();

	MethodFive();

	MethodSix();

	cout << obj.thisIsPublic << endl;

	cout << v << endl;
	cout << obj.Addtwenty(v) << endl;

	return 0;
};
