#pragma once
#include "State.h"
#include "Welcome.h"
#include "MainMenu.h"
#include "states.h"
#include "Help.h"
#include "PlayAdventure.h"

extern STATES state;

class StateManager
{
private:
	//states here
	Welcome welcome;
	MainMenu mainMenu;
	PlayAdventure playGame;
	Help help;
	//HallOfFame hallOfFame;
	//Quit quit;

	State* current;
	bool running = true;

public:
	bool Running() const;
	State* Current();
};

