#include "Accomodation.h"
#include<cstring>
#include <stdexcept>;

#pragma warning(disable:4996)

size_t Accomodation::counter = 1;

void Accomodation::copyFrom(const Accomodation& other)
{
	size_t strLen = strlen(other.name);
	name = new char[strLen+1];
	strcpy(name, other.name);
	id = other.id;
	type = other.type;
	price = other.price;
	isBooked = other.isBooked;
	daysToStay = other.daysToStay;
}

void Accomodation::free()
{
	delete[] name;
}

Accomodation::Accomodation() :name(nullptr), price(0), isBooked(0), daysToStay(0), id(0) {}

Accomodation::Accomodation(const Accomodation& other)
{
	copyFrom(other);
}

Accomodation::Accomodation(const char* name, Type type, Point location, double price, size_t daysToStay)
{
	setName(name);
	this->type = type;
	setLocation(location);
	setPrice(price);
	setDaysToStay(daysToStay);
}

Accomodation& Accomodation::operator=(const Accomodation& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Accomodation::~Accomodation()
{
	free();
}

void Accomodation::setDaysToStay(size_t daysToStay)
{
	this->daysToStay = daysToStay;
}

void Accomodation::setIsBooked(bool isBooked)
{
	this->isBooked = isBooked;
}

void Accomodation::setPrice(double price)
{
	this->price = price;
}

void Accomodation::setLocation(Point location)
{
	this->location.x = location.x;
	this->location.y = location.y;
}

void Accomodation::setName(const char* name)
{
	if (!name)
	{
		throw std::invalid_argument("Invalid name");
	}
	delete[] this->name;
	size_t strLen = strlen(name);
	this->name = new char[strLen + 1];
	strcpy(this->name, name);
}

void Accomodation::setType(Type type)
{
	this->type = type;
}

const char* Accomodation::getName() const
{
	return this->name;
}

Type Accomodation::getType() const
{
	return this->type;
}

double Accomodation::getPrice() const
{
	return this->price;
}

size_t Accomodation::getId() const
{
	return this->id;
}

bool Accomodation::getIsBooked() const
{
	return this->isBooked;
}

const Point& Accomodation::getLocation() const
{
	return location;
}

void Accomodation::reserve(size_t daysToStay)
{
	isBooked = 1;
	setDaysToStay(daysToStay);
}

void Accomodation::removeReservation()
{
	isBooked = 0;
	daysToStay = 0;
}

double Accomodation::sumForStay()
{
	double result = daysToStay * price;
	if (isBooked==0)
	{
		return 0.0;
	}
	return result;
}

void AirBnb::resize(size_t newCapacity)
{
	this->capacity = newCapacity;
	Accomodation* temp = new Accomodation[newCapacity];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = accomodations[i];
	}
	delete [] accomodations;
	accomodations = temp;
}

void AirBnb::copyFrom(const AirBnb& other)
{
	capacity=other.capacity;
	size = other.size;
	accomodations = new Accomodation[capacity];
	for(size_t i=0;i<size;i++)
	{
		accomodations[i] = other.accomodations[i];
	}
	accomodations = other.accomodations;
}

void AirBnb::free()
{
	delete[] accomodations;
}

AirBnb::AirBnb()
{
	capacity = initialCapacity;
	size = 0;
	accomodations = new Accomodation[capacity];
}

AirBnb::AirBnb(const AirBnb& other)
{
	copyFrom(other);
}

AirBnb::AirBnb(const Accomodation* accomodations, size_t size, size_t capacity)
{
	if (size >= capacity)
	{
		resize(size);
	}
	this->capacity = capacity;
	this->size = size;

	this->accomodations = new Accomodation[capacity];
	for (size_t i = 0; i < size; i++)
	{
		this->accomodations[i] = accomodations[i];
	}
}

AirBnb& AirBnb::operator=(const AirBnb& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

AirBnb::~AirBnb()
{
	free();
}

void AirBnb::addAccomodation(const Accomodation& newAcc)
{
		if (size == capacity)
		{
			resize(size+1);
		}
		accomodations[size + 1] = newAcc;
}

void AirBnb::reserve(size_t id, size_t daysToStay)
{
	for (int i = 0; i < size; i++)
	{
		if (accomodations[i].getId() == id)
		{
			if (accomodations[i].getIsBooked() == 1)
			{
				throw std::logic_error("Is already reserved");
			}
			else
			{
				accomodations[i].reserve(daysToStay);
			}
		}
		else
		{
			throw std::invalid_argument("ID is incorrect");
		}
	}
}

void AirBnb::cancelReservation(size_t id)
{
	for (int i = 0; i < size; i++)
	{
		if (accomodations[i].getId() == id)
		{
			accomodations[i].removeReservation();
		}
		else
		{
			throw std::invalid_argument("ID is incorrect");
		}
	}
}

double AirBnb::getProfit()
{
	double totalSum=0;
	for (int i = 0; i < size; i++)
	{
		if (accomodations[i].getIsBooked() == 1)
		{
			totalSum += accomodations[i].sumForStay();
		}
	}
	return totalSum;
}

const Point& AirBnb::getClosestLoc(const Point& location) const
{
	int closestIndex = 0;
	int minDistance = getDistance(accomodations[closestIndex].getLocation(), location);
	for (int i = 0; i< size; i++)
	{
		int distance = getDistance(accomodations[i].getLocation(), location);
		if (distance < minDistance)
		{
			minDistance = distance;
			closestIndex=i;
		}
	}
	return accomodations[closestIndex].getLocation();
}

void AirBnb::removeAcc(size_t id)
{
	for (int i = 0; i < size; i++)
	{
		if (accomodations[i].getId() == id)
		{
			std::swap(accomodations[i], accomodations[size - 1]);
		}
		else
		{
			throw std::invalid_argument("ID is incorrect");
		}
	}
}

static int getDistance(const Point& p1, const Point& p2) 
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
