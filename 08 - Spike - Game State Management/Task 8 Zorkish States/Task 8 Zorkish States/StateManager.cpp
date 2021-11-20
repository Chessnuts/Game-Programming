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
	else if (state == STATES::HALLOFFAME)
	{
		current = &hallOfFame;
	}
	else if (state == STATES::NEWHIGHSCORE)
	{
		current = &newHighScore;
	}
	else if (state == STATES::ABOUT)
	{
		current = &about;
	}
	else if (state == STATES::HELP)
	{
		current = &help;
	}
	else if (state == STATES::QUIT)
	{
		current = &quit;
	}
	else if (state == STATES::QUITGAME)
	{
		current = &quitGame;
	}
	return current;
}