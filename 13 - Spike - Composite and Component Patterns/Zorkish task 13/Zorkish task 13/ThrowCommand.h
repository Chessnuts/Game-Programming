#pragma once
#include "Command.h"
class ThrowCommand : public Command
{
public:
	ThrowCommand() {};
	ThrowCommand(vector<string> ids);
	~ThrowCommand() {};

	string Execute(vector<string> input, Location* location, Player* player) override;
};

