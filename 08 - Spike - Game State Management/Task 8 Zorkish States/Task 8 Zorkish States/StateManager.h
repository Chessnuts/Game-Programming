#pragma once
#include "State.h"
#include "states.h"

class StateManager
{
private:
	//states here
	//Welcome welcome;
	//MainMenu mainMenu;
	//PlayGame playGame;
	//Help help;
	//HallOfFame hallOfFame;
	//Quit quit;

	State* current;
	bool running = true;

public:
	bool Running() const;
	State* Current();
};

