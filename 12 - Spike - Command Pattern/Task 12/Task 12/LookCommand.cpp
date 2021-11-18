#include "LookCommand.h"
#include "Command.h"

using namespace std;

LookCommand::LookCommand(vector<string> ids) : Command(ids)
{
	
}

string Execute(vector<string> input, Location* location, Player* player)
{
	if (input.size() > 1 && input.at(1) == "at")
	{
		if (input.size() > 2)
		{
			if (player->AreYou(input.at(2)))
			{
				return player->GetFullDescription();
			}
			else if (player->inventory.HasItem(input.at(2)))
			{
				return player->inventory.Fetch(input.at(2))->GetFullDescription();
			}
			else
			{
				for (auto e : location->entities)
				{
					if (e.AreYou(input.at(2)))
					{
						return e.GetFullDescription();
					}
				}
				return "I cannot find the " + input.at(2);
			}
		}
		else
		{
			return "What did you want to look at?";
		}
	}
	return "where did you want to look?";
}