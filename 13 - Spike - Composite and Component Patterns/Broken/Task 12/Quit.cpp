#include "Quit.h"
#include <conio.h>

using namespace std;



void Quit::Update()
{
	char input = _getch();

	state = STATES::MAIN_MENU;
}

void Quit::Render()
{
	cout << "Your adventure has ended without fame or fortune." << endl << endl;
	cout << "Press Enter to return to the Main Menu" << endl;
}