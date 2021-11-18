#pragma once
#include "State.h"
#include <iostream>
#include "states.h"

extern STATES state;

class QuitGame : public State
{
public:
	QuitGame() {};
	virtual ~QuitGame() {};
	void Update() override;
	void Render() override;
};

