#pragma once
#include "Command.h"
#include "State.h"
#include <iostream>
#include "states.h"

extern STATES state;

class QuitCommand : public Command
{
private:
	bool* loaded;
public:
	QuitCommand() { loaded = nullptr; };
	QuitCommand(vector<string> ids, bool * loaded);
	~QuitCommand() {};

	string Execute(vector<string> input, Location* location, Player* player) override;
};



















