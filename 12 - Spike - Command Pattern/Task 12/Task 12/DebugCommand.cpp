#include "DebugCommand.h"


DebugCommand::DebugCommand(vector<string> ids) : Command(ids)
{

}

string DebugCommand::Execute(vector<string> input, Location* location, Player* player)
{
	if (input.size() > 1 && input.at(1) == "tree")
	{
		string output;
		output += "Current location: \n";
		output += location->GetFullDescription();

		output += "entities: \n";

		for (auto e : location->entities)
		{
			output += e.GetFullDescription() + "\n";
		}
		output += "\n";
		output += "connected Locations: \n\n";
		for (auto c : location->connections)
		{
			output += c.first + ": \n";
			output += c.second->GetDescription() + "\n";

			output += "\n";

			output += "entities: \n";
			for (auto e : c.second->entities)
			{
				output += e.GetFullDescription() + "\n";
			}
			output += "\n";
		}

		return output;
	}
	return "Nothing to debug";
}