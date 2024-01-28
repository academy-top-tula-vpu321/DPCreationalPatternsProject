#include <iostream>
#include <vector>

#include "AbstractUnit.h"

void FactoryMethodExample();
std::vector<BaseUnit*> ArmyCreate(BaseFactory*, int = 20, int = 10, int = 5);

int main()
{
	//FactoryMethodExample();

	std::vector<BaseUnit*> army = ArmyCreate(new RomeFactory());
	for (auto u : army)
		std::cout << u->ToString() << "\n";
}
