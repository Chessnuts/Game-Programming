#include "HelpCommand.h"



HelpCommand::HelpCommand(vector<string> ids) : Command(ids)
{

}

string HelpCommand::Execute(vector<string> input, Location* location, Player* player)
{

    return "Zorkish :: Help \n -------------------------------------------------------- \n \n The following commands are supported: \n \t quit \n \t go _ \n \t look at _ (in _) \n \t look in _ \n \t take _ (from _) \n \t drop _ \n \t attack _ (with _) \n \n";
}