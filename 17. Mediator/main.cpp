#include "mediator.h"

int main(void)
{
	ChatRoom room;

	Person John{ "John" };
	Person Jane{ "Jane" };

	room.join(&John);
	room.join(&Jane);

	John.say("hello");
	Jane.say("world");

	return 0;
}