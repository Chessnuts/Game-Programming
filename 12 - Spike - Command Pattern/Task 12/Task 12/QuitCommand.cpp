#include "QuitCommand.h"

QuitCommand::QuitCommand(vector<string> ids, bool*l) : Command(ids)
{
	loaded = l;
}

string QuitCommand::Execute(vector<string> input, Location* location, Player* player)
{
	*loaded = false;
	state = STATES::QUIT;
	return "Quitting game...";
}