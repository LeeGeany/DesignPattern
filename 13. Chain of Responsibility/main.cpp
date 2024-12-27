#include <iostream>

#include "Pointer.h"
#include "Brocker.h"

int main(void)
{
	Creature goblin{ "goblin", 1,1 };
	CreatureModifier root{ goblin };
	DoubleAttackModifier r1{ goblin };
	DoubleAttackModifier r1_2{ goblin };
	IncreaseDefenseModifier r2{ goblin };

	root.add(&r1);
	root.add(&r1_2);
	root.add(&r2);

	root.handle();

	std::cout << goblin.name << " " 
		      << goblin.attack << " " 
		      << goblin.defence << " "
		      << std::endl;

	Game game;
	Creature_2 goblin2{ game, "Strong Goblin", 2,2 };

	std::cout << goblin2.name << " "
	      << goblin2.attack << " "
	      << goblin2.defence << " "
	      << std::endl;

	goblin2.get_attack();
	DoubleAttackModifier_2 dam{ game, goblin2 };

	std::cout << goblin2.name << " "
		<< goblin2.attack << " "
		<< goblin2.defence << " "
		<< std::endl;
}