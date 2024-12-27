#include <string>

class Creature
{
public:
	std::string name;
	int attack, defence;
};

class CreatureModifier
{
	CreatureModifier* next{ nullptr };

protected:
	Creature& creature;

public:
	explicit CreatureModifier(Creature& creature)
		: creature{ creature }
	{
	}

	void add(CreatureModifier* cm)
	{
		if (next)next->add(cm);
		else next = cm;
	}

	virtual void handle()
	{
		if (next) next->handle();
	}
};

class DoubleAttackModifier : public CreatureModifier
{
public:
	explicit DoubleAttackModifier(Creature& creature)
		: CreatureModifier(creature)
	{
	}

	virtual void handle() override
	{
		creature.attack *= 2;
		CreatureModifier::handle();
	}
};

class IncreaseDefenseModifier : public CreatureModifier
{
public:
	explicit IncreaseDefenseModifier(Creature& creature)
		: CreatureModifier(creature)
	{
	}

	virtual void handle() override
	{
		if (creature.attack <= 2)
		{
			creature.defence += 1;
		}
		CreatureModifier::handle();
	}
};