#pragma once
#include <string>

using namespace std;

class Message
{
public:
	Message() {};
	Message(string f, string t, string m, void* d = nullptr);
	~Message() {};
	string from;
	string to;
	string message;
	void* data = nullptr;

	bool operator== (const Message &m);
};

