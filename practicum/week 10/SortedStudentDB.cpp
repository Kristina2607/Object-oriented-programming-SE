#include "SortedStudentDB.h"

void FilteredStudentDB::filter(bool(*g)(const Student& st))
{
	size_t writeIndex = 0;
	for (size_t i = 0; i < getSize(); i++)
	{
		if (g(getStudent(i)))
		{
			if (writeIndex != i)
			{
				setStudents(writeIndex,getStudent(i));
			}
			writeIndex++;
		}
	}
	setSize(writeIndex);
}

void FilteredStudentDB::limit(size_t N)
{
	if (N > getSize())
	{
		throw std::invalid_argument("Invalid argument");
	}
	resize(N);
}

void SortedStudentDB::sortBy(bool (*f) (const Student& lhs, const Student& rhs))
{
	for (int i = 0; i < getSize(); i++)
	{
		int minIndex = i;
		for (int j = i+1; j < getSize() - i; j++)
		{
			if (f(getStudent(j), getStudent(minIndex)))
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			std::swap(getStudent(i), getStudent(minIndex));
		}
	}
}

