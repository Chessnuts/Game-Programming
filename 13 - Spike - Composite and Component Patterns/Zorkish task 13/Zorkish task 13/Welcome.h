#pragma once
#include "State.h"
#include "states.h"

extern STATES state;

class Welcome : public State
{
public:
	Welcome();
	virtual ~Welcome() {};
	void Update() override;
	void Render() override;
};

