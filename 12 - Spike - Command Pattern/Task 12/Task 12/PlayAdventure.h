#pragma once
#include "State.h"
#include <iostream>
#include "states.h"
#include "Player.h"
#include "Location.h"
#include "string"

extern STATES state;

class PlayAdventure : public State
{
private:
	bool loaded = false;
	Player player;
	vector<Location> locations;
public:
	PlayAdventure() {};
	virtual ~PlayAdventure() {};
	void LoadAdventure(string fileName);
	void Update() override;
	void Render() override;
};

