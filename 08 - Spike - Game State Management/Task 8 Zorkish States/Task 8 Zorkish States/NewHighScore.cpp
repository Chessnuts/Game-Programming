#include "NewHighScore.h"
#include <iostream>


using namespace std;



void NewHighScore::Update()
{
	string input;
	cin >> input;
	state = STATES::MAIN_MENU;
}

void NewHighScore::Render()
{
	cout << ">>> NEW HIGH SCORE!!! <<<" << endl;
	cout << "Please enter Your name:" << endl;
}