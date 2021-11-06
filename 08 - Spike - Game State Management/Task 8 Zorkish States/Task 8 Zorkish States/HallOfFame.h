#pragma once
#include "State.h"
#include <iostream>
#include "states.h"

extern STATES state;

class HallOfFame : public State
{
public:
	HallOfFame() {};
	virtual ~HallOfFame() {};
	void Update() override;
	void Render() override;
};


