#include "IntSet.h"

bool IntSet::isSubsetOf(const IntSet& set) const
{
	for (size_t i = 0; i < getSize(); i++)
	{
		if (!set.member(get(i)))
		{
			return false;
		}
	}
	return true;
}

bool IntSet::intersects(const IntSet& set) const
{
	for (size_t i = 0; i < getSize(); i++)
	{
		if (set.member(get(i)))
		{
			return true;
		}
	}
	return false;
}
