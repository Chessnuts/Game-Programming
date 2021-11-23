#include "Message.h"

Message::Message(string f, string t, string m, void* d)
{
	from = f;
	to = t;
	message = m;
	data = d;
}

bool Message::operator==(const Message& m)
{
	return (from == m.from && to == m.to && message == m.message && data == m.data);
}
