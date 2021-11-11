#pragma once
#include <list>
#include <vector>

using namespace std;

class IdentifiableObject
{
private:
	vector<string> identifiers;
public:
	IdentifiableObject(vector<string> ids);
	~IdentifiableObject();

	bool AreYou(string id);
	string FirstId();
	void AddIdentifier(string id);
};

