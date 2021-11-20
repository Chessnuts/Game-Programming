#pragma once
#include "LookCommand.h"
#include "GoCommand.h"
#include "HelpCommand.h"
#include "InventoryCommand.h"
#include "DebugCommand.h"
#include "AliasCommand.h"
#include "QuitCommand.h"
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class CommandProcessor
{
private:
	LookCommand look;
	GoCommand go;
	HelpCommand help;
	DebugCommand debug;
	InventoryCommand inventory;
	AliasCommand alias;
	QuitCommand quit;
	vector<Command*> commands;
	//map<string, vector<string>> aliases;

public:

	CommandProcessor(bool*l);
	CommandProcessor() {};
	~CommandProcessor() {};

	string Execute(vector<string> input, Location* location, Player* player);
};

