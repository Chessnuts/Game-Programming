#pragma once
class State
{

public:
	State();
	~State();
	void Update() = 0;
	void Render() = 0;
};

