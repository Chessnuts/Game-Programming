#include "Location.h"

using namespace std;

Location::Location(vector<string> ids, string n, string d) : GameObject(ids, n, d)
{

}


string Location::GetFullDescription()
{
	return "You are in " + GetName() + ".";
}