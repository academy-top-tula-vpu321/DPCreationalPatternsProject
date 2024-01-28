#include <iostream>
#include <vector>

#include "Unit.h"

Unit* CreateUnit(UnitType type)
{
	switch (type)
	{
	case InfantryType:
		return new Infantry();
	case ArcherType:
		return new Archer();
	case HorsemanType:
		return new Horseman();
	default:
		return nullptr;
	}
}

void FactoryMethodExample()
{
	srand(time(nullptr));
	int size{ 10 };

	std::vector<Unit*> army;
	std::vector<Factory*> factories;
	factories.push_back(new InfantryFactory());
	factories.push_back(new ArcherFactory());
	factories.push_back(new HorsemanFactory());
	factories.push_back(new CatapultFactory());

	/*for (int i{}; i < size; i++)
		army.push_back(CreateUnit((UnitType)(rand() % 3)));
	for (auto u : army)
		u->Info();*/

	Factory* factory;
	Unit* unit;
	for (int i{}; i < size; i++)
	{
		factory = factories[rand() % factories.size()];
		unit = factory->Create();
		army.push_back(unit);
	}
	for (auto u : army)
		u->Info();
}

