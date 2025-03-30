#include "GradeReport.h"
#include <cstring>
#pragma warning (disable : 4996)

void GradeReport::copyFrom(const GradeReport& other)
{
	grades = new int[other.counter];
	counter = other.counter;
	for (int i = 0; i < other.counter; i++)
	{
		grades[i] = other.grades[i];
	}

	int strLen = strlen(other.nameOfReport);
	nameOfReport = new char[strLen + 1] {};
	strcpy(nameOfReport, other.nameOfReport);
}

void GradeReport::free()
{
	delete[] grades;
	grades = nullptr;
	delete[] nameOfReport;
	nameOfReport = nullptr;
	counter = 0;
}

GradeReport::GradeReport():counter(0),grades(nullptr),nameOfReport(nullptr){} //default constructor

GradeReport::GradeReport(const GradeReport& other)
{
	copyFrom(other);    //copy constructor
}

GradeReport::GradeReport(const char* nameOfReport, int counter, const int* grades)
{
	setGradeCount(counter);
	setGrades(grades, counter);
	setName(nameOfReport);
}

GradeReport& GradeReport::operator=(const GradeReport& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void GradeReport::setGradeCount(int counter)
{
	this->counter = counter;
}

void GradeReport::setGrades(const int* grades, int counter)
{
	if (!grades || this->grades == grades)
	{
		return;
	}
	delete[] this->grades;
	setGradeCount(counter);
	this->grades = new int[counter];

	for (int i = 0; i < counter; i++)
	{
		this->grades[i] = grades[i];
	}
}

void GradeReport::setName(const char* newName)
{
	if (!newName || nameOfReport==newName)
	{
		return;
	}
	delete[] nameOfReport;
	nameOfReport = new char[strlen(newName) + 1];
	strcpy(nameOfReport, newName);
}

const char* GradeReport::getName() const
{
	return nameOfReport;
}

 int GradeReport::getGradesCount() const
{
	return counter;
}

const int GradeReport::averageGrade() const
{
	int counter = getGradesCount();
	int sumOfGrades = 0;
	for (int i = 0; i < counter; i++)
	{
		sumOfGrades += grades[i];
	}
	return sumOfGrades / counter;
}

GradeReport::~GradeReport()
{
	free();   //destructor
}

