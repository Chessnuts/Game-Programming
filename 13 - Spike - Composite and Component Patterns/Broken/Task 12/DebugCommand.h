#pragma once
#include "Command.h"
class DebugCommand : public Command
{
public: 
	DebugCommand() {};
	DebugCommand(vector<string> ids);
	~DebugCommand() {};

	string Execute(vector<string> input, Location* location, Player* player) override;
};

