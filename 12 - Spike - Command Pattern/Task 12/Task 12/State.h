#pragma once
class State
{

public:
	State();
	~State();
	virtual void Update() = 0;
	virtual void Render() = 0;
};

