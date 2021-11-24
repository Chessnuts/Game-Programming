#pragma once
#include "Entity.h"

using namespace std;

class NPC : public Entity
{
public:
	NPC(vector<string> ids, string n, string d, BlackBoard* bb);
	~NPC() {};

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;

	void Update() override;
	void Render() override;
};

