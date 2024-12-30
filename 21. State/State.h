#include <iostream>

class State;
class OffState;
class OnState;

class LightSwitch
{
	State* state;

public:
	LightSwitch()
	{
		state = new OffState();
	}

	void set_state(State* state)
	{
		this->state = state;
	}

	void on() { state->on(this); }
	void off() { state->off(this); }
};

class State
{
public:
	virtual void on(LightSwitch* ls)
	{
		std::cout << "Light is already on\n";
	}

	virtual void off(LightSwitch* ls)
	{
		std::cout << "Light is already off\n";
	}
};

class OnState : public State
{
public:
	OnState() { std::cout << "Light turned on\n"; }
	void off(LightSwitch* ls) override
	{
		std::cout << "Switching light off...\n";
		ls->set_state(new OffState);
		delete this;
	}
};

class OffState : public State
{
public:
	OffState() { std::cout << "Light turned off\n"; }
	void on(LightSwitch* ls) override
	{
		std::cout << "Switching light off...\n";
		ls->set_state(new OffState);
		delete this;
	}
};

enum class STATE
{
	OFF_HOOK,
	CONNECTING,
	CONNECT,
	ON_HOLD,
	ON_HOOK
};

enum class TRIGGER
{
	CALL_DIALED,
	HUNG_UP,
	CALL_CONNECTED,
	PLACED_ON_HOLD,

};