#pragma once
#include "Computer.h"

enum class Criteria
{
	Gaming,
	Travel,
	NoCriteria
};

class ComputerStore
{
	Computer* computers;
	size_t size;
	size_t capacity;
	char* name;

	static constexpr size_t INITIAL_CAPACITY = 8;

	void copyFrom(const ComputerStore& other);
	void free();
	void resize(size_t newCapacity);

public:
	ComputerStore(const char* name);
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator= (const ComputerStore& other);
	~ComputerStore();

	void setName(const char* name);
	const char* getName() const;

	void addComputer(const Computer& other);
	void print() const;
	void buyComputer(const char* brand, double money);
	void printAvailableComputers(Criteria criteria) const;
};

class ConsultantUtils
{
public:
	static bool isGoodForGaming(const Computer& obj);
	static bool isGoodForTravel(const Computer& obj);
};

