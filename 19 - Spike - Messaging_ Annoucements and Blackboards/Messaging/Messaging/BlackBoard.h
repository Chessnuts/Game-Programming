#pragma once
#include <vector>
#include <string>

using namespace std;

struct Message
{
public:
	string from;
	string to;
	string message;
	void* data = nullptr;
};

class BlackBoard
{
private:
	vector<Message> messages;
public:
	BlackBoard() {};
	~BlackBoard() {};
	void AddMessage(Message message);
	vector<Message> GetMessages(vector<string> ids);
	void clear();
};

