#include "AliasCommand.h"

AliasCommand::AliasCommand(vector<string> ids, vector<Command*> c) : Command(ids)
{
    commands = c;
}

string AliasCommand::Execute(vector<string> input, Location* location, Player* player)
{
	if (input.size() > 1)
	{
		for (auto c : commands)
		{
			if (c->AreYou(input.at(1)))
			{
				if (input.size() > 2)
				{
					if (!c->AreYou(input.at(2)))
					{
						c->AddIdentifier(input.at(2));
						return "alias added.";
					}
					return "alias already exists.";
				}
				return "Please specify command for alias " + input.at(1);
			}
		}
	}
	return "Please specify alias and command";
}