#pragma once
class State
{

public:
	State();
	virtual ~State() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};

