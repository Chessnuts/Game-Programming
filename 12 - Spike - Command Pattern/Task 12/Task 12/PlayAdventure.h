#pragma once
#include "State.h"
#include <iostream>
#include "states.h"

extern STATES state;

class PlayAdventure : public State
{
public:
	PlayAdventure() {};
	virtual ~PlayAdventure() {};
	void Update() override;
	void Render() override;
};

