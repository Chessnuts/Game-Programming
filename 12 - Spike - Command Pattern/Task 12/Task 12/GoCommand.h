#pragma once
#include "Command.h"
class GoCommand : public Command
{
public:
	GoCommand() {};
	GoCommand(vector<string> ids);
	~GoCommand() {};

	string Execute(vector<string> input, Location* location, Player* player) override;
};

