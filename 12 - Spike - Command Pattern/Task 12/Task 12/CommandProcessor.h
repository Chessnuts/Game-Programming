#pragma once
#include "LookCommand.h"
#include "GoCommand.h"
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
	vector<Command*> commands;
	map<string, vector<string>> aliases;

public:
	CommandProcessor();
	~CommandProcessor() {};

	string Execute(vector<string> input, Location* location, Player* player);
};

