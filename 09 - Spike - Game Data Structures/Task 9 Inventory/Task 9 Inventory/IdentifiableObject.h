#pragma once
#include <list>
#include <string>

using namespace std;

class IdentifiableObject
{
private:
	list<string> identifiers;
public:
	IdentifiableObject(list<string> ids);
	~IdentifiableObject();

	bool AreYou(string id);
	string FirstId();
	void AddIdentifier(string id);
};

