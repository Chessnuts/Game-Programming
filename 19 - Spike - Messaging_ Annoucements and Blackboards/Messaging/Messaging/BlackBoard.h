#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Message.h"

using namespace std;


class BlackBoard
{
private:
	vector<Message> messages;
public:
	BlackBoard() {};
	~BlackBoard() {};
	void AddMessage(Message message);
	vector<Message> GetMessages(vector<string> ids);
	void RemoveMessage(Message message);
	void clear();
};

