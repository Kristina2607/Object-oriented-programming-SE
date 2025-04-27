#pragma once
#include "Computer.h"

class ComputerStore
{
	Computer* computers;
	size_t size;
	size_t capacity;
	char* name;
	void copyFrom(const ComputerStore& other);
	void free();
	void resize(size_t newCapacity);

public:
	ComputerStore();
	ComputerStore(const char* name);
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator= (const ComputerStore& other);
	~ComputerStore();

	void setName(const char* name);
	const char* getName() const;

	void addComputer(const Computer& other);
	void print() const;
	void buyComputer(const char* brand, double money);
	void printAvailableComputers();
};

class ConsultantUtils
{
	bool isGoodForGaming(const Computer& obj);
	bool isGoodForTravel(const Computer& obj);
};

