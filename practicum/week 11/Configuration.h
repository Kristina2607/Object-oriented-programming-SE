#pragma once
#include "ComputerComponents.h"
#include "Memory.h";
#include "Processor.h";
#include "MyString.h"

class Configuration
{
	ComputerComponent** components;
	size_t size;
	size_t capacity;

public:
	void insert(ComputerComponent* component);
	double price() const;
	size_t getSize() const;

	ComputerComponent* create_Component();
	Memory* createMemory();
	Processor* createProcessor();


	const ComputerComponent* operator[] (size_t index) const;
	friend std::ostream& operator<< (std::ostream& os, const Configuration& config);
};


