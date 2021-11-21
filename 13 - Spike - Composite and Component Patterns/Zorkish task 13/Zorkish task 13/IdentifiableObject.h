#pragma once
#include <list>
#include <vector>
#include <string>

using namespace std;

class IdentifiableObject
{
private:
	vector<string> identifiers;
public:
	IdentifiableObject() {};
	IdentifiableObject(vector<string> ids);
	~IdentifiableObject();

	bool AreYou(string id);
	string FirstId();
	void AddIdentifier(string id);
	vector<string> GetIdentifiers();
};

