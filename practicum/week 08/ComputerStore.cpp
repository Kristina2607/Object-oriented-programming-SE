#include "ComputerStore.h"
#include <iostream>
#pragma warning (disable:4996)

void ComputerStore::copyFrom(const ComputerStore& other)
{
	size_t strLen = strlen(other.name);
	name = new char[strLen + 1];
	strcpy(name, other.name);

	size = other.size;
	capacity = other.capacity;

	computers = new Computer[capacity];
	for (int i = 0; i < size; i++)
	{
		computers[i] = other.computers[i];
	}
}

void ComputerStore::free()
{
	delete[]computers;
	computers = nullptr;
	delete[]name;
	name = nullptr;
	size = 0;
}

void ComputerStore::resize(size_t newCapacity)
{
	this->capacity = newCapacity;
	Computer* newComputers = new Computer [newCapacity];
	for (int i = 0; i < size; i++)
	{
		newComputers[i] = computers[i];
	}
	delete[] computers;
	computers = newComputers;
}

ComputerStore::ComputerStore(const char* name)
{
	setName(name);
}

ComputerStore::ComputerStore(const ComputerStore& other)
{
	copyFrom(other);
}

ComputerStore& ComputerStore::operator=(const ComputerStore& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

ComputerStore::~ComputerStore()
{
	free();
}

void ComputerStore::setName(const char* name)
{
	if (!name ||this->name==name)
	{
		return;
	}
	delete[]this->name;
	size_t strLen = strlen(name);
	this->name = new char[strLen + 1];
	strcpy(this->name, name);
}

const char* ComputerStore::getName() const
{
	return name;
}

void ComputerStore::addComputer(const Computer& other)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(computers[i].getBrand(), other.getBrand()) == 0)
		{
			computers[i].setQuantity(computers[i].getQuantity()+1);
			return;
		}
	}
	if (size == capacity)
	{
		resize(size+INITIAL_CAPACITY);
	}
	computers[size++] = other;
}

void ComputerStore::print() const
{
	for (int i = 0; i < size; i++)
	{
		computers[i].printComputer();
	}
}

void ComputerStore::buyComputer(const char* brand, double money)
{
	for (int i = 0; i < size; i++)
	{
		if (computers[i].getBrand() == brand && computers[i].getQuantity()>0)
		{
			if (computers[i].getPrice() <= money)
			{
				computers[i].setQuantity(computers[i].getQuantity()-1);
			}
			else
			{
				throw std::logic_error("This brand of the computer is more expensive.");
			}
		}
	}
	throw std::logic_error("Is not available");
}

void ComputerStore::printAvailableComputers(Criteria criteria) const
{
	for (int i = 0; i < size; i++)
	{
		if (criteria == Criteria::NoCriteria && computers[i].getQuantity() > 0)
		{
			computers[i].printComputer();
		}
		if (criteria == Criteria::Travel && computers[i].getQuantity() > 0 && ConsultantUtils::isGoodForTravel(computers[i]))
		{
			computers[i].printComputer();
		}
		else if (criteria == Criteria::Gaming && ConsultantUtils::isGoodForGaming(computers[i]) && computers[i].getQuantity() > 0)
		{
			computers[i].printComputer();
		}
	}
}

bool ConsultantUtils::isGoodForGaming(const Computer& obj)
{
	if (strcmp(obj.getProcessor(), "i5") == 0 || strcmp(obj.getProcessor(), "i7") == 0)
	{
		if (obj.getVideo() == 3060 || obj.getVideo() == 3070 || obj.getVideo() == 3080 || obj.getVideo() == 3090)
		{
			if (obj.getHardDrive() >= 512)
			{
				return true;
			}
		}
	}
	return false;
}

bool ConsultantUtils::isGoodForTravel(const Computer& obj)
{
	if (obj.getWeight() <= 2.5)
	{
		if (obj.getBatteryLife() > 6)
		{
			return true;
		}
	}
	return false;
}
