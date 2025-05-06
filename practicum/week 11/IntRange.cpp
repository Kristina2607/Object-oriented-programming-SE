#include "IntRange.h"

IntRange::IntRange(int min, int max): min(min), max(max){}

bool IntRange::member(int x) const
{
	return x >= min || x <= max;
}

int IntRange::get(int index) const
{
	if (index >= getSize() ||index<0)
	{
		throw std::out_of_range("Invalid argument");
	}
	return min + index;
}

size_t IntRange::getSize() const
{
	return max - min + 1;
}
