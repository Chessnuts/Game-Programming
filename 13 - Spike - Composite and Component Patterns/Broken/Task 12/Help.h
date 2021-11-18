#pragma once
#include "State.h"
#include <iostream>
#include "states.h"

extern STATES state;

class Help : public State
{
public:
	Help();
	virtual ~Help() {};
	void Update() override;
	void Render() override;
};
