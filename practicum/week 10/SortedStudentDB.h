#pragma once
#include "Student.h";

class SortedStudentDB: public StudentDB
{
	void sortBy(bool (*f) (const Student& lhs, const Student& rhs));
};

class FilteredStudentDB : public StudentDB
{
	void filter(bool (*g) (const Student& st));
	void limit(size_t N);
};

