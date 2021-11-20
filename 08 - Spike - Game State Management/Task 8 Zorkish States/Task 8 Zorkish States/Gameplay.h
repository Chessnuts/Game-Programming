#pragma once
#include "State.h"
#include <iostream>
#include "states.h"

extern STATES state;

class Gameplay : public State
{
public:
	Gameplay() {};
	~Gameplay() {};
	void Update() override;
	void Render() override;
};
