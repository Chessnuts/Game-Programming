#pragma once
#include "Command.h"

class AliasCommand : public Command
{
private:
	vector<Command*> commands;
public:
	AliasCommand() { commands = { nullptr }; };
	AliasCommand(vector<string> ids, vector<Command*> c);
	~AliasCommand() {};

	string Execute(vector<string> input, Location* location, Player* player) override;
};

