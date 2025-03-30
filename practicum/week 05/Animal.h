#pragma once

enum class Type
{
	mammal,
	reptile,
	fish,
	bird,
	amphibian,
	ivertebrates,
	insect
};

class Animal
{
	char* name;
	Type type;
	unsigned age;
	void copyFrom(const Animal& other);
	void free();

public:
	Animal();
	Animal(const Animal& other);
	Animal(const char* name, const unsigned age, const Type type);
	Animal& operator=(const Animal& other);

	void setName(const char* name);
	void setAge(const unsigned age);
	void setType(const Type type);

	const char* getName() const;
	const unsigned getAge() const;
	const Type getType() const;
	const char* getTypeToString(Type type) const;

	~Animal();
};

class Zoo
{
	char* name;
	Animal* animals;
	size_t currSize;
	size_t maxSize;
	void copyFrom(const Zoo& other);
	void free();

public:
	Zoo();
	Zoo(const Zoo& other);
	Zoo(const char* name, const size_t maxSize);
	Zoo& operator=(const Zoo& other);

	void setName(const char* name);
	void setMaxSize(size_t maxSize);
	void setAnimals(const Animal* animal, const size_t maxSize, size_t currSize);

	const char* getName() const;
	const size_t  getMaxSize() const;
	const Animal* getAnimals() const;

	void addAnimal(const Animal& other);
	void removeAnimal(const char* name);
	unsigned counterOfAnimalType(const Type type) const;
	void print() const;
	void saveToCSV(const char* filename) const;

	~Zoo();
};

