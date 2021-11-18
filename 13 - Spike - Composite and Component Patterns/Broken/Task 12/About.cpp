#include "About.h"
#include <conio.h>

using namespace std;



void About::Update()
{
	char input = _getch();

	state = STATES::MAIN_MENU;
}

void About::Render()
{
	cout << "Zorkish :: About" << endl;
	cout << "--------------------------------------------------------" << endl << endl;
	cout << "Created by Ryan Chessum 102564760 for COS30031" << endl << endl;
	cout << "Press Enter to return to the Main Menu" << endl;
}