#include "NPC.h"
#include "Item.h"

NPC::NPC(vector<string> ids, string n, string d, BlackBoard* bb) : Entity(ids, n, d, bb)
{

}

string NPC::GetShortDescription()
{
	return "You can see " + GetName();
}

string NPC::GetDescription()
{
	return GameObject::GetDescription();
}

string NPC::GetFullDescription()
{
	return GameObject::GetFullDescription();
}

void NPC::Update()
{
	output = GetShortDescription() + "\n";

	vector<Message> messages = blackBoard->GetMessages({"npc", "greg"});

	for (auto m : messages)
	{
		if (m.message == "greeting")
		{
			if (m.data != nullptr)
			{
				try
				{
					string* n = reinterpret_cast<string*>(m.data);

					output += GetName() + ": Hello " + *n + "\n";
				}
				catch (...)
				{
					output += GetName() + ": Hi\n";
				}
			}
			else
			{
				output += GetName() + ": Hi\n";
			}
			blackBoard->RemoveMessage(m);
		}
		if (m.message == "purchase")
		{
			if (m.data != nullptr)
			{
				try
				{
					string* r = reinterpret_cast<string*>(m.data);

					if (*r == "sword")
					{
						output += GetName() + ": Let me get that for you\n";

						Item *sword = new Item({ {"sword"}, "Sword", "It's an Iron sword with a sharp blade." });

						blackBoard->AddMessage({ GetName(), "player", "receive item", sword });
					}
					else
					{
						output += GetName() + ": Sorry, I don't sell " + *r + "\n";
					}
				}
				catch (...)
				{
					output += GetName() + ": Hmmmm, I don't know if I can do that for you...\n";
				}

				delete m.data;
			}
			blackBoard->RemoveMessage(m);
		}
	}
}

void NPC::Render()
{
	cout << output << endl;
}
