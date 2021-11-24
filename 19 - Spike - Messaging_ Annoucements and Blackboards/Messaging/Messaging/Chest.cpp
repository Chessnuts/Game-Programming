#include "Chest.h"

Chest::Chest(vector<string> ids, string n, string d, BlackBoard* bb) : Entity(ids, n, d, bb)
{
}

string Chest::GetShortDescription()
{
	if (open)
	{
		return "You can see an open chest.";
	}
	return "You can see a closed chest.";
}

string Chest::GetDescription()
{
	return GameObject::GetDescription();
}

string Chest::GetFullDescription()
{
	return GameObject::GetFullDescription();
}

void Chest::Update()
{
	vector<Message> messages = blackBoard->GetMessages({ "chest" });
	
	for (auto m : messages)
	{
		if (m.message == "open")
		{
			open = true;

			blackBoard->RemoveMessage(m);
		}
	}
}

void Chest::Render()
{
	cout << GetShortDescription() << endl << endl;
}
