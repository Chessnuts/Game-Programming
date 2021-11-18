#pragma once
#include "State.h"
#include <iostream>
#include "states.h"

extern STATES state;

class MainMenu : public State
{
public:
	MainMenu();
	virtual ~MainMenu() {};
	void Update() override;
	void Render() override;
};

