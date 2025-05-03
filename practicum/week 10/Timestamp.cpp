#include "Timestamp.h"
#include <iostream>
#include <utility>

Timestamp::Timestamp() :time(0) {}

Timestamp::Timestamp(unsigned time)
{
	setTime(time);
}

void Timestamp::setTime(unsigned time)
{
	this->time = time;
}

int Timestamp::getTime() const
{
	return time;
}

Timestamp& Timestamp::operator+=(int newTime)
{
	time += newTime;
}

std::istream& operator>>(std::istream& is, const Timestamp& time)
{
	return is >> time.getTime();
}

std::ostream& operator<<(std::ostream& os, const Timestamp& time)
{
	return os << time.getTime();
}






void TimestampWithDescription::copyFrom(const TimestampWithDescription& other)
{
	size_t strLen = strlen(description);
	this->description = new char[strLen + 1];
	strcpy(this->description, description);
}

void TimestampWithDescription::free()
{
	delete[]description;
	description = nullptr;
}

void TimestampWithDescription::moveFrom(TimestampWithDescription&& other)
{
	description = other.description;
	other.description = nullptr;
}

TimestampWithDescription::TimestampWithDescription(unsigned time, const char* description): Timestamp(time)
{
	setDescription(description);
}

const char* TimestampWithDescription::getDescription() const
{
	return description;
}

void TimestampWithDescription::setDescription(const char* description)
{
	if (!description || this->description==description)
	{
		throw std::invalid_argument("Invalid argument");
	}
	delete[] this->description;
	size_t strLen = strlen(description);
	this->description = new char[strLen + 1];
	strcpy(this->description,description);
}

TimestampWithDescription& TimestampWithDescription::operator=(TimestampWithDescription&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

TimestampWithDescription::TimestampWithDescription(const TimestampWithDescription& other)
{
	copyFrom(other);
}

TimestampWithDescription& TimestampWithDescription::operator=(const TimestampWithDescription& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

TimestampWithDescription::TimestampWithDescription(TimestampWithDescription&& other)
{
	moveFrom(std::move(other));
}

TimestampWithDescription::~TimestampWithDescription()
{
	free();
}

std::istream& operator>>(std::istream& is, const TimestampWithDescription& t) 
{
	//??
}

std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& t)
{
	//??
}
