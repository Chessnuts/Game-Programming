#include "TakeCommand.h"

TakeCommand::TakeCommandd(vector<string> ids) : Command(ids)
{

}

string TakeCommand::Execute(vector<string> input, Location* location, Player* player)
{
	if (input.size() > 1)
	{
		for (auto e : location->entities)
		{
			if (e->AreYou(input.at(1)))
			{
				for (auto a : e->attributes)
				{
					if (a.AreYou("takeable"))
					{
						location->
					}
				}
				return e->GetName();
			}
		}
		return "I cannot find the " + input.at(1);

	}
	else
	{
		return "What did you want to look at?";
	}
	
	if (input.size() > 1 && input.at(1) == "in")
	{
		if (input.size() > 2)
		{
			if (player->AreYou(input.at(2)))
			{
				return player->GetFullDescription();
			}
			else if (player->HasItem(input.at(2)))
			{
				return player->Fetch(input.at(2))->GetFullDescription();
			}
			else
			{
				for (auto e : location->entities)
				{
					if (e->AreYou(input.at(2)))
					{
						for (auto a : e->attributes)
						{
							if (a.AreYou("searchable"))
							{
								return "\nContains: \n" + e->ItemList();
							}
							return "I cannot look inside the " + e->GetName();
						}
					}
				}
				return "I cannot find the " + input.at(2);
			}
		}
		else
		{
			return "What did you want to look in?";
		}
	}
	return "where did you want to look?";
}