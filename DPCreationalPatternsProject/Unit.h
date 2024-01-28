#pragma once
#include <iostream>
enum UnitType
{
	InfantryType,
	ArcherType,
	HorsemanType
};

class Unit
{
protected:
	std::string name;
public:
	Unit(std::string name = "") : name{ name } {};
	virtual void Info() = 0;
};

class Factory
{
public:
	virtual Unit* Create() = 0;
};

class Infantry : public Unit
{
public:
	void Info() override;
};

class InfantryFactory : public Factory
{
	Unit* Create() override
	{
		return new Infantry();
	}
};

class Archer : public Unit
{
public:
	void Info() override;
};

class ArcherFactory : public Factory
{
	Unit* Create() override
	{
		return new Archer();
	}
};

class Horseman : public Unit
{
public:
	void Info() override;
};

class HorsemanFactory : public Factory
{
	Unit* Create() override
	{
		return new Horseman();
	}
};

class Catapult : public Unit
{
public:
	void Info() override;
};

class CatapultFactory : public Factory
{
	Unit* Create() override
	{
		return new Catapult();
	}
};

