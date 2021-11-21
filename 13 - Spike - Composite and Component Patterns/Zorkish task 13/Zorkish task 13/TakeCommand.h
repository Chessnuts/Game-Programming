#pragma once
#include "Command.h"
class TakeCommand : public Command
{
public:
	TakeCommand() {};
	TakeCommand(vector<string> ids);
	~TakeCommand() {};

	string Execute(vector<string> input, Location* location, Player* player) override;
};

