#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(bool * l)
{
	go = GoCommand({ "go", "move" });
	look = LookCommand({ "look", "inspect" });
	help = HelpCommand({ "help", "?" });
	debug = DebugCommand({ "debug" });
	inventory = InventoryCommand({ "inventory" });
	quit = QuitCommand({ "quit", "exit" }, l);

	commands.push_back(&go);
	commands.push_back(&look);
	commands.push_back(&help);
	commands.push_back(&debug);
	commands.push_back(&inventory);
	commands.push_back(&alias);
	commands.push_back(&quit);

	alias = AliasCommand({ "alias" }, commands);
	//vector<string> inv = { "look", "at", "inventory" };
	//aliases.insert(make_pair("inventory", inv));
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

/*
		if(input.at(0) == "alias")
		{
			if (input.size() > 1)
			{
				string a = input.at(1);
				if (input.size() > 2)
				{
					input.erase(input.begin());
					input.erase(input.begin());

					aliases.insert(make_pair(a, input));

					return "Alias " + a + " added.";
				}

				return "Please specify command for alias " + a;
			}
			return "Please specify alias and command";
		}
		for (auto a : aliases)
		{
			if (a.first == input.at(0))
			{
				for (auto c : commands)
				{
					if (c->AreYou(a.second.at(0)))
					{
						return c->Execute(a.second, location, player);
					}
				}
			}
		}
		*/