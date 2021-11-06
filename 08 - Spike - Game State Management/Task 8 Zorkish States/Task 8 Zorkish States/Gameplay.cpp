#include "Gameplay.h"

using namespace std;

void Gameplay::Update()
{
	string input;

	cin >> input;

	if (input == "quit")
	{
		state = STATES::QUIT;
	}
}

void Gameplay::Render()
{
	cout << "This world is simple and pointless. Used it to test Zorkish phase 1 spec." << endl;
	cout << "\t" << "(type 'quit' to go back)" << endl;
}