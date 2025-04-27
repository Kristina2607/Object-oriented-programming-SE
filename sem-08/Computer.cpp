#include "Computer.h"
#include <iostream>
#pragma warning(disable:4996)

int Computer::nextSerialNumber = 1;

void Computer::copyFrom(const Computer& other)
{
	serialNumber =other.serialNumber;
	video = other.video;
	hardDrive = other.hardDrive;
	weight = other.weight;
	batteryLife = other.batteryLife;
	price = other.price;
	quantity = other.quantity;

	size_t brandLen = strlen(other.brand);
	brand = new char[brandLen + 1];
	strcpy(brand, other.brand);

	size_t processorLen = strlen(other.processor);
	processor = new char[processorLen + 1];
	strcpy(processor, other.processor);
}

void Computer::free()
{
	delete[]brand;
	brand = nullptr;
	delete[]processor;
	processor = nullptr;
	serialNumber = 0;
	quantity = 0;
}

Computer::Computer() :brand(nullptr), processor(nullptr),  serialNumber(nextSerialNumber++),
video(0), hardDrive(0), weight(0), batteryLife(0), price(0), quantity(0){}

Computer::Computer(const char* brand, const char* processor, int video, int hardDrive, double weight, double batteryLife, double price): serialNumber(nextSerialNumber++)
{
	if (!brand)
	{
		throw std::invalid_argument("Invalid argument");
	}
	delete[] this->brand;
	size_t strLen = strlen(brand);
	this->brand = new char[strLen + 1];
	strcpy(this->brand, brand);

	if (!processor)
	{
		throw std::invalid_argument("Invalid argument");
	}
	delete[] this->processor;
	size_t strLen = strlen(processor);
	this->processor = new char[strLen + 1];
	strcpy(this->processor, processor);

	this->video = video;
	this->hardDrive = hardDrive;
	this->weight = weight;
	this->batteryLife = batteryLife;
	this->price = price;
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Computer::~Computer()
{
	free();
}

void Computer::setQuantity(int newQuantity)
{
	if (newQuantity >= 0)
	{ 
		this->quantity = newQuantity;
	}
	else 
	{
		throw std::invalid_argument("Quantity cannot be negative");
	}
}

void Computer::printComputer() const
{
	std::cout <<getSerialNumber() << std::endl << getBrand() << std::endl <<
		getProcessor() << std::endl << getQuantity()<< std::endl<< getHardDrive() << std::endl <<
		getBatteryLife() << std::endl << getVideo() << std::endl <<
		getPrice() << std::endl << getWeight() << std::endl;
}

const char* Computer::getBrand() const
{
	return brand;
}

const char* Computer::getProcessor() const
{
	return processor;
}

int Computer::getSerialNumber() const
{
	return serialNumber;
}

int Computer::getVideo() const
{
	return video;
}

int Computer::getHardDrive() const
{
	return hardDrive;
}

double Computer::getWeight() const
{
	return weight;
}

double Computer::getBatteryLife() const
{
	return batteryLife;
}

double Computer::getPrice() const
{
	return price;
}

int Computer::getQuantity() const
{
	return quantity;
}

