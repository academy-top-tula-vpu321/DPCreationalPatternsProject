#include <iostream>
#include <vector>

#include "AbstractUnit.h"
#include "Builder.h"
#include "Computer.h"

#include <thread>

void FactoryMethodExample();
std::vector<BaseUnit*> ArmyCreate(BaseFactory*, int = 20, int = 10, int = 5);

void BuilderExample();

void ComputerLaunch(std::string name)
{
	Computer* computer = new Computer();
	computer->Os() = OS::GetOs(name);
	std::cout << computer->Os()->Name() << "\n";
}

int main()
{
	//FactoryMethodExample();

	/*std::vector<BaseUnit*> army = ArmyCreate(new RomeFactory());
	for (auto u : army)
		std::cout << u->ToString() << "\n";*/

	/*Computer* computer = new Computer();
	computer->Launch("Windows 10");

	std::cout << computer->Os()->Name() << "\n";

	computer->Os()->GetOs("Linux");
	std::cout << computer->Os()->Name() << "\n";*/

	std::thread th1(ComputerLaunch, "Windows 10");
	std::thread th2(ComputerLaunch, "Linux");

	th2.join();
	th1.join();

	
}

void BuilderExample()
{
	IBuilder* builder = new PizzaBuilder();

	/*builder->SetSize(45);
	builder->SetBase("pshenica");
	builder->SetMainIngr("bekon");
	builder->SetSauce("tomate");
	builder->SetIngr("kolbaski");
	builder->SetIngr("mocarella");

	Pizza* pizza1 = (Pizza*)builder->GetProduct();*/

	Pizza* pizza1 = (Pizza*)
		builder->SetSize(45)
		->SetBase("pshenica")
		->SetMainIngr("bekon")
		->SetSauce("tomate")
		->SetIngr("kolbaski")
		->SetIngr("mocarella")
		->GetProduct();

	std::cout << pizza1->ToString();
}