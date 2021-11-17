#include "Welcome.h"
#include <iostream>

using namespace std;

Welcome::Welcome()
{

}

void Welcome::Update()
{
	state = STATES::MAIN_MENU;
}

void Welcome::Render()
{
	cout << "welcome to zorkish" << endl;
}