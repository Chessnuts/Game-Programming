#include "GoCommand.h"

GoCommand::GoCommand(vector<string> ids) : Command(ids)
{

}

string GoCommand::Execute(vector<string> input, Location* location, Player* player)
{
    if (input.size() > 1)
    {
        //cout << "argument found" << endl;
        if (player->location->GetConnection(input.at(1)) != nullptr)
        {
            player->MoveTo(player->location->GetConnection(input.at(1)));

            return "Moving " + input.at(1);
        }
        return "I can't move in that direction.";
    }
    return "Which direction should I go?";
}
