#pragma once
#include "Command.h"
class HelpCommand : public Command
{
public:
	HelpCommand() {};
	HelpCommand(vector<string> ids);
	~HelpCommand() {};

	string Execute(vector<string> input, Location* location, Player* player) override;
};

