#include "ThrowCommand.h"

using namespace std;

ThrowCommand::ThrowCommand(vector<string> ids) : Command(ids)
{

}

string ThrowCommand::Execute(vector<string> input, Location* location, Player* player)
{
	if (input.size() > 1)
	{
		for (auto p : player->items)
		{
			for (auto a : p->attributes)
			{
				if (a.AreYou("throwable"))
				{
					if (input.size() > 2 && input.at(2) == "at")
					{
						for (auto e : location->entities)
						{
							if (e->AreYou(input.at(3)))
							{
								for (auto aa : e->attributes)
								{
									if (aa.AreYou("health"))
									{
										if (e->health > 0)
										{
											player->Take(p->FirstId());
											e->health -= 100;
											string output = "You threw the " + p->GetName() + " at the " + e->GetName();
											if (e->health <= 0)
											{
												output += "\nThe " + e->GetName() + " fell to the ground...";
												e->attributes.push_back(Attribute({ "searchable" }));
											}
											else
											{
												output += "\nThe " + e->GetName() + " took some damage";
											}
											return output;
										}
										return "the " + input.at(3) + " is already dead.";
									}
								}
								return "I probably shouldn't throw the " + input.at(1) + " at the " + input.at(3);
							}
						}
						return "I cannot find the " + input.at(3);
					}
					return "what did you want to throw the " + input.at(1) + " at?";
				}
			}
		}
		return "Cannot throw the " + input.at(1);
	}
	else
	{
		return "What did you want to throw?";
	}
}