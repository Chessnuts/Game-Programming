#include "BlackBoard.h"
#include <vector>

void BlackBoard::AddMessage(Message message)
{
	messages.push_back(message);
}

vector<Message*> BlackBoard::GetMessages(vector<string> ids)
{
	vector<Message*> result;

	for (auto id : ids)
	{
		for (auto message : messages)
		{
			if (message.to == id)
			{
				result.push_back(&message);
			}
		}
	}

	return result;
}

void BlackBoard::RemoveMessage(Message* message)
{
	int i = 0;
	for (auto m : messages)
	{
		if (m == *message)
		{
			messages.erase(find(messages.begin(), messages.end(), m));
		}
	}
}

void BlackBoard::clear()
{
	for (auto m : messages)
	{
		delete m.data;
	}
	messages.clear();
}
