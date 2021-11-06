#pragma once
#include "State.h"
#include "Welcome.h"
#include "MainMenu.h"
#include "states.h"
#include "Help.h"
#include "PlayAdventure.h"
#include "Gameplay.h"
#include "Quit.h"
#include "HallOfFame.h"

extern STATES state;

class StateManager
{
private:
	//states here
	Welcome welcome;
	MainMenu mainMenu;
	PlayAdventure playGame;
	Gameplay gameplay;
	Help help;
	HallOfFame hallOfFame;
	Quit quit;

	State* current;
	bool running = true;

public:
	StateManager() {};
	~StateManager() {};
	bool Running() const;
	State* Current();
};

