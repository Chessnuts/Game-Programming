#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Message
{
public:
	~Message() {};
	string from;
	string to;
	string message;
	void* data;
};

class BlackBoard
{
private:
	vector<Message> messages;
public:
	BlackBoard() {};
	~BlackBoard() {};
	void AddMessage(Message message);
	vector<Message*> GetMessages(vector<string> ids);
	void RemoveMessage(Message* message);
	void clear();
};

