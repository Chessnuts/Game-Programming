#pragma once
#include "State.h"
#include <iostream>
#include "states.h"

extern STATES state;

class About : public State
{
public:
	About() {};
	~About() {};
	void Update() override;
	void Render() override;
};


