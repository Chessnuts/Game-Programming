#pragma once
#include "Entity.h"
class Chest :
    public Entity
{
private: 
	bool open = false;
public:
	Chest(vector<string> ids, string n, string d, BlackBoard* bb);
	~Chest() {};

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;

	void Update() override;
	void Render() override;
};

