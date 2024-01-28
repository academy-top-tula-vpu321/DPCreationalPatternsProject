#include "AbstractUnit.h"

std::string BaseUnit::ToString()
{
    return "Name: " + name
        + ", defense: " + std::to_string(defense)
        + ", attack: " + std::to_string(attack);
}

InfantryUnit* RomeFactory::CreateInfantry()
{
    return new RomeInfantry();
}

ArcherUnit* RomeFactory::CreateArcher()
{
    return new RomeArcher();
}

HorsemanUnit* RomeFactory::CreateHorseman()
{
    return new RomeHorseman();
}
