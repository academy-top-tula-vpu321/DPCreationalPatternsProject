#pragma once
#include <iostream>
#include <string>
#include <vector>

class BaseUnit
{
protected:
	std::string name;
	int defense;
	int attack;
public:
	BaseUnit(std::string name = "")
		: name{ name }, defense{}, attack{} {};

	std::string& Name() { return name; }
	int& Defense() { return defense; }
	int& Attack() { return attack; }

	virtual std::string ToString();
	virtual ~BaseUnit() {}
};

class InfantryUnit : public BaseUnit
{
public:
	InfantryUnit() : BaseUnit("Infantry") {}
};

class ArcherUnit : public BaseUnit
{
public:
	ArcherUnit() : BaseUnit("Archer") {}
};

class HorsemanUnit : public BaseUnit
{
public:
	HorsemanUnit() : BaseUnit("Horseman") {}
};


class RomeInfantry : public InfantryUnit
{
public:
	RomeInfantry() : InfantryUnit()
	{
		name += " Rome";
	}
};

class RomeArcher : public ArcherUnit
{
public:
	RomeArcher() : ArcherUnit()
	{
		name += " Rome";
	}
};

class RomeHorseman : public HorsemanUnit
{
public:
	RomeHorseman() : HorsemanUnit()
	{
		name += " Rome";
	}
};





class BaseFactory
{
public:
	virtual InfantryUnit* CreateInfantry() = 0;
	virtual ArcherUnit* CreateArcher() = 0;
	virtual HorsemanUnit* CreateHorseman() = 0;
};

class RomeFactory : public BaseFactory
{
	InfantryUnit* CreateInfantry() override;
	ArcherUnit* CreateArcher() override;
	HorsemanUnit* CreateHorseman() override;
};

class CarthageFactory : public BaseFactory
{
	InfantryUnit* CreateInfantry() override;
	ArcherUnit* CreateArcher() override;
	HorsemanUnit* CreateHorseman() override;
};

