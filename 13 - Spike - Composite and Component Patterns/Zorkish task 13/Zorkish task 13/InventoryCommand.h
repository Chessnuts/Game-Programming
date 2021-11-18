#pragma once
#include "Command.h"
class InventoryCommand : public Command
{
public:
	InventoryCommand() {};
	InventoryCommand(vector<string> ids);
	~InventoryCommand() {};

	string Execute(vector<string> input, Location* location, Player* player) override;
};

