#pragma once
#include "State.h"
#include <iostream>
#include "states.h"
#include "Player.h"
#include "Entity.h"
#include "Location.h"
#include "string"
#include "CommandProcessor.h"

extern STATES state;

class PlayAdventure : public State
{
private:
	bool loaded = false;
	Player player;
	vector<Location> locations;
	CommandProcessor commandProcessor;
public:
	PlayAdventure() {};
	virtual ~PlayAdventure() {};
	void LoadAdventure(string fileName);
	void Update() override;
	void Render() override;
};

