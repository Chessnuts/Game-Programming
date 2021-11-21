#pragma once
#include "LookCommand.h"
#include "GoCommand.h"
#include "HelpCommand.h"
#include "InventoryCommand.h"
#include "DebugCommand.h"
#include "TakeCommand.h"
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
	TakeCommand take;

	vector<Command*> commands;
	//map<string, vector<string>> aliases;

public:
	CommandProcessor();
	~CommandProcessor() {};

	string Execute(vector<string> input, Location* location, Player* player);
};

