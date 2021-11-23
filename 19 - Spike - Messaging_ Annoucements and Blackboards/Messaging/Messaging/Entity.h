#pragma once
#include <string>
#include "GameObject.h"
#include "BlackBoard.h"
#include "Message.h"

class Entity : public GameObject
{
protected:
	string output;
	BlackBoard* blackBoard = nullptr;
public:
	Entity(vector<string> ids, string n, string d, BlackBoard* bb);
	~Entity() {};

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;
	virtual void Update() {};
	virtual void Render() {};
};