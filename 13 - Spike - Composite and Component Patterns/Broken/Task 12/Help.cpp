#include "Help.h"
#include <conio.h>

using namespace std;



Help::Help()
{

}

void Help::Update()
{
	char input = _getch();

	state = STATES::MAIN_MENU;
}

void Help::Render()
{
	cout << "Zorkish :: Help" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
	cout << "The following commands are supported:" << endl;
	cout << endl;
	cout << "\t" << "quit" << endl;
	cout << "\t" << "go _" << endl;
	cout << "\t" << "look at _ (in _) " << endl;
	cout << "\t" << "look in _" << endl;
	cout << "\t" << "take _ (from _)" << endl;
	cout << "\t" << "drop _" << endl;
	cout << "\t" << "attack _ (with _)" << endl << endl;
	cout << "Press Enter to return to the Main Menu" << endl;
}