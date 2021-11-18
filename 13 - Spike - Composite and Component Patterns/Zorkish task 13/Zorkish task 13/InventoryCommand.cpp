#include "InventoryCommand.h"


InventoryCommand::InventoryCommand(vector<string> ids) : Command(ids)
{

}

string InventoryCommand::Execute(vector<string> input, Location* location, Player* player)
{
	return player->GetFullDescription();
}