#pragma once
#include "State.h"
#include <iostream>
#include "states.h"

extern STATES state;

class Quit : public State
{
public:
	Quit() {};
	virtual ~Quit() {};
	void Update() override;
	void Render() override;
};

