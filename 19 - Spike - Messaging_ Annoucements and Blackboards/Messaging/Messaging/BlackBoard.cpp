#include "BlackBoard.h"

void BlackBoard::AddMessage(Message message)
{
	messages.push_back(message);
}

vector<Message> BlackBoard::GetMessages(vector<string> ids)
{
	vector<Message> result;

	for (auto id : ids)
	{
		for (auto message : messages)
		{
			if (message.to == id)
			{
				result.push_back(message);
			}
		}
	}

	return result;
}

void BlackBoard::clear()
{
	messages.clear();
}
