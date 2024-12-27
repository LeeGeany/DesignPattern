#include <string>
#include <boost/signals2.hpp>

using namespace boost;

struct Query
{
	std::string creature_name;
	enum Argument {attack, defense} argument;
	int result;
};

class Game
{
public:
	boost::signals2::signal<void(Query&)> queries;
};

class Creature_2
{
public:
	Game& game;
	int attack;
	int defence;
	std::string name;

public:
	Creature_2(Game& game, std::string name, int attack, int defence)
		: game{ game }, name{ name }, attack{ attack }, defence{ defence }
	{
	}

	int get_attack() const
	{
		Query q{ name, Query::Argument::attack, attack };
		game.queries(q);
		return q.result;
	}
};

class CreatureModifier_2
{
	Game& game;
	Creature_2& creature;

public:
	CreatureModifier_2(Game& game, Creature_2 creature)
	:game{ game }, creature{ creature }
	{
	}
};

class DoubleAttackModifier_2 : public CreatureModifier_2
{
	boost::signals2::connection conn;

public:
	DoubleAttackModifier_2(Game& game, Creature_2 creature)
	: CreatureModifier_2(game, creature)
	{

		conn = game.queries.connect([&](Query& q)
			{
				if (q.creature_name == creature.name &&
				q.argument == Query::Argument::attack)
				{

					q.result *= 2;
				}
			});
	}

	virtual ~DoubleAttackModifier_2()
	{
		conn.disconnect();
	}
};