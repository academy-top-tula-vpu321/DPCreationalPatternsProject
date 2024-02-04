#pragma once
#include <iostream>
#include <string>
#include <vector>

class Product
{
};


class Pizza : public Product
{
public:
	int size;
	std::string base;
	std::string sauce;
	std::string ingrMain;

	std::vector<std::string> ingrs;

	Pizza() 
		: size{}, 
		base{ "" }, 
		sauce{ "" }, 
		ingrMain{ "" } {};
	
	std::string ToString()
	{
		std::string str = "size: " + std::to_string(size)
			+ ", base: " + base + ", sauce: " + sauce
			+ ", main ingrident: " + ingrMain + ", ingridents: ";
		for (auto i : ingrs)
			str += i + ", ";
		
		return str;
	}

};

class IBuilder
{
public:
	virtual IBuilder* SetNew() = 0;
	virtual IBuilder* SetBase(std::string base) = 0;
	virtual IBuilder* SetSize(int size) = 0;
	virtual IBuilder* SetSauce(std::string sauce) = 0;
	virtual IBuilder* SetMainIngr(std::string ingrMain) = 0;
	virtual IBuilder* SetIngr(std::string ingr) = 0;

	virtual Product* GetProduct() = 0;
};

class PizzaBuilder : public IBuilder
{
	Pizza* pizza;
public:
	PizzaBuilder() : pizza{ new Pizza() } {}

	IBuilder* SetNew() override
	{
		if (pizza) delete pizza;

		pizza = new Pizza();
		return this;
	}

	IBuilder* SetBase(std::string base) override
	{
		pizza->base = base;
		return this;
	}

	IBuilder* SetSize(int size) override
	{
		pizza->size = size;
		return this;
	}

	IBuilder* SetSauce(std::string sauce) override
	{
		pizza->sauce = sauce;
		return this;
	}

	IBuilder* SetMainIngr(std::string ingrMain) override
	{
		pizza->ingrMain = ingrMain;
		return this;
	}

	IBuilder* SetIngr(std::string ingr) override
	{
		pizza->ingrs.push_back(ingr);
		return this;
	}

	Product* GetProduct() override
	{
		return pizza;
	}
};