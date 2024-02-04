#include "AbstractUnit.h"

std::vector<BaseUnit*> ArmyCreate(BaseFactory* factory, int infantries, int archers, int horsemans)
{
	std::vector<BaseUnit*> army;
	for (int i{}; i < infantries; i++)
		army.push_back(factory->CreateInfantry());
	for (int i{}; i < archers; i++)
		army.push_back(factory->CreateArcher());
	for (int i{}; i < horsemans; i++)
		army.push_back(factory->CreateHorseman());

	return army;
}


