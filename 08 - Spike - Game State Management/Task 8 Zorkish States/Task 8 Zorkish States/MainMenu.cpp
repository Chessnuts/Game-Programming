#include "MainMenu.h"
#include <conio.h>

using namespace std;

MainMenu::MainMenu() 
{

}

void MainMenu::Update()
{
	char input = _getch();

	switch (input)
	{
	case '1':
		state = STATES::PLAY_GAME;
		break;

	case '2':
		state = STATES::HALLOFFAME;
		break;

	case '3':
		state = STATES::HELP;
		break;

	case '4':
		state = STATES::ABOUT;
		break;

	case '5':
		state = STATES::QUITGAME;
		break;

	default:
		cout << "Try again" << endl;
	}
}

void MainMenu::Render()
{
	cout << "Zorkish :: Main Menu" << endl;
	cout << "--------------------------------------------------------" << endl << endl;
	cout << "Welcome to Zorkish Adventures" << endl;
	cout << "\t" << "1. Select Adventure and Play" << endl;
	cout << "\t" << "2. Hall of Fame" << endl;
	cout << "\t" << "3. Help" << endl;
	cout << "\t" << "4. About" << endl;
	cout << "\t" << "5. Quit" << endl << endl;
	cout << "Select 1-5: " << endl;
}