#include "TakeCommand.h"
#include <iostream>

using namespace std;

TakeCommand::TakeCommand(vector<string> ids) : Command(ids)
{

}

string TakeCommand::Execute(vector<string> input, Location* location, Player* player)
{
	if (input.size() > 1)
	{
		// take from
		if (input.size() > 2 && input.at(2) == "from")
		{
			if (input.size() > 3)
			{
				for (auto e : location->entities)
				{
					if (e->AreYou(input.at(3)))
					{
						for (auto a : e->attributes)
						{
							if (a.AreYou("searchable"))
							{
								for (auto i : e->items)
								{
									if (i->AreYou(input.at(1)))
									{
										for (auto aa : i->attributes)
										{
											if (aa.AreYou("takeable"))
											{
												player->Put(e->Take(i->FirstId()));
												return "You took the " + i->GetName() + " from the " + e->GetName();
											}
										}
										return "I cannot take the " + i->GetName();
									}
									return "I cannot find the  " + input.at(1) + " from the " + input.at(3);
								}
							}
						}
						return "I cannot look inside the " + e->GetName();
					}
				}
				return "I cannot find the " + input.at(3);
			}
			return "What did you want to take the " + input.at(1) + " from?";
		}
		//take
		for (auto e : location->entities)
		{
			if (e->AreYou(input.at(1)))
			{
				for (auto a : e->attributes)
				{
					if (a.AreYou("takeable"))
					{
						player->Put(location->Take(e->FirstId()));
						return "You took the " + e->GetName();
					}
				}
				return "I cannot take the " + e->GetName();
			}
		}
		return "I cannot find the " + input.at(1);

	}
	else
	{
		return "What did you want to take?";
	}
}