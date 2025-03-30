#include "Animal.h"
#include <cstring>
#include <fstream>
#include <iostream>
#pragma warning(disable: 4996)

void Animal::copyFrom(const Animal& other)
{
	size_t strLen = strlen(other.name);
	name = new char[strLen + 1];
	strcpy(name, other.name);
	type = other.type;
	age = other.age;
}

void Animal::free()
{
	delete[] name;
}

Animal::Animal(): name(nullptr), age(0) {};
Animal::Animal(const Animal& other)
{
	copyFrom(other);
}
Animal::Animal(const char* name, const unsigned age, const Type type)
{
	setName(name);
	setAge(age);
	setType(type);
}

void Animal::setName(const char* name)
{
	if (!name || name == this->name)
	{
		return;
	}
	size_t strLen = strlen(name);
	delete[] this->name;
	this->name = new char[strLen + 1] {};
	strcpy(this->name, name);
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void Animal::setAge(const unsigned age)
{
	this->age = age;
}

void Animal::setType(const Type type)
{
	this->type = type;
}

const char* Animal::getName() const
{
	return name;
}

const unsigned Animal::getAge() const
{
	return age;
}

const Type Animal::getType() const
{
	return type;
}

const char* Animal::getTypeToString(const Type type) const
{
	switch (type)
	{
	case Type::mammal:return "mammal";  break;
	case Type::bird:return "bird";  break;
	case Type::fish:return "fish";  break;
	case Type::reptile:return "reptile"; break;
	case Type::insect:return "insect"; break;
	case Type::amphibian:return "amphibian"; break;
	default: return "Invalid";
	}
}

Animal::~Animal()
{
	free();
}

void Zoo::copyFrom(const Zoo& other)
{
	size_t strLen = strlen(other.name);
	name = new char[strLen + 1];
	strcpy(name, other.name);
	animals = new Animal[other.currSize];
	currSize = other.currSize;
	for (int i = 0; i < other.currSize; i++)
	{
		animals[i] = other.animals[i];
	}
	maxSize = other.maxSize;
}

Zoo& Zoo::operator=(const Zoo& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void Zoo::free()
{
	delete[] name;
	delete[] animals;
	name = nullptr;
	animals = nullptr;
	currSize = 0;
}

Zoo::Zoo() :name(nullptr), animals(nullptr), currSize(0), maxSize(0) {};
Zoo::Zoo(const char* name, const size_t maxSize)
{
	setName(name);
	setMaxSize(maxSize);
	setAnimals(animals, maxSize, currSize);
}

Zoo::Zoo(const Zoo& other)
{
	copyFrom(other);
}

void Zoo::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}
	delete[] this->name;
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

void Zoo::setMaxSize(const size_t maxSize)
{
	this->maxSize = maxSize;
}

void Zoo::setAnimals(const Animal* animals, const size_t maxSize, size_t currSize)
{
	if (!animals || this->animals == animals)
	{
		return;
	}
	delete[] this->animals;
	this->animals = new Animal[maxSize];
	this->maxSize = maxSize;
	this->currSize = currSize;
	for(int i=0;i<currSize;i++)
	{
		this->animals[i] = animals[i];
	}
}

const char* Zoo::getName() const
{
	return name;
}

const size_t Zoo::getMaxSize() const
{
	return maxSize;
}

const Animal* Zoo::getAnimals() const
{
	return animals;
}

void Zoo::addAnimal(const Animal& other)
{
	if (currSize < maxSize)
	{
		animals[currSize++] = other;
	}
	return;
}

void Zoo::removeAnimal(const char* name)
{
	if (!name)
	{
		return;
	}
	for (size_t i = 0; i < currSize; i++)
	{
		if (strcmp(animals[i].getName(), name)==0)
		{
			for (size_t j = i; j < currSize-1; j++)
			{
				animals[j] = animals[j + 1];
			}
			currSize--;
		}
		return;
	}
}

unsigned Zoo::counterOfAnimalType (const Type type) const
{
	unsigned counter = 0;
	for (size_t i = 0; i < currSize; i++)
	{
		if (animals[i].getType() == type)
		{
			counter++;
		}
	}
	return counter;
}

void Zoo::print() const
{
	for (size_t i = 0; i < currSize; i++)
	{
		std::cout << animals[i].getName() << " " << animals[i].getAge()<< " " << animals[i].getTypeToString(animals[i].getType());
	}
}

void Zoo::saveToCSV(const char* filename) const
{
	if (!filename)
	{
		return;
	}
	std::ofstream ofs(filename);
	if(ofs.is_open())
	{
		return;
	}
	for (size_t i = 0; i < currSize; i++)
	{
		ofs << animals[i].getName() << ","
			<< animals[i].getAge() << ","
			<< animals[i].getTypeToString(animals[i].getType()) << '\n';
	}
	ofs.close();
}

Zoo::~Zoo()
{
	free();
}
