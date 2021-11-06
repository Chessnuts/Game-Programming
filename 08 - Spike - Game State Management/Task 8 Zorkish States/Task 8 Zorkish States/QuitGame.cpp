#include "QuitGame.h"

#include <conio.h>

using namespace std;



void QuitGame::Update()
{

	state = STATES::DONE;
}

void QuitGame::Render()
{
	cout << "Good bye" << endl;
}