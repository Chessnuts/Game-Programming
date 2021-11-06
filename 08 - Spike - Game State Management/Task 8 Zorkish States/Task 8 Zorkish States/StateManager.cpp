#include "StateManager.h"

bool StateManager::Running() const
{
	return state != STATES::DONE;
}
State* StateManager::Current()
{
	return current;
}