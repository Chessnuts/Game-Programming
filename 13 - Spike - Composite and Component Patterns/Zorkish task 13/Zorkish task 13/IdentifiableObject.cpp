#include "IdentifiableObject.h"
#include <string>

using namespace std;

IdentifiableObject::IdentifiableObject(vector<string> ids)
{
	for (auto id : ids)
	{
		identifiers.push_back(id);
	}
}

IdentifiableObject::~IdentifiableObject()
{

}

bool IdentifiableObject::AreYou(string id)
{
	for (auto mID : identifiers)
	{
		if (mID == id)
		{
			return true;
		}
	}
	return false;
}

string IdentifiableObject::FirstId()
{
	return identifiers[0];
}

void IdentifiableObject::AddIdentifier(string id)
{
	identifiers.push_back(id);
}

vector<string> IdentifiableObject::GetIdentifiers()
{
	return identifiers;
}
