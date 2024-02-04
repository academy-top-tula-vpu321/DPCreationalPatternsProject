#pragma once
#include <string>
#include <mutex>

std::mutex m;

class OS
{
	static OS* osPointer;
	std::string name;

	OS(std::string name) : name{ name } {};
	OS(const OS& os) = delete;
	OS& operator=(OS& os) = delete;

public:
	std::string& Name() { return name; }

	static OS* GetOs(std::string name)
	{
		std::lock_guard<std::mutex> lg(m);

		if (!osPointer)
			osPointer = new OS(name);
		return osPointer;
	}
};


class Computer
{
	OS* os;
public:
	OS*& Os() { return os; }

	void Launch(std::string name)
	{
		os = OS::GetOs(name);
	}
};

OS* OS::osPointer = nullptr;
