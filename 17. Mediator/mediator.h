#include <string>
#include <vector>
#include <iostream>

class ChatRoom;
class Person;

class Person
{
public:
	std::string name;
	ChatRoom* room = nullptr;
	std::vector<std::string> chat_log;

	Person(const std::string& name) : name(name) {}

	void say(const std::string& message) const
	{
		room->broadcast(name, message);
	}

	void pm(const std::string& who, const std::string& message) const
	{
		room->message(name, who, message);
	}

	void receive(const std::string& origin, const std::string& message)
	{
		std::string s{ origin + ": \"" + message + "\"" };
		std::cout << "[" << name << "'s chat session] " << s << "\n";
		chat_log.emplace_back(s);
	}
};

class ChatRoom
{
public:
	std::vector<Person*> people;

	void join(Person* p)
	{
		// 모든 사람들에게 알림
		std::string join_msg = p->name + "joins the chat";
		broadcast("room", join_msg);
		
		// 들어온 객체에 채팅 방 등록
		p->room = this;
		people.push_back(p);
	}

	void leave()
	{
		//...
	}

	void broadcast(const std::string& origin, const std::string& message)
	{
		for (auto p : people)
			if (p->name != origin)
				p->receive(origin, message);
	}

	// 개인 메시지를 전송
	void message(const std::string& origin, const std::string& who, const std::string& message)
	{
		auto target = std::find_if(std::begin(people), end(people),
			[&](const Person* p) {return p->name == who; });

		if (target != end(people))
			(*target)->receive(origin, message);
	}
};

