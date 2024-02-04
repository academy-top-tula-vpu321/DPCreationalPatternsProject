#pragma once
class Singleton
{
	static Singleton* singleton;

	Singleton(){}
	Singleton(const Singleton& singleton) = delete;
	Singleton& operator=(Singleton& singleton) = delete;

public:
	static Singleton* GetInstance()
	{
		if (!singleton)
			singleton = new Singleton();
		return singleton;
	}
};

