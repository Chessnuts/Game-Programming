#include "StateManager.h"


bool StateManager::Running() const
{
	return state != STATES::DONE;
}
State* StateManager::Current()
{
	if (state == STATES::WELCOME)
	{
		current = &welcome;
	}
	else if (state == STATES::PLAY_GAME)
	{
		current = &playGame;
	}
	else if (state == STATES::GAMEPLAY)
	{
		current = &gameplay;
	}
	else if (state == STATES::MAIN_MENU)
	{
		current = &mainMenu;
	}
	else if (state == STATES::HELP)
	{
		current = &help;
	}
	return current;
}