#pragma once
#include "State.h"
#include <iostream>
#include "states.h"
#include "Location.h"
#include "Player.h"

extern STATES state;

class Gameplay : public State
{
private:
	Player player;
	vector<Location> locations;
public:
	Gameplay(string file);
	Gameplay() {};
	virtual ~Gameplay() {};
	void Update() override;
	void Render() override;
};
