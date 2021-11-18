#include "CommandProcessor.h"

CommandProcessor::CommandProcessor()
{
	go = GoCommand({ "go", "move" });
	look = LookCommand({ "look", "inspect" });

	commands.push_back(&go);
	commands.push_back(&look);
}

string CommandProcessor::Execute(vector<string> input, Location* location, Player* player)
{
	if(!input.empty())
	{
		for (auto c : commands)
		{
			if (c->AreYou(input.at(0)))
			{
				return c->Execute(input, location, player);
			}
		}
	}
	return "No command found.";
}