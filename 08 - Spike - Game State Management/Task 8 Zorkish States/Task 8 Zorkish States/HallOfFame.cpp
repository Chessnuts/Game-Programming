#include "HallOfFame.h"
#include <conio.h>

using namespace std;



void HallOfFame::Update()
{
	char input = _getch();

	switch (input)
	{
	case '1':
		state = STATES::NEWHIGHSCORE;
		break;

	case '2':
		state = STATES::MAIN_MENU;
		break;

	default:
		cout << "Try again" << endl;
	}
}

void HallOfFame::Render()
{
	cout << "Zorkish :: Hall Of Fame" << endl;
	cout << "--------------------------------------------------------" << endl << endl;
	cout << "Top 10 Zorkish Champions" << endl << endl;
	cout << "\t" << "1. Fred, Mountain World, 5000" << endl;
	cout << "\t" << "2. Mary, Mountain World, 4000" << endl;
	cout << "\t" << "3. Jow, Water World, 3000" << endl;
	cout << "\t" << "4. Henry, Mountain World, 2000" << endl;
	cout << "\t" << "5. Susan, Mountain World, 1000" << endl;
	cout << "\t" << "6. Alfred, Water World, 900" << endl;
	cout << "\t" << "7. Clark, Mountain World, 800" << endl;
	cout << "\t" << "8. Harold, Mountain World, 500" << endl;
	cout << "\t" << "9. Julie, Water World, 300" << endl;
	cout << "\t" << "10. Bill, Box World, -5" << endl << endl;
	cout << "--------------------------------------------------------" << endl << endl;
	cout << "\t" << "Select:" << endl;
	cout << "\t" << "1. Enter new high score" << endl;
	cout << "\t" << "2. Return to main menu" << endl;
}