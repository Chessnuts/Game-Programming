#pragma once
#include <string>
#include "GameObject.h"
#include "Inventory.h"
#include "Entity.h"
#include "BlackBoard.h"

using namespace std;
class Player : public Entity
{
public:
	Player(string n, string d, BlackBoard*bb);
	~Player() {};
	Inventory inventory;

	string GetShortDescription() override;
	string GetDescription() override;
	string GetFullDescription() override;

	void Update() override;
	void Render() override;
};

