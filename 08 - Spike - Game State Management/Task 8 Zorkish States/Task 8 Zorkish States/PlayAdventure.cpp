#include "PlayAdventure.h"
#include <conio.h>

using namespace std;


void PlayAdventure::Update()
{
	char input = _getch();

	switch (input)
	{
	case '1':
		state = STATES::GAMEPLAY;
		break;

	case '2':
		state = STATES::MAIN_MENU;
		break;

	default:
		cout << "Try again" << endl;
	}
}

void PlayAdventure::Render()
{
	cout << "\t" << "Select Adventure" << endl;
	cout << "\t" << "1. Void World" << endl;
	cout << "\t" << "2. Return to main menu" << endl;
}