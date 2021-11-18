#pragma once
#include "Command.h"
class LookCommand : public Command
{
public:
	LookCommand() {};
	LookCommand(vector<string> ids);
	~LookCommand() {};

	string Execute(vector<string> input, Location* location, Player* player) override;
};

