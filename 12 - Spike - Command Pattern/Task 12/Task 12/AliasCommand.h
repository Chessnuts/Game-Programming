#pragma once
#include "Command.h"
class AliasCommand : public Command
{
public:
	AliasCommand() {};
	AliasCommand(vector<string> ids);
	~AliasCommand() {};

	string Execute(vector<string> input, Location* location, Player* player) override;
};

